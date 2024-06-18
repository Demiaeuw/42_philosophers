/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:50:28 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 18:48:47 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;
	
	main_init(ac, av, &data, &(*philo));
	ft_printf("salut\n");
}
