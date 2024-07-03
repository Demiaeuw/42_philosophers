/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:50:52 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/03 18:14:59 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

long	get_timestamp()
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int		get_duration(t_data *data)
{
	return (get_timestamp() - data->start_time);
}

void	gestion_one_forks(t_philo *philo)
{
	printmessage(philo, "thinking");
	pthread_mutex_lock(philo->right_fork);
	usleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->right_fork);
	printmessage(philo, "dead");
}
