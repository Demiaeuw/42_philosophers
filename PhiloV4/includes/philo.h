/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:21:24 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 04:37:08 by acabarba         ###   ########.fr       */
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

typedef struct	s_philo
{
	int						id;
	pthread_t				thread;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	long					last_meal_time;
	int						meals_eaten;
	struct s_monitoring		*monitor;
}				t_philo;

typedef struct	s_monitoring
{
	int					num_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_meals_required;
	long				simulation_start;
	int					simulation_stop;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		meals_mutex;
	pthread_mutex_t		stop_mutex;
	pthread_t			monitor_thread;
	t_philo				*philosophers;
}				t_monitoring;

int		ft_atoi(const char *str);
long	get_current_time(long start_time);
int		get_duration(t_monitoring *monitor);
long	get_timestamp(void);
//00
int		init_forks(pthread_mutex_t *forks, int num);
int		init_monitoring(t_monitoring *monitor, int argc, char **argv);
int		init_philosophers(t_monitoring *monitor);
//01
void	free_monitoring(t_monitoring *monitor);
void	free_philosophers(t_monitoring *monitor);
void	shutdown_sim(t_monitoring *monitor);
//02
void	print_status(t_philo *philo, int status);
int		print_error(char *str);
//03
void	*monitoring_routine(void *arg);
//10
void	*philosopher_routine(void *arg);
//11
void	philosopher_eat(t_philo *philo);
void	philosopher_sleep(t_philo *philo);
void	philosopher_think(t_philo *philo);


#endif