/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:36:38 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 14:49:38 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_argument(int ac, char **av, t_data *data, t_philo *philo)
{
	(void)av;
	if (ac != 5 && ac != 6)
		main_error(error_argument, data, philo);
	forksnbr(av, data, philo);
	t_t_d(av, data, philo);
	t_t_e(av, data, philo);
	t_t_s(av, data, philo);
	if (ac == 6)
		nbr_eat(av, data, philo);
}

/**
 * Number of philosophe
*/
void	forksnbr(char **av, t_data *data, t_philo *philo)
{
	check_arg_int(av, data, 1, philo);
	data->forks_nb = ft_atoi(av[1]);
}

/**
 * Time to die
*/
void	t_t_d(char **av, t_data *data, t_philo *philo)
{
	check_arg_int(av, data, 2, philo);
	data->tt_d = ft_atoi(av[2]);
}

/**
 * Time to eat
*/
void	t_t_e(char **av, t_data *data, t_philo *philo)
{
	check_arg_int(av, data, 3, philo);
	data->tt_e = ft_atoi(av[3]);
}

/**
 * Time to sleep
*/
void	t_t_s(char **av, t_data *data, t_philo *philo)
{
	check_arg_int(av, data, 4, philo);
	data->tt_s = ft_atoi(av[4]);
}
