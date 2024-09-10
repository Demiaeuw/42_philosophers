/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:12:44 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/10 23:15:55 by acabarba         ###   ########.fr       */
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

void	check_eat_death(int i, t_data *data, t_philo *ph)
{
	while (++i < data->n_philo && !(data->is_dead))
	{
		pthread_mutex_lock(&(data->eat_m));
		if ((stock_time() - ph[i].last_eat_ph) > data->t_die)
			print_action(data, i + 1, "is dead");
		if ((stock_time() - ph[i].last_eat_ph) > data->t_die)
			data->is_dead = 1;
		pthread_mutex_unlock(&(data->eat_m));
		usleep(100);
	}
}

void	is_dead(t_data *data, t_philo *ph)
{
	int	i;

	while (1)
	{
		i = -1;
		check_eat_death(i, data, ph);
		if (data->is_dead)
			break ;
		i = 0;
		pthread_mutex_lock(&(data->eat_m));
		while (data->meal_n != -1 && i < data->n_philo
			&& ph[i].n_eat_ph >= data->meal_n)
			i++;
		if (i == data->n_philo)
		{
			data->have_ate = 1;
			pthread_mutex_unlock(&(data->eat_m));
			finish(data);
			pthread_mutex_lock(&(data->eat_m));
		}
		pthread_mutex_unlock(&(data->eat_m));
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

