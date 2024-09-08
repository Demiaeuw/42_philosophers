/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:07:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 19:21:55 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_arguments(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	return (0);
}

int	init_data(int ac, char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meal = ft_atoi(av[5]);
	else
		data->nb_meal = -1;
	data->start_time = get_timestamp();
	data->diecheck = 0;
	data->diecheck_m = malloc(sizeof(pthread_mutex_t));
	data->printex = malloc(sizeof(pthread_mutex_t));
	if (!data->diecheck_m || !data->printex)
		return (1);
	pthread_mutex_init(data->diecheck_m, NULL);
	pthread_mutex_init(data->printex, NULL);
	return (0);
}

int	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].meallimit = (data->nb_meal != -1);
		philos[i].mealtaking = 0;
		philos[i].mealfull = 0;
		gettimeofday(&(philos[i].mealtimer), NULL);

		philos[i].left_f = &forks[i];
		philos[i].right_f = &forks[(i + 1) % data->nb_philo];

		philos[i].data = data;
		i++;
	}
	return (0);
}

