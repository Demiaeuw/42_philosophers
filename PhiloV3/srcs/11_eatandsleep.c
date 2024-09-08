/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_eatandsleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:27:01 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 19:52:18 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	print_status(philo, 1);

	pthread_mutex_lock(philo->right_f);
	print_status(philo, 1);
}

void	drop_forks(t_philo *philo)
{
		pthread_mutex_unlock(philo->right_f);
		pthread_mutex_unlock(philo->left_f);
}

void	eat_action(t_philo *philo)
{
	print_status(philo, 2);
	gettimeofday(&(philo->mealtimer), NULL);
	philo->mealtaking++;
	usleep(philo->data->time_to_eat * 1000);
}

void	eat(t_philo *philo)
{
	if (check_death(philo))
		return ;
	take_forks(philo);
	eat_action(philo);
	drop_forks(philo);
}

void	sleeping(t_philo *philo)
{
	if (check_death(philo))
		return ;
	print_status(philo, 3);
	usleep(philo->data->time_to_sleep * 1000);
}
