/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:12:44 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/18 13:23:31 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_arguments(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		ft_error("Error, program needs 5 or 6 args");
	if (!check_value(ac, av))
		ft_error("Error, args are not digit");
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		ft_error("Error, args not positive");
	if (ft_atoi(av[1]) == 1)
	{
		printf("%4d 1 has taken fork\n", 1);
		usleep(ft_atoi(av[2]) * 1000);
		printf("%4d 1 is dead\n", (ft_atoi(av[2]) + 1));
		exit(0);
	}
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

int	check_value(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
