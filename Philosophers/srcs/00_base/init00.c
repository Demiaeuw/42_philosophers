/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:08:21 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/06 15:54:05 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_init(t_data **data, t_philo **philo)
{
	data_init(&(*data));
	philo_init(&(*philo));
}

void	data_init(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (*data == NULL)
	{
		printf("\n\nError to init struct t_data\n\n");
		exit(EXIT_FAILURE);
	}
	(*data)->forks_nb = 0;
	(*data)->tt_d = 0;
	(*data)->tt_e = 0;
	(*data)->tt_s = 0;
	(*data)->nbreat = 0;
}

void	philo_init(t_philo **philo)
{
	*philo = malloc(sizeof(t_philo));
	if (*philo == NULL)
	{
		printf("\n\nError to init struct t_philo\n\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(*philo, 0, sizeof(t_philo));
	(*philo)->id_philo = 0;
}
