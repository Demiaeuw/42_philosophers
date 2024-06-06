/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:36:53 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/06 15:37:04 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*j;

	j = (unsigned char *)s;
	while (n > 0)
	{
		*(j) = (unsigned char)c;
		j++;
		n--;
	}
	return (s);
}
