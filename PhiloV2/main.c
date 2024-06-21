/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:16:47 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/21 09:06:25 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosopher.h"

int		main(int ac, char **av)
{
	t_data *data;
	t_philo *philo;
	if (argument_checker(ac, av) == -1)
		argument_error();
	init_struct(data, &philo, ac, av);
	write(1, "HelloWorld\n", 11);
}