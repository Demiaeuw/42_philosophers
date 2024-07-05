/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:22:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/05 16:29:02 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	create_thread(t_data *data, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	struct timeval	current_time;
	long			time_diff;

	gettimeofday(&current_time, NULL);
	time_diff = (current_time.tv_sec - philo->last_meal.tv_sec) * 1000
					+ (current_time.tv_usec - philo->last_meal.tv_usec) / 1000;
	if (time_diff > philo->data->time_to_die)
	{
		printmessage(philo, "dead");
		pthread_mutex_lock(&philo->data->someone_died_mutex);
		philo->data->someone_died = 1;
		pthread_mutex_unlock(&philo->data->someone_died_mutex);
		return (1);
	}
	return (0);
}

void take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}

	pthread_mutex_lock(&philo->data->someone_died_mutex);
	if (philo->data->someone_died == 0)
	{
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("%d Philosophe n° %d has taken"
			"forks.\n", get_duration(philo->data), philo->id);
		pthread_mutex_unlock(&philo->data->printex);
	}
	pthread_mutex_unlock(&philo->data->someone_died_mutex);
}


void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->data->nb_philo == 1)
	{
		gestion_one_forks(philo);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->data->someone_died_mutex);
		if (philo->data->someone_died == 1)
		{
			pthread_mutex_unlock(&philo->data->someone_died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->someone_died_mutex);

		if (check_death(philo))
			break ;
		printmessage(philo, "thinking");
		take_forks(philo);
		if (check_death(philo))
		{
			drop_forks(philo);
			break ;
		}
		printmessage(philo, "eating");
		gettimeofday(&philo->last_meal, NULL);
		usleep(1000 * philo->data->time_to_eat);
		philo->nb_meal++;
		drop_forks(philo);
		if (check_meals(philo))
			break ;
		printmessage(philo, "sleeping");
		usleep(1000 * philo->data->time_to_sleep);
	}
	return (NULL);
}

