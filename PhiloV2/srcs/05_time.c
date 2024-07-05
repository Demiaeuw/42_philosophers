/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:50:52 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/04 07:15:35 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

long	get_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	get_duration(t_data *data)
{
	return (get_timestamp() - data->start_time);
}

void	gestion_one_forks(t_philo *philo)
{
	printmessage(philo, "thinking");
	pthread_mutex_lock(philo->right_fork);
	usleep(philo->data->time_to_die * 1000);
	pthread_mutex_unlock(philo->right_fork);
	printmessage(philo, "dead");
}

int	check_meals(t_philo *philo)
{
	if (philo->data->nb_meal_needed > 0
		&& philo->nb_meal == philo->data->nb_meal_needed)
	{
		printmessage(philo, "full");
		return (1);
	}
	return (0);
}
