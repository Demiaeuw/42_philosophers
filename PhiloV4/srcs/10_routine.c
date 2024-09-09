/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:20:12 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 04:42:41 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(10);
	while (!philo->monitor->simulation_stop)
	{
		philosopher_eat(philo);
		philosopher_sleep(philo);
		philosopher_think(philo);
		printf("\n\nNb de repas pris par %d --> %d sur %d\n\n", philo->id, philo->meals_eaten, philo->monitor->num_meals_required);
	}
	return (NULL);
}
