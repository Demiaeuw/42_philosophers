/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:48:49 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/16 12:52:16 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

struct			s_data;

typedef struct s_fork
{
	int				right;
	int				left;
}		t_fork;

typedef struct s_philo
{
	int				philo_id;
	int				philo_nbeat;
	long long		time_philolastmeal;
	t_fork			fork;
	pthread_t		n_thread;
	struct s_data	*philo_data;
}			t_philo;

typedef struct s_data
{
	int				philo_nb;
	long int		tt_death;
	long int		tt_eat;
	long int		tt_sleep;
	int				tt_meal;
	long long		time_simstart;
	int				check_eat;
	int				is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_eat;
	t_philo			*philos;
}			t_data;

//00
void		print_status(t_data *data, int nb, char *msg);
long long	get_time(void);
void		ft_error(char *str);
int			ft_atoi(const char *str);
//01
void		check_arguments(int argc, char **argv);
void		check_eatdeath(int i, t_data *data, t_philo *ph);
void		is_dead(t_data *data, t_philo *ph);
int			check_value(int argc, char **argv);
//02
void		init(t_data *data);
void		init_data(int argc, char **argv, t_data *data);
void		init_mutex(t_data *data);
void		end_sim(t_data *data);
//03
void		*routine(void *routine);
void		eat_philo(t_philo *philo);
void		sleep_time(long long time, t_data *data);


#endif