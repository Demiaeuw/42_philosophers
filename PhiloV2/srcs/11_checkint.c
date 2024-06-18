/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_checkint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:20:50 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 17:45:47 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check_arg_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if(!check_is_numbr(av[i]) || !check_int(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_is_numbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
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
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}
