/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:18:39 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/27 15:43:07 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	init_data(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meal_needed = ft_atoi(av[5]);
	else
		data->nb_meal_needed = -1;
	if (pthread_mutex_init(&data->printex, NULL) != 0)
	{
		error_mutex();
		free(data);
		exit(EXIT_FAILURE);
	}
	data->someone_died = 0;
}

void	initphilo(t_philo *p, pthread_mutex_t *f, int i, t_data *data)
{
	p->id = i + 1;
	p->nb_meal = 0;
	p->left_fork = &f[i];
	p->right_fork = &f[(i + 1) % data->nb_philo];
	p->print = NULL;
	p->data = data;
	gettimeofday(&p->last_meal, NULL);
}

pthread_mutex_t	*init_forks(int nb_philo)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*init_philo(t_data *data)
{
	int				i;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (NULL);
	forks = init_forks(data->nb_philo);
	if (!forks)
	{
		free(philo);
		return (NULL);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		initphilo(&philo[i], forks, i, data);
		i++;
	}
	return (philo);
}

int	init_struct(t_data **data, t_philo **philo, int ac, char **av)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (-1);
	init_data(*data, ac, av);
	*philo = init_philo(*data);
	if (!*philo)
	{
		free(*data);
		return (-1);
	}
	return (0);
}
