/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:50 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/07 14:37:05 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo *philo;
	
	data_init(&data);
	philo_init(&data, &philo);
	main_argument(ac, av, data, philo);
	mutex_init(data, philo);
	
	//
	print_struct(&(*data));
	//
	
	main_free(data, philo);
	return (0);
}
