/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:36 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 14:58:30 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	*philo_routine(void *arg)
{
	int	id;

	id = ((t_philo *)arg)->id_philo;
	printf("philosopne n° %d : je suis a la routine\n", id);
	return (NULL);
}
