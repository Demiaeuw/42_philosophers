/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:18:41 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/23 19:21:51 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	main_error(void (*f)(), t_data *data, t_philo *philo)
{
	f();
	cleanup(data, philo);
	exit(EXIT_FAILURE);
}

void	error_argument(void)
{
	ft_printf("\n\nError !\n\nArgument issue\n\n");
}

void	error_thread(void)
{
	ft_printf("\n\nError !\n\nThread issue\n\n");
}

void	error_mutex(void)
{
	ft_printf("\n\nError !\n\nMutex issue\n\n");
}
