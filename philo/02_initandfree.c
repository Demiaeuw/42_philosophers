/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_initandfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:47:59 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/10 23:19:09 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *data)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = data->philos;
	data->start = stock_time();
	while (i < data->n_philo)
	{
		pthread_create(&(ph[i].n_thread), NULL, routine, &(ph[i]));
		pthread_mutex_lock(&(data->eat_m));
		ph[i].last_eat_ph = stock_time();
		pthread_mutex_unlock(&(data->eat_m));
		i++;
	}
	is_dead(data, ph);
	finish(data);
}

void	set_data(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->have_ate = 0;
	if (argc == 6)
		data->meal_n = ft_atoi(argv[5]);
	else
		data->meal_n = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	init_mutex(data);
	init(data);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = data->n_philo;
	data->is_dead = 0;
	pthread_mutex_init(&(data->write_m), NULL);
	pthread_mutex_init(&(data->eat_m), NULL);
	while (--i >= 0)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philos[i].id_ph = i + 1;
		data->philos[i].n_eat_ph = 0;
		data->philos[i].fork.l = i;
		data->philos[i].fork.r = (i + 1) % data->n_philo;
		data->philos[i].last_eat_ph = 0;
		data->philos[i].data_ph = data;
	}
}


void	finish(t_data *data)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = data->philos;
	if (data->n_philo == 1)
		pthread_mutex_unlock(&(data->forks[ph[0].fork.l]));
	while (i < data->n_philo)
	{
		pthread_join(ph[i].n_thread, NULL);
		i++;
	}
	i = 0;
	while (++i < data->n_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->write_m));
	pthread_mutex_destroy(&(data->eat_m));
	free(data->forks);
	free(data->philos);
	exit (0);
}