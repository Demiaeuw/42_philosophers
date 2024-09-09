/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:26:07 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 15:40:49 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	result = result * sign;
	return (result);
}

long	get_current_time(long start_time)
{
	struct timeval	tv;
	long			ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms - start_time);
}

int	get_duration(t_monitoring *monitor)
{
	return (get_timestamp() - monitor->time_start);
}

long	get_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	check_argument(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("\n\033[1;31mError\033[0m Invalid number of arguments.\n"
				"Usage: ./philo num_philosophers time_to_die"
				" time_to_eat time_to_sleep [num_meals_required]\n");
		return (0);
	}
	return (1);
}
