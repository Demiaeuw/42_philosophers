/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:48:49 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/10 23:19:09 by acabarba         ###   ########.fr       */
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
	int	r;
	int	l;
}		t_fork;

typedef struct s_philo
{
	t_fork			fork;
	int				id_ph;
	pthread_t		n_thread;
	struct s_data	*data_ph;
	int				n_eat_ph;
	long long		last_eat_ph;
}			t_philo;

typedef struct s_data
{
	pthread_mutex_t	eat_m;
	long long		start;
	long int		t_die;
	long int		t_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_m;
	t_philo			*philos;
	int				is_dead;
	int				n_philo;
	int				have_ate;
	int				meal_n;
	long int		t_sleep;
}			t_data;

void		check_arguments(int argc, char **argv);
int			ft_atoi(const char *str);
void		init_mutex(t_data *data);
void		ft_error(char *str);
void		init(t_data *data);
void		eat_philo(t_philo *philo);
void		finish(t_data *data);
long long	stock_time(void);
void		*routine(void *routine);
void		is_dead(t_data *data, t_philo *ph);
void		sleep_time(long long time, t_data *data);
void		print_action(t_data *data, int nb, char *msg);
int			check_value(int argc, char **argv);
void		set_data(int argc, char **argv, t_data *data);


#endif