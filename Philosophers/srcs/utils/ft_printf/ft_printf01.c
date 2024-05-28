/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:16:13 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/07 17:17:48 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int	ftp_putnbrhex(unsigned long n)
{
	char	*tab;
	int		i;

	i = 0;
	tab = "0123456789abcdef";
	if (n < 16)
		i += ftp_putchar(tab[n]);
	else
	{
		i += ftp_putnbrhex(n / 16);
		i += ftp_putchar(tab[n % 16]);
	}
	return (i);
}

int	ftp_putnbrhe_x(unsigned long n)
{
	char	*tab;
	int		i;

	i = 0;
	tab = "0123456789ABCDEF";
	if (n < 16)
		i += ftp_putchar(tab[n]);
	else
	{
		i += ftp_putnbrhe_x(n / 16);
		i += ftp_putchar(tab[n % 16]);
	}
	return (i);
}
