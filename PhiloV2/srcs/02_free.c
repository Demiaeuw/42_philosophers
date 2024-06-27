/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:18:37 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/27 15:28:19 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	free_philo(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	if (philo)
	{
		while (i < nb_philo)
		{
			if (philo[i].right_fork)
				pthread_mutex_destroy(philo[i].right_fork);
			if (philo[i].left_fork)
				pthread_mutex_destroy(philo[i].left_fork);
			if (philo[i].print)
				pthread_mutex_destroy(philo[i].print);
			i++;
		}
		if (nb_philo > 0 && philo[0].left_fork)
			free(philo[0].left_fork);
		free(philo);
	}
}

void	cleanup(t_data *data, t_philo *philo)
{
	if (philo)
		free_philo(philo, data->nb_philo);
	if (data)
	{
		pthread_mutex_destroy(&data->printex);
		free(data);
	}
}
