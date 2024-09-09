/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:27:17 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 16:08:39 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_monitoring(t_monitoring *monitor, int ac, char **av)
{
	monitor->nb_philo = ft_atoi(av[1]);
	monitor->tt_death = ft_atoi(av[2]);
	monitor->tt_eat = ft_atoi(av[3]);
	monitor->tt_think = ft_atoi(av[4]);
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
	init_mutexmonitoring(monitor);
	
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