/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:08:51 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/10 19:35:25 by acabarba         ###   ########.fr       */
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

typedef struct s_philo
{
	int					id;
	int					meal_eaten;
	long				time_lastmeal;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	pthread_t			thread_philo;	
	struct s_monitoring	*monitoring;
		
}				t_philo;

typedef struct s_monitoring
{
	int					nb_philo;
	int					tt_death;
	int					tt_eat;
	int					tt_sleep;
	int					nb_meal;
	int					check_alleat;
	int					check_death;
	long				time_start;
	long				time_present;
	pthread_mutex_t		*mutex_thread;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_death;
	pthread_t			thread_monitor;
	t_philo				*philo;
}				t_monitoring;

//00
int			ft_atoi(const char *str);
long		get_timestamp(void);
int			check_argument(int ac);
//01
int			init_monitoring(t_monitoring *monitor, int ac, char **av);
int			init_mutexmonitoring(t_monitoring *monitor);
int			init_philosophers(t_monitoring *monitor);
int 		start_simulation(t_monitoring *monitor);
int			init_philosopher_forks(t_monitoring *monitor, int i);

//02
void		clean_monitoring(t_monitoring *monitor);
//03
void 		print_status(t_philo *philo, char *status);
//10
void		*philo_routine(void *arg);
void		take_forks(t_philo *philo);
void 		drop_forks(t_philo *philo);
void 		eat_philo(t_philo *philo);
//11
void 		sleep_philo(t_philo *philo);
void 		think_philo(t_philo *philo);
void		*monitor_routine(void *arg);

#endif