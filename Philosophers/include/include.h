/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:15:33 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/12 11:49:43 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <limits.h>

int	main(int ac, char **av);

typedef struct s_data
{
	int		forks_nb;
	int		tt_d;
	int		tt_e;
	int		tt_s;
	int		nbreat;
	pthread_mutex_t *forks_mutex;
	pthread_mutex_t print_mutex;
	pthread_t *threads;
}	t_data;

typedef struct s_philo
{
	int		id_philo;
	t_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	
}	t_philo;
/*			BASE			*/
//			ERROR
void	main_error(void (*f)(), t_data *data, t_philo *philo);
void	error_argument(void);
void	error_nb_philo(void);
void	error_ttd(void);
void	error_tte(void);
void	error_tts(void);
void	error_nbreat(void);

//			FREE
void	main_free(t_data *data, t_philo *philo);

//			INIT
void	data_init(t_data **data);
void	philo_init(t_data **data, t_philo **philo);
void	mutex_init(t_data *data, t_philo *philo);

/*			ARGUMENT		*/
void	main_argument(int ac, char **av, t_data *data, t_philo *philo);
void	forksnbr(int ac, char **av, t_data *data, t_philo *philo);
void	t_t_d(int ac, char **av, t_data *data, t_philo *philo);
void	t_t_e(int ac, char **av, t_data *data, t_philo *philo);
void	t_t_s(int ac, char **av, t_data *data, t_philo *philo);
void	nbr_eat(int ac, char **av, t_data *data, t_philo *philo);

/*			THREAD			*/
void	init_thread(int ac, char **av, t_data **data, t_philo **philo);

/*			ROUTINE			*/
void	*philo_routine(void *arg, t_data *data);
/*			UTILS			*/
void	check_arg_int(int ac, char **av, t_data *data, int i, t_philo *philo);
int		check_is_numbr(char *str);
int		check_int(char *str);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	print_struct(t_data *data);
void	*ft_memset(void *s, int c, size_t n);

#endif
