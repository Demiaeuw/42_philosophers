/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:36 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 19:42:17 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		// Philosophe pense
		print_lock(data, philo, "think");

		// Philosophe prend les fourchettes
		print_lock(data, philo, "eating");
		if (pthread_mutex_lock(philo->left_fork) == 0
			&& pthread_mutex_lock(philo->right_fork) == 0)
		{
			// Philosophe mange
			usleep(data->tt_e * 1000);
			print_lock(data, philo, "is full");
			// Philosophe repose les fourchettes
			if (pthread_mutex_unlock(philo->right_fork) == 0
				&& pthread_mutex_unlock(philo->left_fork) == 0)
			{
				// Philosophe dort
				print_lock(data, philo, "sleeping");
				usleep(data->tt_s * 1000);
			}
			else
			{
				print_lock(data, philo, "died");
				// data->died++;
				return (NULL);
			}
		}
		else
		{
			print_lock(data, philo, "died");
			// data->died++;
			return (NULL);
		}
	}
	return (NULL);
}

void	print_lock(t_data *data, t_philo *philo, char *action)
{
	pthread_mutex_lock(&data->print_mutex);
	printf("Philosophe n°%d %s\n", philo->id_philo, action);
	pthread_mutex_unlock(&data->print_mutex);
}

