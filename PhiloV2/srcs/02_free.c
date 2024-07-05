/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:18:37 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/05 16:12:43 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	free_philo(t_philo *philo, int nb_philo)
{
	int i;
	int *destroyed;

	destroyed = calloc(nb_philo, sizeof(int));
	if (!destroyed)
		return;
	i = 0;
	if (philo)
	{
		while (i < nb_philo)
		{
			if (philo[i].left_fork && !destroyed[i])
			{
				pthread_mutex_destroy(philo[i].left_fork);
				destroyed[i] = 1;
			}
			if (philo[i].right_fork && !destroyed[(i + 1) % nb_philo])
			{
				pthread_mutex_destroy(philo[i].right_fork);
				destroyed[(i + 1) % nb_philo] = 1;
			}
			i++;
		}
		if (nb_philo > 0 && philo[0].left_fork)
			free(philo[0].left_fork);
		free(philo);
	}
	free(destroyed);
}



void	cleanup(t_data *data, t_philo *philo)
{
	if (philo)
		free_philo(philo, data->nb_philo);
	if (data)
	{
		pthread_mutex_destroy(&data->printex);
		pthread_mutex_destroy(&data->someone_died_mutex);
		free(data);
	}
}
