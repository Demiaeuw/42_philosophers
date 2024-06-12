/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:36 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 12:02:02 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	*philo_routine(void *arg, t_data *data)
{
	int	id;
	
	id = ((t_philo *)arg)->id_philo;
	pthread_mutex_lock(&data->print_mutex);
	printf("philosopne n° %d : je suis a la routine\n", id);
	pthread_mutex_unlock(&data->print_mutex);
	return NULL;
}
