/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:36 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/07 14:50:32 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	*philo_routine(void *arg)
{
	(void)arg;
	printf("je suis a la routine");
	return NULL;
}
