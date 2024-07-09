/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_messageprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:40:33 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/09 17:55:32 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// Avec couleurs
// void	printmessage(t_philo *philo, char *message)
// {
// 	pthread_mutex_lock(&philo->data->someone_died_mutex);
// 	if (philo->data->someone_died == 0)
// 	{
// 		pthread_mutex_lock(&philo->data->printex);
// 		if (ft_strcmp(message, "thinking") == 0)
// 			ft_printf("%d \033[33mPhilosophe n°\33[0m %d \033[33m"
// 				"thinking.\033[0m\n", get_duration(philo->data), philo->id);
// 		else if (ft_strcmp(message, "eating") == 0)
// 			ft_printf("%d \033[1;34mPhilosophe n°\33[0m %d \33[1;34m"
// 				"start eating.\n\33[0m", get_duration(philo->data), philo->id);
// 		else if (ft_strcmp(message, "sleeping") == 0)
// 			ft_printf("%d \033[32mPhilosophe n°\33[0m %d \033[32m"
// 				"go to bed.\033[0m\n", get_duration(philo->data), philo->id);
// 		else if (ft_strcmp(message, "full") == 0)
// 			ft_printf("%d \033[2;34mPhilosophe n°\33[0m %d \33[2;34mhas eaten"
// 				" enough.\n\033[0m", get_duration(philo->data), philo->id);
// 		else if (ft_strcmp(message, "dead") == 0)
// 			ft_printf("%d Philosophe n° %d "
// 				"is dead.\n", get_duration(philo->data), philo->id);
// 		else
// 			ft_printf("%d, Philosophe %d, "
// 				"is %s.\n", get_duration(philo->data), philo->id, message);
// 		pthread_mutex_unlock(&philo->data->printex);
// 	}
// 	pthread_mutex_unlock(&philo->data->someone_died_mutex);
// }

// Sans couleurs
void	printmessage(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->someone_died_mutex);
	if (philo->data->someone_died == 0)
	{
		pthread_mutex_lock(&philo->data->printex);
		if (strcmp(message, "thinking") == 0)
			printf("%d Philosophe n° %d thinking.\n", get_duration(philo->data), philo->id);
		else if (strcmp(message, "eating") == 0)
			printf("%d Philosophe n° %d start eating.\n", get_duration(philo->data), philo->id);
		else if (strcmp(message, "sleeping") == 0 || strcmp(message, "bed") == 0)
			printf("%d Philosophe n° %d go to bed.\n", get_duration(philo->data), philo->id);
		else if (strcmp(message, "full") == 0)
			printf("%d Philosophe n° %d has eaten enough.\n", get_duration(philo->data), philo->id);
		else if (strcmp(message, "dead") == 0 || strcmp(message, "died") == 0)
			printf("%d Philosophe n° %d is dead.\n", get_duration(philo->data), philo->id);
		else
			printf("%d Philosophe n° %d is %s.\n", get_duration(philo->data), philo->id, message);
		pthread_mutex_unlock(&philo->data->printex);
	}
	pthread_mutex_unlock(&philo->data->someone_died_mutex);
}


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
