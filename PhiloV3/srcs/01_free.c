/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:38:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 18:48:25 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_data(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	if (data->diecheck_m)
	{
		pthread_mutex_destroy(data->diecheck_m);
		free(data->diecheck_m);
	}
	if (data->printex)
	{
		pthread_mutex_destroy(data->printex);
		free(data->printex);
	}
}

void	free_philos(t_philo *philos)
{
	if (philos)
		free(philos);
}

void	cleanup_simulation(t_philo *philos, t_data *data,
			pthread_mutex_t *forks)
{
	free_philos(philos);
	free_data(data, forks);
}
