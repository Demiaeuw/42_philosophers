/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:36 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 16:09:04 by acabarba         ###   ########.fr       */
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
		pthread_mutex_lock(&data->print_mutex);
		printf("Philosophe n°%d think\n", philo->id_philo);
		pthread_mutex_unlock(&data->print_mutex);

		// Philosophe prend les fourchettes
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&data->print_mutex);
		printf("Philosophe n°%d are eating with 2 forks\n", philo->id_philo);
		pthread_mutex_unlock(&data->print_mutex);

		// Philosophe mange
		usleep(data->tt_e * 1000);

		// Philosophe repose les fourchettes
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);

		// Philosophe dort
		pthread_mutex_lock(&data->print_mutex);
		printf("Philosophe n°%d are sleeping\n", philo->id_philo);
		pthread_mutex_unlock(&data->print_mutex);
		usleep(data->tt_s * 1000);
	}
	return (NULL);
}
