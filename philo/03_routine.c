/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:26:03 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/10 23:19:09 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo		*ph;
	t_data		*data;
	int			i;

	i = 0;
	ph = (t_philo *)philo;
	data = ph->data_ph;
	if (ph->id_ph % 2 == 0)
		usleep(1500);
	pthread_mutex_lock(&(data->eat_m));
	while (!(data->is_dead) && data->have_ate != 1)
	{
		pthread_mutex_unlock(&(data->eat_m));
		eat_philo(ph);
		pthread_mutex_lock(&(data->eat_m));
		print_action(data, ph->id_ph, "is sleeping");
		pthread_mutex_unlock(&(data->eat_m));
		sleep_time(data->t_sleep, data);
		pthread_mutex_lock(&(data->eat_m));
		print_action(data, ph->id_ph, "is thinking");
		i++;
	}
	pthread_mutex_unlock(&(data->eat_m));
	return (NULL);
}

void	eat_philo(t_philo *philo)
{
	t_data	*data;

	data = philo->data_ph;
	pthread_mutex_lock(&(data->forks[philo->fork.l]));
	pthread_mutex_lock(&(data->eat_m));
	print_action(data, philo->id_ph, "has taken a fork");
	pthread_mutex_unlock(&(data->eat_m));
	pthread_mutex_lock(&(data->forks[philo->fork.r]));
	pthread_mutex_lock(&(data->eat_m));
	print_action(data, philo->id_ph, "has taken a fork");
	print_action(data, philo->id_ph, "is eating");
	philo->last_eat_ph = stock_time();
	pthread_mutex_unlock(&(data->eat_m));
	sleep_time(data->t_eat, data);
	pthread_mutex_lock(&(data->eat_m));
	(philo->n_eat_ph)++;
	pthread_mutex_unlock(&(data->eat_m));
	pthread_mutex_unlock(&(data->forks[philo->fork.r]));
	pthread_mutex_unlock(&(data->forks[philo->fork.l]));
}

void	sleep_time(long long time, t_data *data)
{
	long long	i;

	i = stock_time();
	pthread_mutex_lock(&(data->eat_m));
	while ((!((stock_time() - i) >= time)) && !(data->is_dead))
	{
		pthread_mutex_unlock(&(data->eat_m));
		usleep(50);
		pthread_mutex_lock(&(data->eat_m));
	}
	pthread_mutex_unlock(&(data->eat_m));
}