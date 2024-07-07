/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_checkint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:47:13 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/07 22:16:06 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	check_is_numbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	check_int(char *str)
{
	int			i;
	int long	nbr;

	i = 0;
	while (str[i])
	{
		nbr = ft_atol(str);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int	argument_checker(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (check_is_numbr(av[i]) == -1)
				return (-1);
			if (check_int(av[i]) == -1)
				return (-1);
			i++;
		}
		return (0);
	}
	else
		return (-1);
}
