/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compteur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:33:55 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/07 17:19:55 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nb;
	va_list	args;

	i = 0;
	nb = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			nb += ftp_format(args, str[i + 1]);
			i++;
		}
		else
		{
			nb += ftp_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (nb);
}

int	ftp_intlen(long long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	i++;
	return (i);
}

int	ftp_put_pointer(void *n)
{
	int	i;

	i = 0;
	if (n == NULL)
	{
		i += ftp_putstr("(nil)");
		return (i);
	}
	else
	{
		i += ftp_putstr("0x");
		i += ftp_putnbrhex((unsigned long)n);
		return (i);
	}
}

int	ftp_format(va_list args, const char format)
{
	int	nb;

	nb = 0;
	if (format == 'c')
		nb += ftp_putchar(va_arg(args, int));
	else if (format == 's')
		nb += ftp_putstr(va_arg(args, char *));
	else if (format == 'i')
		nb += ftp_putnbr(va_arg(args, int));
	else if (format == 'd')
		nb += ftp_putnbr(va_arg(args, int));
	else if (format == 'u')
		nb += ftp_put_u_nbr(va_arg(args, unsigned int));
	else if (format == 'p')
		nb += ftp_put_pointer(va_arg(args, void *));
	else if (format == 'x')
		nb += ftp_putnbrhex((long)va_arg(args, unsigned int));
	else if (format == 'X')
		nb += ftp_putnbrhe_x((long)va_arg(args, unsigned int));
	else if (format == '%')
		nb += ftp_percent();
	return (nb);
}

int	ftp_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	result = result * sign;
	return (result);
}
