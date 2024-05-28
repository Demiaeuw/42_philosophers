/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:56:58 by acabarba          #+#    #+#             */
/*   Updated: 2024/04/29 13:56:59 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "include.h"

// ft_printf
int	ft_printf(const char *str, ...);
int	ftp_intlen(long long nb);
int	ftp_put_pointer(void *n);
int	ftp_format(va_list args, const char format);
int	ftp_atoi(const char *str);
int	ftp_putnbrhex(unsigned long n);
int	ftp_putnbrhe_x(unsigned long n);
int	ftp_putchar(char c);
int	ftp_putstr(char *s);
int	ftp_putnbr(long long int n);
int	ftp_put_u_nbr(unsigned int n);
int	ftp_percent(void);

#endif
