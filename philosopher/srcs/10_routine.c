/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:56:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/11 17:33:29 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		pthread_mutex_lock(&philo->monitoring->mutex_death);
		if (philo->monitoring->check_death)
		{
			pthread_mutex_unlock(&philo->monitoring->mutex_death);
			break ;
		}
		pthread_mutex_unlock(&philo->monitoring->mutex_death);
		take_forks(philo);
		eat_philo(philo);
		drop_forks(philo);
		sleep_philo(philo);
		think_philo(philo);
	}
	return (NULL);
}


void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_status(philo, "has taken left fork");
	pthread_mutex_lock(philo->fork_right);
	print_status(philo, "has taken right fork");
}

void drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

void eat_philo(t_philo *philo)
{
    philo->time_lastmeal = get_timestamp();
    print_status(philo, "is eating");
    usleep(philo->monitoring->tt_eat * 1000);
    philo->meal_eaten++;
    if (philo->monitoring->nb_meal != -1 && philo->meal_eaten >= philo->monitoring->nb_meal)
    {
        pthread_mutex_lock(&philo->monitoring->mutex_death);
        philo->monitoring->check_alleat++;
        if (philo->monitoring->check_alleat == philo->monitoring->nb_philo)
            philo->monitoring->check_death = 1;
        pthread_mutex_unlock(&philo->monitoring->mutex_death);
    }
}


