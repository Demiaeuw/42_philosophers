/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_eatandsleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:41:21 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 04:31:29 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philosopher_eat(t_philo *philo)
{
	// Le philosophe prend d'abord la fourchette à gauche de lui (sa propre fourchette)
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, 1); // A pris sa propre fourchette

	// Ensuite, il prend la fourchette à droite de lui (celle de son voisin)
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, 1); // A pris la fourchette de son voisin

	// Maintenant, il mange
	pthread_mutex_lock(&philo->monitor->meals_mutex);
	print_status(philo, 2); // Commence à manger
	philo->meals_eaten++;
	philo->last_meal_time = get_current_time(philo->monitor->simulation_start);
	pthread_mutex_unlock(&philo->monitor->meals_mutex);

	// Simule le temps nécessaire pour manger
	usleep(philo->monitor->time_to_eat * 1000);

	// Libère les deux fourchettes après avoir mangé
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}


void	philosopher_sleep(t_philo *philo)
{
	print_status(philo, 3);
	usleep(philo->monitor->time_to_sleep * 1000);
}

void	philosopher_think(t_philo *philo)
{
	print_status(philo, 4);
}
