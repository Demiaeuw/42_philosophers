/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat00.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:02:50 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/06 15:56:24 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	eat(int ac, char **av, t_philo *philo)
{
	long	duration;
	
	(void)ac;
	gettimeofday(&philo->start_meal, NULL);
	printf("%ln >> Philosopher %ls starts eating\n",
		&philo->start_meal.tv_sec, &philo->id_philo);
	usleep(atoi(av[3]));
	gettimeofday(&philo->end_meal, NULL);
	printf("%ln >> Philosopher %ls finishes eating\n",
		&philo->end_meal.tv_sec, &philo->id_philo);
	duration = ((&philo->end_meal.tv_sec - &philo->start_meal.tv_sec)
		* 1000000L + 
		(philo->end_meal.tv_usec - philo->start_meal.tv_usec));
	printf("Philosopher %ls ate for %ld", &philo->id_philo, duration);
	return ;
}