/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:18:41 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/21 09:05:04 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	main_error(void (*f)(), t_data *data, t_philo *philo)
{
	f();
	main_free(data, philo);
	exit();
}

void	argument_error(void)
{
	write(1, "\n\nError !\n\nArgument issue\n", 31);
}
