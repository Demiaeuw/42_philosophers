/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:43:54 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 18:34:31 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	main_init(int ac, char **av, t_data *data, t_philo *philo)
{
	if (ac != 5 && ac != 6 ||check_arg_int(ac, av))
		ft_printf("\n\nError\nInvalid arguments\n");
	init_struct(&data, &philo);
	init_mutex(&data, &philo);
}

void	init_struct(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		ft_printf("\n\nError\nMemory allocation failed for forks\n");
		exit(1);
	}
	*philo = malloc(data->nb_meal * sizeof(t_philo));
	if (!*philo)
	{
		ft_printf("\n\nError\nMemory allocation failed for philosophers\n");
		exit(1);
	}
	while (i < data->nb_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].nb_eaten = 0;
		(*philo)[i].last_meal = 0;
		(*philo)[i].data = data;
		i++;
	}
}

void	init_mutex(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			ft_printf("\n\nError\nMutex initialization failed\n");
			exit(1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		ft_printf("\n\nError\nMutex initialization failed\n");
		exit(1);
	}
}
