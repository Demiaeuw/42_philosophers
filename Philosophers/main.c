/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:50 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 16:03:51 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

int	main(int ac, char **av)
{
	t_data *data;
	t_philo *philo;

	data_init(&data);
	main_argument(ac, av, data, philo);
	philo_init(&data, &philo);
	mutex_init(data, philo);
	init_thread(&data, &philo);

	// Impression des structures pour le débogage
	print_struct(data);

	main_free(data, philo);
	return (0);
}
