/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:10:29 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/23 19:33:23 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

int		main(int ac, char **av);

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal_needed;
	pthread_mutex_t	printex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				nb_meal;
	pthread_t		thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print;
	t_data			*data;
}	t_philo;
//00
void	main_error(void (*f)(), t_data *data, t_philo *philo);
void	error_argument(void);
void	error_thread(void);
void	error_mutex(void);
//01
void	init_data(t_data *data, int ac, char **av);
t_philo	*init_philo(t_data *data);
int		init_struct(t_data **data, t_philo **philo, int ac, char **av);
//02
void	free_philo(t_philo *philo, int nb_philo);
void	cleanup(t_data *data, t_philo *philo);
//03
int		create_thread(t_data *data, t_philo *philo);
void	*routine(void *arg);
//10
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
//11
int		check_is_numbr(char *str);
int		check_int(char *str);
int		argument_checker(int ac, char **av);
//12
void	ft_putstr_printf(char *str, int *count);
void	ft_pr_pf(long long int nb, int base, int *count);
int		ft_printf(const char *str, ...);

#endif