/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:22:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/27 16:34:28 by acabarba         ###   ########.fr       */
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
	while (1)
	{
		// Vérification de la mort et de l'état général
		gettimeofday(&current_time, NULL);
		time_diff = (current_time.tv_sec - philo->last_meal.tv_sec) * 1000 + 
		            (current_time.tv_usec - philo->last_meal.tv_usec) / 1000;
		if (time_diff > philo->data->time_to_die || philo->data->someone_died)
		{
			pthread_mutex_lock(&philo->data->printex);
			if (time_diff > philo->data->time_to_die)
			{
				ft_printf("Philosophe n° %d is dead.\n", philo->id);
				philo->data->someone_died = 1;
			}
			pthread_mutex_unlock(&philo->data->printex);
			break;
		}

		// Penser
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[33mPhilosophe n°\33[0m %d \033[33mthinking.\033[0m\n", philo->id);
		pthread_mutex_unlock(&philo->data->printex);

		// Prendre les fourchettes
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[31mPhilosophe n°\33[0m %d \033[31mtake RIGHT_Fork.\033[0m\n", philo->id);
		pthread_mutex_unlock(&philo->data->printex);

		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[31mPhilosophe n°\33[0m %d \033[31mtake LEFT_Fork.\033[0m\n", philo->id);
		pthread_mutex_unlock(&philo->data->printex);

		// Vérification de la mort avant de manger
		gettimeofday(&current_time, NULL);
		time_diff = (current_time.tv_sec - philo->last_meal.tv_sec) * 1000 + 
		            (current_time.tv_usec - philo->last_meal.tv_usec) / 1000;
		if (time_diff > philo->data->time_to_die || philo->data->someone_died)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_lock(&philo->data->printex);
			if (time_diff > philo->data->time_to_die)
			{
				ft_printf("Philosophe n° %d is dead.\n", philo->id);
				philo->data->someone_died = 1;
			}
			pthread_mutex_unlock(&philo->data->printex);
			break;
		}

		// Manger
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\33[1;34mPhilosophe n°\33[0m %d \33[1;34mstart eating.\n\33[0m", philo->id);
		pthread_mutex_unlock(&philo->data->printex);

		gettimeofday(&philo->last_meal, NULL); // Mettre à jour l'horodatage du dernier repas
		usleep(1000 * philo->data->time_to_eat);
		philo->nb_meal++;

		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\33[3;34mPhilosophe n°\33[0m %d \33[3;34mfinished eating.\n\33[0m", philo->id);
		pthread_mutex_unlock(&philo->data->printex);

		// Lâcher les fourchettes
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[31mPhilosophe n°\33[0m %d \033[31mdrop RIGHT_Fork.\033[0m\n", philo->id);
		pthread_mutex_unlock(&philo->data->printex);

		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[31mPhilosophe n°\33[0m %d \033[31mdrop LEFT_Fork.\033[0m\n", philo->id);
		pthread_mutex_unlock(&philo->data->printex);

		// Vérifier si le philosophe a mangé assez de fois
		if (philo->data->nb_meal_needed > 0 && philo->nb_meal == philo->data->nb_meal_needed)
		{
			pthread_mutex_lock(&philo->data->printex);
			ft_printf("\33[2;34mPhilosophe n°\33[0m %d \33[2;34mhas eaten enough.\n\33[0m", philo->id);
			pthread_mutex_unlock(&philo->data->printex);
			break;
		}

		// Dormir
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[32mPhilosophe n°\33[0m %d \033[32mgo to bed.\033[0m\n", philo->id);
		pthread_mutex_unlock(&philo->data->printex);
		usleep(1000 * philo->data->time_to_sleep);
	}
	return (NULL);
}

