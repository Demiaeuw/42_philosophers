/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:27:17 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 18:40:50 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_monitoring(t_monitoring *monitor, int ac, char **av)
{
	monitor->nb_philo = ft_atoi(av[1]);
	monitor->tt_death = ft_atoi(av[2]);
	monitor->tt_eat = ft_atoi(av[3]);
	monitor->tt_sleep = ft_atoi(av[4]);
	monitor->nb_meal = -1;
	monitor->check_alleat = -1;
	if (ac == 6)
	{
		monitor->nb_meal = ft_atoi(av[5]);
		monitor->check_alleat = 0;
	}
	monitor->check_death = 0;
	monitor->time_start = get_timestamp();
	monitor->time_present = get_timestamp();
	if (init_mutexmonitoring(monitor) != 0)
		return (1);
	return (0);
}

int	init_mutexmonitoring(t_monitoring *monitor)
{
	int	i;

	i = 0;
	monitor->mutex_thread = malloc(sizeof(pthread_mutex_t) * monitor->nb_philo);
	if (!monitor->mutex_thread)
	{
		printf("\n\033[1;31mError\033 allocating memory for mutex_thread\n");
		return (1);
	}
	while (i < monitor->nb_philo)
	{
		if (pthread_mutex_init(&monitor->mutex_thread[i], NULL) != 0)
		{
			printf("\n\033[1;31mError\033 initializing mutex_thread\n");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&monitor->mutex_print, NULL) != 0)
	{
		printf("\n\033[1;31mError\033 initializing mutex_print\n");
		return (1);		
	}
	if (pthread_mutex_init(&monitor->mutex_death, NULL) != 0)
	{
		printf("\n\033[1;31mError\033 initializing mutex_death\n");
		return (1);
	}
	return (0);
}

int	init_philosophers(t_monitoring *monitor)
{
	int	i;

	monitor->philo = malloc(sizeof(t_philo) * monitor->nb_philo);
	if (!monitor->philo)
		return (1);
	i = 0;
	while (i < monitor->nb_philo)
	{
		monitor->philo[i].id = i + 1;
		monitor->philo[i].meal_eaten = 0;
		monitor->philo[i].time_lastmeal = monitor->time_start;
		monitor->philo[i].fork_left = &monitor->mutex_thread[i];
		monitor->philo[i].fork_right = &monitor->mutex_thread[(i + 1) % monitor->nb_philo];
		monitor->philo[i].monitoring = monitor;
		if (pthread_create(&monitor->philo[i].thread_philo, NULL, &philo_routine, &monitor->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int start_simulation(t_monitoring *monitor)
{
	int	i;

	i = 0;
	if (init_philosophers(monitor) != 0)
		return (1);
	
	if (pthread_create(&monitor->thread_monitor, NULL, &monitor_routine, monitor) != 0)
		return (1);
	while (i < monitor->nb_philo)
	{
		pthread_join(monitor->philo[i].thread_philo, NULL);
		i++;
	}
	pthread_join(monitor->thread_monitor, NULL);
	return (0);
}

