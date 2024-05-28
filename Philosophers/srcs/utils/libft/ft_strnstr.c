/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:24:47 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/30 12:39:54 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *	The strnstr() function locates the first occurrence of the
 *	null-termi-nated string little in the string big,where not more 
 *	than len charac-ters are searched.
 *	Characters that appear after a `\0' character are not  searched.
 *	Since the strnstr() function is a FreeBSD specific API,
 *	it should only be used when portability is not a concern.
*/

#include "../../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		k = 0;
		while (little[k] == big[i + k] && (i + k) < len)
		{
			if (little[k + 1] == '\0')
			{
				return ((char *)big + i);
			}
			k++;
		}
		i++;
	}
	return (NULL);
}
