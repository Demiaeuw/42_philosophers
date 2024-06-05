/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:36:38 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:04 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_argument(int ac, char **av, t_data *data)
{
	(void)av;
	if (ac != 5 && ac != 6)
		main_error(error_argument, data);
	forksnbr(ac, av, data);
	t_t_d(ac, av, data);
	t_t_e(ac, av, data);
	t_t_s(ac, av, data);
	if (ac == 6)
		nbr_eat(ac, av, data);
	
}

/**
 * Number of philosophe
*/
void	forksnbr(int ac, char **av, t_data *data)
{
	check_arg_int(ac, av, data, 1);
	data->forks_nb = ft_atoi(av[1]);
}

/**
 * Time to die
*/
void	t_t_d(int ac, char **av, t_data *data)
{
	check_arg_int(ac, av, data, 2);
	data->tt_d = ft_atoi(av[2]);
}

/**
 * Time to eat
*/
void	t_t_e(int ac, char **av, t_data *data)
{
	check_arg_int(ac, av, data, 3);
	data->tt_e = ft_atoi(av[3]);
}

/**
 * Time to sleep
*/
void	t_t_s(int ac, char **av, t_data *data)
{
	check_arg_int(ac, av, data, 4);
	data->tt_s = ft_atoi(av[4]);
}
