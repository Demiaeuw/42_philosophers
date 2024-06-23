/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:01:20 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/23 19:31:14 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	ft_putstr_printf(char *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
}

void	ft_pr_pf(long long int nb, int base, int *count)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (nb < 0)
	{
		nb = -nb;
		*count += write (1, "-", 1);
	}
	if (nb >= base)
	{
		ft_pr_pf((nb / base), base, count);
	}
	*count += write(1, &tab[nb % base], 1);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr_printf(va_arg(arg, char *), &count);
			else if (str[i] == 'd')
				ft_pr_pf((long long int)va_arg(arg, int), 10, &count);
			else if (str[i] == 'x')
				ft_pr_pf((long long int)va_arg(arg, unsigned int), 16, &count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	return (va_end(arg), count);
}
