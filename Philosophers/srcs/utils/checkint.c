/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:51:03 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:40 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	check_arg_int(int ac, char **av, t_data *data, int i)
{
	(void)ac;
	if (check_is_numbr(av[i]) == 0 || check_int(av[i]) == 0)
	{
		if (i == 1)
			main_error(error_nb_philo, data);
		if (i == 2)
			main_error(error_ttd, data);
		if (i == 3)
			main_error(error_tte, data);
		if (i == 4)
			main_error(error_tts, data);
		if (i == 5)
			main_error(error_nbreat, data);
	}
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

