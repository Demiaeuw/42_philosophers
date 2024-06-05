/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:45:19 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/05 16:55:06 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	error_tts(void)
{
	printf("\n\n\033[31mERROR\033[0m\n\n");
	printf("Argument Problem\n\n"
		"\033[34m<time to sleep>\033[0m must be an int > 0.\n\n");
}

void	error_nbreat(void)
{
	printf("\n\n\033[31mERROR\033[0m\n\n");
	printf("Argument Problem\n\n"
		"\033[34m<number of times each philosopher must eat"
		">\033[0m must be an int > 0.\n\n");
}