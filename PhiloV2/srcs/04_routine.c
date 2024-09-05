/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:29:12 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/05 17:23:46 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	check_and_print(t_philo *philo, char *message)
{
	if (check_death(philo))
		return ;
	printmessage(philo, message);
}

void	eat_and_sleep(t_philo *philo)
{
	if (check_death(philo))
	{
		drop_forks(philo);
		return ;
	}
	printmessage(philo, "eating");
	gettimeofday(&philo->last_meal, NULL);
	usleep(1000 * philo->data->time_to_eat);
	philo->nb_meal++;
	drop_forks(philo);
	if (check_meals(philo))
	{
		printf("\n   a finis de mager \n\n");
		return ;
	}
	printmessage(philo, "sleeping");
	usleep(1000 * philo->data->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->data->nb_philo == 1)
	{
		gestion_one_forks(philo);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->data->someone_died_mutex);
		if (philo->data->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->data->someone_died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->someone_died_mutex);
		if (check_death(philo))
			break ;
		check_and_print(philo, "thinking");
		take_forks(philo);
		eat_and_sleep(philo);
	}
	return (NULL);
}
