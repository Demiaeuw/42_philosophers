/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_printex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:48:16 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 19:30:39 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, int index)
{
	long	timestamp;

	timestamp = get_duration(philo->data);
	if (index == 6)
		printf("%ld\033[1;31m %d died\033[0m\n", timestamp, philo->id);
	if (check_death(philo))
		return ;
	pthread_mutex_lock(philo->data->printex);
	if (index == 1)
		printf("%ld %d has taken a fork\n", timestamp, philo->id);
	else if (index == 2)
		printf("%ld %d is eating\n", timestamp, philo->id);
	else if (index == 3)
		printf("%ld %d is sleeping\n", timestamp, philo->id);
	else if (index == 4)
		printf("%ld %d is thinking\n", timestamp, philo->id);
	else if (index == 5)
		printf("%ld %d is full\n", timestamp, philo->id);
	pthread_mutex_unlock(philo->data->printex);
}

int	get_duration(t_data *data)
{
	return (get_timestamp() - data->start_time);
}

long	get_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
