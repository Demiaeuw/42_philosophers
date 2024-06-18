/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:10:53 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 19:17:44 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_data
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				nb_meal;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	long long		start_time;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				nb_eaten;
	long long		last_meal;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

void	ft_putstr(char *str);
int	ft_atoi(const char *str);
long	ft_atol(const char *str);
int	check_is_numbr(char *str);
int	check_int(char *str);
int	check_arg_int(int ac, char **av);
void	main_init(int ac, char **av, t_data *data, t_philo **philo);
void	init_struct(t_data *data, t_philo **philo);
void	init_mutex(t_data *data);
void	*routine(void *arg);
int	main(int ac, char **av);

#endif
