/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:20:23 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 20:20:25 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_simulation(t_philo *philos, t_data *data)
{
	int	i;

	if (data->nb_philo == 1)
	{
		print_status(&philos[0], 1);
		usleep(data->time_to_die * 1000);
		print_status(&philos[0], 6);
		return (0);
	}
	i = 0;
	data->start_time = get_timestamp();
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philos[i].thread), NULL, &ft_routine, &(philos[i])) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(10);
	while (1)
	{
		if (philo->data->nb_meal != -1
			&& philo->mealtaking >= philo->data->nb_meal)
			break ;
		if (death(philo))
			break ;
		eat(philo);
		if (death(philo))
			break ;
		sleeping(philo);
		if (death(philo))
			break ;
		think(philo);
		if (death(philo))
			break ;
	}
	return (NULL);
}

