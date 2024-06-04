/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:36:38 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/04 18:11:34 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_argument(int ac, char **av, t_philo *philo)
{
	(void)av;
	if (ac != 5 && ac != 6)
		main_error(error_argument, philo);
	forksnbr(ac, av, philo);
}

void	forksnbr(int ac, char **av, t_philo *philo)
{
	check_arg_int(ac, av, philo);
	philo->forks_nb = ft_atoi(av[1]);
}