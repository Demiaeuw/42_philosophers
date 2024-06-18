/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:40:25 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 16:52:45 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void ft_putstr(char *str, int *count)
{
    if (!str)
        str = "(null)";
    int i = 0;
    while(str[i])
    {
        *count += write(1, &str[i], 1);
        i++; 
    }
}

void ft_putnbrbase(long long int nb, int base, int *count)
{
    char *tab = "0123456789abcdef";

    if (nb < 0)
    {
        nb = -nb;
        *count += write (1, "-", 1);
    }
    if (nb >= base)
    {
        ft_putnbrbase((nb / base), base, count);
    }
    *count += write(1, &tab[nb % base], 1);
}


int ft_printf(const char *str, ... )
{
    int count = 0;
    int i = 0;
    va_list arg;

    va_start(arg, str);
    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
                ft_putstr(va_arg(arg, char*), &count);
            else if (str[i] == 'd')
                ft_putnbrbase((long long int)va_arg(arg, int), 10, &count);
            else if (str[i] == 'x')
                ft_putnbrbase((long long int)va_arg(arg, unsigned int), 16, &count);
        }
        else
            count += write(1, &str[i], 1);
        i++;
    }
    return (va_end(arg), count);
}
