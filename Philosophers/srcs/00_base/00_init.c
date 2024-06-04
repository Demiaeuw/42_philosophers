/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:08:21 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/04 17:42:33 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_init(t_philo **philo)
{
	*philo = malloc(sizeof(t_philo));
	if (*philo == NULL)
	{
		exit(EXIT_FAILURE);
	}
	(*philo)->forks_nb = 0;
}
