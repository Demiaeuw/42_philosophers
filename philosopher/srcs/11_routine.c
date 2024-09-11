/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:18:47 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/11 01:34:23 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void sleep_philo(t_philo *philo)
{
    print_status(philo, "is sleeping");
    usleep(philo->monitoring->tt_sleep * 1000);
}

void think_philo(t_philo *philo)
{
    print_status(philo, "is thinking");
}

void	*monitor_routine(void *arg)
{
	t_monitoring	*monitor = (t_monitoring *)arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < monitor->nb_philo)
		{
			pthread_mutex_lock(&monitor->mutex_death);
			if (get_timestamp() - monitor->philo[i].time_lastmeal > monitor->tt_death)
			{
				print_status(&monitor->philo[i], "died");
				monitor->check_death = 1;
				pthread_mutex_unlock(&monitor->mutex_death);
				return (NULL);
			}
			pthread_mutex_unlock(&monitor->mutex_death);
			pthread_mutex_lock(&monitor->mutex_death);
			if (monitor->check_alleat == monitor->nb_philo)
			{
				monitor->check_death = 1;
				pthread_mutex_unlock(&monitor->mutex_death);
				return (NULL);
			}
			pthread_mutex_unlock(&monitor->mutex_death);
			i++;
		}
		usleep(10);
	}
	return (NULL);
}
