/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_printex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:14:58 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 12:08:56 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_status(t_philo *philo, int status)
{
	long	timestamp;

	// Calculer le temps écoulé depuis le début de la simulation
	timestamp = get_duration(philo->monitor);
	pthread_mutex_lock(&philo->monitor->print_mutex);

	if (status == 1)
		printf("%ld %d has taken a fork\n", timestamp, philo->id);
	else if (status == 2)
		printf("%ld %d is eating\n", timestamp, philo->id);
	else if (status == 3)
		printf("%ld %d is sleeping\n", timestamp, philo->id);
	else if (status == 4)
		printf("%ld %d is thinking\n", timestamp, philo->id);
	else if (status == 5)
		printf("%ld %d is full\n", timestamp, philo->id);
	else if (status == 6)
	{
		printf("%ld %d died\n", timestamp, philo->id);
		pthread_mutex_unlock(&philo->monitor->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->monitor->print_mutex);
}

int	print_error(char *str)
{
	printf("%s\n", str);
	return (1);
}