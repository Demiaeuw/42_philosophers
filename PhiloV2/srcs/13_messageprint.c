/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_messageprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:40:33 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/03 17:39:33 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	printmessage(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->someone_died_mutex);
	if (philo->data->someone_died == 0)
	{
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("%d, Philosophe %d, is %s.\n", get_duration(philo->data), philo->id, str);
		pthread_mutex_unlock(&philo->data->printex);
	}
	pthread_mutex_unlock(&philo->data->someone_died_mutex);
}

