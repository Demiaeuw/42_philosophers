/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:28:21 by acabarba          #+#    #+#             */
/*   Updated: 2024/04/29 13:55:45 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/get_next_line.h"

char	*gnl_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	gnl_strlen(const char *c)
{
	size_t	len;

	if (!c)
		return (0);
	len = 0;
	while (c[len])
		len++;
	return (len);
}

void	gnl_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*pointeur;

	pointeur = malloc(nmemb * size);
	if (!pointeur)
		return (NULL);
	gnl_bzero(pointeur, (nmemb * size));
	return (pointeur);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2 || !s1)
		return (NULL);
	s3 = malloc(sizeof(char) * ((gnl_strlen(s1) + gnl_strlen(s2)) + 1));
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	k = -1;
	while (s2[++k])
		s3[i + k] = s2[k];
	s3[i + k] = '\0';
	free (s1);
	return (s3);
}
