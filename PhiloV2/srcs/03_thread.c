/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:22:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/03 18:18:23 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	create_thread(t_data *data, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	struct timeval current_time;
	long	time_diff;

	philo = (t_philo *) arg;

	if (philo->data->nb_philo == 1)
	{
		gestion_one_forks(philo);
		return (NULL);
	}
	while (philo->data->someone_died != 1)
	{
		// Vérification de la mort et de l'état général
		gettimeofday(&current_time, NULL);
		time_diff = (current_time.tv_sec - philo->last_meal.tv_sec) * 1000 + 
					(current_time.tv_usec - philo->last_meal.tv_usec) / 1000;
		if (time_diff > philo->data->time_to_die || philo->data->someone_died)
		{
			if (time_diff > philo->data->time_to_die)
			{
				printmessage(philo, "dead");
				pthread_mutex_lock(&philo->data->someone_died_mutex);
				philo->data->someone_died = 1;
				pthread_mutex_unlock(&philo->data->someone_died_mutex);
			}
			break ;
		}

		// Penser
		printmessage(philo, "thinking");

		// Prendre les fourchettes
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);

		// Vérification de la mort avant de manger
		gettimeofday(&current_time, NULL);
		time_diff = (current_time.tv_sec - philo->last_meal.tv_sec) * 1000 + 
					(current_time.tv_usec - philo->last_meal.tv_usec) / 1000;
		if (time_diff > philo->data->time_to_die || philo->data->someone_died)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			if (time_diff > philo->data->time_to_die)
			{
				printmessage(philo, "dead");
				pthread_mutex_lock(&philo->data->someone_died_mutex);
				philo->data->someone_died = 1;
				pthread_mutex_unlock(&philo->data->someone_died_mutex);
			}
			break ;
		}

		// Manger
		printmessage(philo, "eating");
		gettimeofday(&philo->last_meal, NULL); // Mettre à jour l'horodatage du dernier repas
		usleep(1000 * philo->data->time_to_eat);
		philo->nb_meal++;

		// Lâcher les fourchettes
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		// Vérifier si le philosophe a mangé assez de fois
		if (philo->data->nb_meal_needed > 0 && philo->nb_meal == philo->data->nb_meal_needed)
		{
			printmessage(philo, "full");
			break ;
		}

		// Dormir
		printmessage(philo, "sleeping");
		usleep(1000 * philo->data->time_to_sleep);
	}
	return (NULL);
}
