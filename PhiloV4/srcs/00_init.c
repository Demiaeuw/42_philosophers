/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:13:44 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 04:33:02 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(pthread_mutex_t *forks, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_monitoring(t_monitoring *monitor, int argc, char **argv)
{
	monitor->num_philosophers = ft_atoi(argv[1]);
	monitor->time_to_die = ft_atoi(argv[2]);
	monitor->time_to_eat = ft_atoi(argv[3]);
	monitor->time_to_sleep = ft_atoi(argv[4]);
	monitor->num_meals_required = -1;
	if (argc == 6)
		monitor->num_meals_required = ft_atoi(argv[5]);
	monitor->simulation_stop = 0;
	monitor->simulation_start = get_current_time(monitor->simulation_start);
	monitor->philosophers = malloc(sizeof(t_philo) * monitor->num_philosophers);
	if (!monitor->philosophers)
		return (1);
	monitor->forks = malloc(sizeof(pthread_mutex_t) * monitor->num_philosophers);
	if (!monitor->forks)
		return (1);
	if (init_forks(monitor->forks, monitor->num_philosophers))
		return (1);
	pthread_mutex_init(&monitor->print_mutex, NULL);
	pthread_mutex_init(&monitor->death_mutex, NULL);
	pthread_mutex_init(&monitor->meals_mutex, NULL);
	pthread_mutex_init(&monitor->stop_mutex, NULL);
	return (0);
}

int	init_philosophers(t_monitoring *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->num_philosophers)
	{
		monitor->philosophers[i].id = i + 1;
		monitor->philosophers[i].meals_eaten = 0;
		monitor->philosophers[i].last_meal_time = monitor->simulation_start;
		monitor->philosophers[i].monitor = monitor;
		monitor->philosophers[i].left_fork = &monitor->forks[i];
		if (i == monitor->num_philosophers - 1)
			monitor->philosophers[i].right_fork = &monitor->forks[0];
		else
			monitor->philosophers[i].right_fork = &monitor->forks[i + 1];

		if (pthread_create(&monitor->philosophers[i].thread, NULL, philosopher_routine, &monitor->philosophers[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_create(&(monitor->monitor_thread), NULL, monitoring_routine, monitor) != 0)
		return (1);

	return (0);
}
