/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:04:46 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 18:49:25 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				i;

	if (check_arguments(ac) || init_data(ac, av, &data))
		return (1);

	philos = malloc(sizeof(t_philo) * data.nb_philo);
	forks = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
	if (!philos || !forks)
		return (1);
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	init_philos(philos, &data, forks);
	if (start_simulation(philos, &data))
	{
		cleanup_simulation(philos, &data, forks);
		return (1);
	}
	cleanup_simulation(philos, &data, forks);

	return (0);
}

