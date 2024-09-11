/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:26:03 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/11 02:26:15 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo		*philosopher;
	t_data		*data;
	int			i;

	i = 0;
	philosopher = (t_philo *)philo;
	data = philosopher->philo_data;
	if (philosopher->philo_id % 2 == 0)
		usleep(1500);
	pthread_mutex_lock(&(data->mutex_eat));
	while (!(data->is_dead) && data->check_eat != 1)
	{
		pthread_mutex_unlock(&(data->mutex_eat));
		eat_philo(philosopher);
		pthread_mutex_lock(&(data->mutex_eat));
		print_status(data, philosopher->philo_id, "is sleeping");
		pthread_mutex_unlock(&(data->mutex_eat));
		sleep_time(data->tt_sleep, data);
		pthread_mutex_lock(&(data->mutex_eat));
		print_status(data, philosopher->philo_id, "is thinking");
		i++;
	}
	pthread_mutex_unlock(&(data->mutex_eat));
	return (NULL);
}

void	eat_philo(t_philo *philo)
{
	t_data	*data;

	data = philo->philo_data;
	pthread_mutex_lock(&(data->forks[philo->fork.left]));
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "has taken a fork");
	pthread_mutex_unlock(&(data->mutex_eat));
	pthread_mutex_lock(&(data->forks[philo->fork.right]));
	pthread_mutex_lock(&(data->mutex_eat));
	print_status(data, philo->philo_id, "has taken a fork");
	print_status(data, philo->philo_id, "is eating");
	philo->time_philolastmeal = get_time();
	pthread_mutex_unlock(&(data->mutex_eat));
	sleep_time(data->tt_eat, data);
	pthread_mutex_lock(&(data->mutex_eat));
	(philo->philo_nbeat)++;
	pthread_mutex_unlock(&(data->mutex_eat));
	pthread_mutex_unlock(&(data->forks[philo->fork.right]));
	pthread_mutex_unlock(&(data->forks[philo->fork.left]));
}

void	sleep_time(long long time, t_data *data)
{
	long long	i;

	i = get_time();
	pthread_mutex_lock(&(data->mutex_eat));
	while ((!((get_time() - i) >= time)) && !(data->is_dead))
	{
		pthread_mutex_unlock(&(data->mutex_eat));
		usleep(50);
		pthread_mutex_lock(&(data->mutex_eat));
	}
	pthread_mutex_unlock(&(data->mutex_eat));
}
