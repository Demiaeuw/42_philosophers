/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:14:23 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 04:30:13 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_monitoring(t_monitoring *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->num_philosophers)
	{
		pthread_mutex_destroy(&monitor->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&monitor->print_mutex);
	pthread_mutex_destroy(&monitor->death_mutex);
	pthread_mutex_destroy(&monitor->meals_mutex);
	pthread_mutex_destroy(&monitor->stop_mutex);
	free(monitor->philosophers);
	free(monitor->forks);
}

void	free_philosophers(t_monitoring *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->num_philosophers)
	{
		pthread_join(monitor->philosophers[i].thread, NULL);
		i++;
	}
	pthread_join(monitor->monitor_thread, NULL);
}

void	shutdown_sim(t_monitoring *monitor)
{
	if (monitor != NULL)
	{
		free_philosophers(monitor);
		free_monitoring(monitor);
	}
}


