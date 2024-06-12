/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initthread00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:04:45 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 14:50:56 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	init_thread(t_data **data, t_philo **philo)
{
	int	i;

	(*data)->threads = malloc(sizeof(pthread_t) * (*data)->forks_nb);
	if ((*data)->threads == NULL)
	{
		printf("Error allocating memory for threads\n");
		main_free(*data, *philo);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < (*data)->forks_nb)
	{
		if (pthread_create(&(*data)->threads[i], NULL, philo_routine, &(*philo)[i]) != 0)
		{
			printf("Error creating thread\n");
			main_free(*data, *philo);
			free((*data)->threads);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < (*data)->forks_nb)
	{
		pthread_join((*data)->threads[i], NULL);
		i++;
	}
}
