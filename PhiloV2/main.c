/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:16:47 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/05 20:18:23 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (argument_checker(ac, av) == -1)
	{
		error_argument();
		return (-1);
	}
	if (init_struct(&data, &philo, ac, av) == -1)
	{
		main_error(error_argument, data, philo);
		return (-1);
	}
	if (create_thread(data, philo) == -1)
	{
		main_error(error_thread, data, philo);
		return (-1);
	}
	cleanup(data, philo);
	return (0);
}
