/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:12:44 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/11 02:20:28 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		ft_error("Error, program needs 5 or 6 args");
	if (!check_value(argc, argv))
		ft_error("Error, args are not digit");
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		ft_error("Error, args not positive");
}

void	check_eatdeath(int i, t_data *data, t_philo *ph)
{
	while (++i < data->philo_nb && !(data->is_dead))
	{
		pthread_mutex_lock(&(data->mutex_eat));
		if ((get_time() - ph[i].time_philolastmeal) > data->tt_death)
			print_status(data, i + 1, "is dead");
		if ((get_time() - ph[i].time_philolastmeal) > data->tt_death)
			data->is_dead = 1;
		pthread_mutex_unlock(&(data->mutex_eat));
		usleep(100);
	}
}

void	is_dead(t_data *data, t_philo *ph)
{
	int	i;

	while (1)
	{
		i = -1;
		check_eatdeath(i, data, ph);
		if (data->is_dead)
			break ;
		i = 0;
		pthread_mutex_lock(&(data->mutex_eat));
		while (data->tt_meal != -1 && i < data->philo_nb
			&& ph[i].philo_nbeat >= data->tt_meal)
			i++;
		if (i == data->philo_nb)
		{
			data->check_eat = 1;
			pthread_mutex_unlock(&(data->mutex_eat));
			end_sim(data);
			pthread_mutex_lock(&(data->mutex_eat));
		}
		pthread_mutex_unlock(&(data->mutex_eat));
	}
}

int	check_value(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
