/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:22:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/25 17:53:33 by acabarba         ###   ########.fr       */
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

	philo = (t_philo *) arg;
	while (1)
	{
		// Manger (sans gestion des forks avec gestion du nombre de repas)
		if (philo->data->nb_meal_needed == -1 || philo->nb_meal < philo->data->nb_meal_needed)
		{
			pthread_mutex_lock(&philo->data->printex);
			ft_printf("\33[1;34mPhilosophe n°\33[0m %d \33[1;34mstart eating.\n\33[0m", philo->id);
			pthread_mutex_unlock(&philo->data->printex);
			usleep(1000 * philo->data->time_to_eat);
			philo->nb_meal++;
			pthread_mutex_lock(&philo->data->printex);
			ft_printf("\33[3;34mPhilosophe n°\33[0m %d \33[3;34mfinished eating.\n\33[0m", philo->id);
			pthread_mutex_unlock(&philo->data->printex);
		}
		if (philo->data->nb_meal_needed > 0 && philo->nb_meal == philo->data->nb_meal_needed)
		{
			pthread_mutex_lock(&philo->data->printex);
			ft_printf("\33[2;34mPhilosophe n°\33[0m %d \33[2;34mhas eaten enough.\n\33[0m", philo->id);
			pthread_mutex_unlock(&philo->data->printex);
			break;
		}
		//

		// Dormir
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[32mPhilosophe n°\33[0m %d \033[32mgo to bed.\033[0m\n", philo->id);
		usleep(1000 * philo->data->time_to_sleep);
		pthread_mutex_unlock(&philo->data->printex);
		//

		// Penser
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("\033[33mPhilosophe n°\33[0m %d \033[33mthinking.\033[0m\n", philo->id);
		pthread_mutex_unlock(&philo->data->printex);
		//
		
		// Gestion de la Mort, si attente depuis le dernier repas > philo->data->time_to_death
		//
	}
	return (NULL);
}
