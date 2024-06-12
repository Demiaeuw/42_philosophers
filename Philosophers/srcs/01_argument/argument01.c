/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:30:52 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 14:46:30 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

/**
 * Number of times each philosopher must eat
*/
void	nbr_eat(char **av, t_data *data, t_philo *philo)
{
	check_arg_int(av, data, 5, philo);
	data->nbreat = ft_atoi(av[5]);
}
