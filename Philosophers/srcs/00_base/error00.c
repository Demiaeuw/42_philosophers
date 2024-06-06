/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:03:32 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/06 15:53:20 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	main_error(void (*f)(), t_data *data, t_philo *philo)
{
	f();
	main_free(data, philo);
	exit(0);
}

void	error_argument(void)
{
	printf("\n\n\033[31mERROR\033[0m\n\n");
	printf("Argument Problem\n\n"
		"Format : ./philosopher "
		"\033[34m<number of philosophe>\033[0m "
		"\033[36m<time to die>\033[0m "
		"\033[34m<time to eat>\033[0m "
		"\033[36m<time to sleep>\033[0m "
		"(optional)\033[34m<number of times each philosopher "
		"must eat>\033[0m\n\n");
	return ;
}

void	error_nb_philo(void)
{
	printf("\n\n\033[31mERROR\033[0m\n\n");
	printf("Argument Problem\n\n"
		"\033[34m<number of philosophe>\033[0m must be an int > 0.\n\n");
}

void	error_ttd(void)
{
	printf("\n\n\033[31mERROR\033[0m\n\n");
	printf("Argument Problem\n\n"
		"\033[34m<time to die>\033[0m must be an int > 0.\n\n");
}

void	error_tte(void)
{
	printf("\n\n\033[31mERROR\033[0m\n\n");
	printf("Argument Problem\n\n"
		"\033[34m<time to eat>\033[0m must be an int > 0.\n\n");
}
