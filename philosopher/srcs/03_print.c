/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:08:32 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 18:12:14 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_status(t_philo *philo, char *status)
{
	long	timer;
	
	pthread_mutex_lock(&philo->monitoring->mutex_print);
	philo->monitoring->time_present = get_timestamp();
	timer = philo->monitoring->time_present - philo->monitoring->time_start;
	if (!philo->monitoring->check_death)
		printf("%ld %d %s\n", timer, philo->id, status);
    pthread_mutex_unlock(&philo->monitoring->mutex_print);
}
