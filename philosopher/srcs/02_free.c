/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:29:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 18:38:18 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clean_monitoring(t_monitoring *monitor)
{
	int	i;

	i = 0;
	// Destruction des mutex pour chaque philosophe
	while (i < monitor->nb_philo)
	{
		pthread_mutex_destroy(&monitor->mutex_thread[i]);
		i++;
	}
	// Libération du tableau de mutex
	free(monitor->mutex_thread);

	// Destruction des autres mutex
	pthread_mutex_destroy(&monitor->mutex_print);
	pthread_mutex_destroy(&monitor->mutex_death);
}
