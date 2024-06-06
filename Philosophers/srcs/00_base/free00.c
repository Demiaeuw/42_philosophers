/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:07:20 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/06 15:52:43 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_free(t_data *data, t_philo *philo)
{
	if (data)
		free(data);
	if (philo)
		free(philo);
	return ;
}
