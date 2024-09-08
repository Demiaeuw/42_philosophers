/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_thinkanddeath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:33:09 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 20:13:10 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	think(t_philo *philo)
{
	print_status(philo, 4);	
}

int	death(t_philo *philo)
{
	struct timeval	now;
	long			time_since_last_meal;

	gettimeofday(&now, NULL);
	time_since_last_meal = (now.tv_sec - philo->mealtimer.tv_sec) * 1000 +
						   (now.tv_usec - philo->mealtimer.tv_usec) / 1000;
	if (time_since_last_meal > philo->data->time_to_die)
	{
		pthread_mutex_lock(philo->data->diecheck_m);
		philo->data->diecheck = 1;
		pthread_mutex_unlock(philo->data->diecheck_m);
		print_status(philo, 6);
		return (1);
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(philo->data->diecheck_m);
	is_dead = philo->data->diecheck;
	pthread_mutex_unlock(philo->data->diecheck_m);
	if (is_dead)
		return (1);
	return (0);
}

