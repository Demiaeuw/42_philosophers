/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:00:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:57 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	print_struct(t_data *data)
{
	printf("fork_nb : %d\n", data->forks_nb);
	printf("tt_d : %d\n", data->tt_d);
	printf("tt_e : %d\n", data->tt_e);
	printf("tt_s : %d\n", data->tt_s);
	printf("nbreat : %d\n", data->nbreat);
}