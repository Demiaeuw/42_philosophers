/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:08 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/08 22:45:59 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	ftp_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ftp_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ftp_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ftp_putnbr(long long int n)
{
	int	i;

	i = ftp_intlen(n);
	if (n < 0)
	{
		ftp_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		ftp_putchar(n + '0');
	}
	else
	{
		ftp_putnbr(n / 10);
		ftp_putnbr(n % 10);
	}
	return (i);
}

int	ftp_put_u_nbr(unsigned int n)
{
	int	i;

	i = ftp_intlen(n);
	if (n <= 9)
	{
		ftp_putchar(n + '0');
	}
	else
	{
		ftp_put_u_nbr(n / 10);
		ftp_put_u_nbr(n % 10);
	}
	return (i);
}

int	ftp_percent(void)
{
	write(1, "%", 1);
	return (1);
}
