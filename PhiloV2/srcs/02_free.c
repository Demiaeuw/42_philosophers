/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:18:37 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/21 09:13:01 by acabarba         ###   ########.fr       */
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
			// Libérez ici toute ressource allouée dans la structure t_philo si nécessaire
			if (philo[i].fork)
				pthread_mutex_destroy(philo[i].fork);
			if (philo[i].print)
				pthread_mutex_destroy(philo[i].print);
			i++;
		}
		free(philo);
	}
}

// void	free_data(t_data *data)
// {
// 	if (data)
// 	{
// 		// Libérez ici toute ressource allouée dans la structure t_data si nécessaire
// 		// Actuellement, il n'y a pas d'allocation dynamique dans t_data
// 	}
// }

void	cleanup(t_data *data, t_philo *philo)
{
	if (philo)
		free_philo(philo, data->nb_philo);
	// if (data)
	// 	free_data(data);
}