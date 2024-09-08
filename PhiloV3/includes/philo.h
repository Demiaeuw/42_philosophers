/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:05:29 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/08 19:22:09 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal;
	int				start_time;
	int				diecheck;
	pthread_mutex_t	*diecheck_m;
	pthread_mutex_t	*printex;
}	t_data;

typedef struct s_philo
{
	int				id;
	bool			meallimit;
	int				mealtaking;
	int				mealfull;
	struct timeval	mealtimer;
	pthread_t		thread;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	*left_f;
	t_data			*data;
}	t_philo;


int		ft_atoi(const char *str);
long	get_current_time(long start_time);
//00
int		check_arguments(int ac);
int		init_data(int ac, char **av, t_data *data);
int		init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks);
//01
void	free_data(t_data *data, pthread_mutex_t *forks);
void	free_philos(t_philo *philos);
void	cleanup_simulation(t_philo *philos, t_data *data,
			pthread_mutex_t *forks);
//02
void	print_status(t_philo *philo, int index);
int		get_duration(t_data *data);
long	get_timestamp(void);
//10
int		start_simulation(t_philo *philos, t_data *data);
void	*ft_routine(void *arg);
//11
void	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
void	eat_action(t_philo *philo);
void	eat(t_philo *philo);
void	sleeping(t_philo *philo);
//12
void	think(t_philo *philo);
int		death(t_philo *philo);
int		check_death(t_philo *philo);

#endif