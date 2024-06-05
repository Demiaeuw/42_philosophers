/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:50 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/05 17:03:17 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	
	main_init(&philo);
	main_argument(ac, av, philo);
	print_struct(&(*philo));
	main_free(philo);
	return (0);
}