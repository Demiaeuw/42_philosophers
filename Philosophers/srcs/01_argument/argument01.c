/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:30:52 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/07 13:02:41 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/**
 * Number of times each philosopher must eat
*/
void	nbr_eat(int ac, char **av, t_data *data, t_philo *philo)
{
	check_arg_int(ac, av, data, 5, philo);
	data->nbreat = ft_atoi(av[5]);
}
