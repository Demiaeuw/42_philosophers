/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:07:20 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 11:58:56 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_free(t_data *data, t_philo *philo)
{
	int	i;

	if (data)
	{
		if (data->forks_mutex)
		{
			i = 0;
			while (i < data->forks_nb)
			{
				pthread_mutex_destroy(&data->forks_mutex[i]);
				i++;
			}
			free(data->forks_mutex);
		}
		if (data->threads)
			free(data->threads);
		free(data);
	}
	if (philo)
	{
		free(philo);
	}
	return ;
}
