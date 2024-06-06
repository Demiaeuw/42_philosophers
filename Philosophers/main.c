/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:50 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/06 15:50:30 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo *philo;
	
	main_init(&data, &philo);
	main_argument(ac, av, data);
	
	//
	print_struct(&(*data));
	//
	
	//
	philo->id_philo = 1;
	eat(ac, av, &(*philo));
	//
	
	main_free(data, philo);
	return (0);
}
