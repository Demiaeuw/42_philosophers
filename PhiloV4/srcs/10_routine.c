/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:20:12 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 14:57:13 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(100);
	while (!philo->monitor->simulation_stop)
	{
		//printf("\n\n\n\033[1;31m%d\33[0m\n\n\n", philo->monitor->simulation_stop);
		philosopher_eat(philo);
		philosopher_sleep(philo);
		philosopher_think(philo);
		printf("\n\nNb de repas pris par %d --> %d sur %d\n\n", philo->id, philo->meals_eaten, philo->monitor->num_meals_required);
	}
	return (NULL);
}
