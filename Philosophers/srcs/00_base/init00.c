/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:08:21 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/05 17:14:32 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_init(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (*data == NULL)
	{
		exit(EXIT_FAILURE);
	}
	(*data)->forks_nb = 0;
	(*data)->tt_d = 0;
	(*data)->tt_e = 0;
	(*data)->tt_s = 0;
	(*data)->nbreat = 0;
}
