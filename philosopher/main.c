/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:08:44 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 18:42:41 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	t_monitoring monitor;

	
	if (!check_argument(ac))
		return (1);
	if (init_monitoring(&monitor, ac, av) != 0)
	{
		printf("Failed to initialize monitoring.\n");
		return (1);
	}
	if (start_simulation(&monitor) != 0)
	{
		printf("Failed to start simulation.\n");
		clean_monitoring(&monitor);
		return (1);
	}
	clean_monitoring(&monitor);
	return (0);
}