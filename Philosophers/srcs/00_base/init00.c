/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:08:21 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 11:50:33 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	data_init(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (*data == NULL)
	{
		printf("\n\nError to init struct t_data\n\n");
		free(data);
		exit(EXIT_FAILURE);
	}
	(*data)->forks_nb = 0;
	(*data)->tt_d = 0;
	(*data)->tt_e = 0;
	(*data)->tt_s = 0;
	(*data)->nbreat = 0;
	(*data)->forks_mutex = NULL;
	(*data)->threads = NULL;
}

void	philo_init(t_data **data, t_philo **philo)
{
	int	i;
	
	*philo = malloc(sizeof(t_philo) * (*data)->forks_nb);
	if (*philo == NULL)
	{
		printf("\n\nError to init struct t_philo\n\n");
		main_free((*data), (*philo));
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < (*data)->forks_nb)
	{
		(*philo)[i].id_philo = i + 1;
		(*philo)[i].left_fork = &(*data)->forks_mutex[i];
		(*philo)[i].right_fork = &(*data)->forks_mutex[(i + 1) % (*data)->forks_nb];
		(*philo)[i].data = (*data);
		i++;
	}
}

void	mutex_init(t_data *data, t_philo *philo)
{
	int		i;
	
	i = 0;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->forks_nb);
	if (data->forks_mutex == NULL)
	{
		printf("Error allocating memory for forks_mutex\n");
		main_free(data, philo);
		exit(EXIT_FAILURE);
	}
	while (i < data->forks_nb)
	{
		if (pthread_mutex_init(&data->forks_mutex[i], NULL) != 0)
		{
			printf("Error initializing mutex\n");
			main_free(data, philo);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
}
