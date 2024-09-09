/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:15:54 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 04:49:08 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitoring_routine(void *arg)
{
	t_monitoring	*monitor;
	int				i;
	int				full_philosophers;

	monitor = (t_monitoring *)arg;

	while (!monitor->simulation_stop)
	{
		i = 0;
		full_philosophers = 0;  // Réinitialiser le compteur à chaque itération
		while (i < monitor->num_philosophers)
		{
			pthread_mutex_lock(&monitor->death_mutex);

			// Vérifier si un philosophe est mort (temps écoulé depuis le dernier repas > time_to_die)
			if (get_timestamp() - monitor->philosophers[i].last_meal_time > monitor->time_to_die)
			{
				print_status(&monitor->philosophers[i], 6); // Philosophe mort
				monitor->simulation_stop = 1;
				pthread_mutex_unlock(&monitor->death_mutex);
				return (NULL);  // Sortir immédiatement si un philosophe meurt
			}

			// Si le nombre de repas est requis, vérifier si ce philosophe a mangé suffisamment
			if (monitor->num_meals_required != -1 &&
				monitor->philosophers[i].meals_eaten >= monitor->num_meals_required)
			{
				full_philosophers++; // Ce philosophe a atteint le nombre de repas requis
			}

			pthread_mutex_unlock(&monitor->death_mutex);
			i++;
		}

		// Si le nombre de repas est requis et que tous les philosophes ont mangé suffisamment de fois, on arrête la simulation
		if (monitor->num_meals_required != -1 && full_philosophers == monitor->num_philosophers)
		{
			monitor->simulation_stop = 1; // Stopper la simulation
		}

		usleep(100); // Pause légère pour éviter de surcharger le CPU
	}

	// Libérer les ressources une fois la simulation arrêtée
	i = 0;
	while (i < monitor->num_philosophers)
	{
		pthread_mutex_unlock(monitor->philosophers[i].left_fork);
		pthread_mutex_unlock(monitor->philosophers[i].right_fork);
		i++;
	}

	// 2. Arrêter les threads des philosophes un par un
	i = 0;
	while (i < monitor->num_philosophers)
	{
		pthread_join(monitor->philosophers[i].thread, NULL);
		i++;
	}

	return (NULL);  // Le thread de monitoring s'arrête
}
