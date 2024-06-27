/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:18:39 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/27 15:15:24 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	init_data(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meal_needed = ft_atoi(av[5]);
	else
		data->nb_meal_needed = -1;
	if (pthread_mutex_init(&data->printex, NULL) != 0)
	{
		error_mutex();
		free(data);
		exit(EXIT_FAILURE);
	}
	data->someone_died = 0;
}

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;
	pthread_mutex_t	*forks;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (NULL);
	forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!forks)
	{
		free(philo);
		return (NULL);
	}
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_meal = 0;
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % data->nb_philo];
		philo[i].print = NULL;
		philo[i].data = data;
		gettimeofday(&philo[i].last_meal, NULL);
		i++;
	}
	return (philo);
}

int	init_struct(t_data **data, t_philo **philo, int ac, char **av)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (-1);
	init_data(*data, ac, av);
	*philo = init_philo(*data);
	if (!*philo)
	{
		free(*data);
		return (-1);
	}
	return (0);
}
