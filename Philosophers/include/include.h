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

typedef struct s_philo
{
	int		forks_nb;
}	t_philo;
/*			BASE			*/
//			ERROR
void	main_error(void (*f)(), t_philo *philo);
void	error_argument(void);
void	error_nb_philo(void);
//			FREE
void	main_free(t_philo *philo);
//			INIT
void	main_init(t_philo **philo);
/*			ARGUMENT		*/
void	main_argument(int ac, char **av, t_philo *philo);
void	forksnbr(int ac, char **av, t_philo *philo);
void	check_arg_int(int ac, char **av, t_philo *philo);
int		check_is_numbr(char *str);
int		check_int(char *str);
/*			UTILS			*/
int		ft_atoi(const char *str);
long	ft_atol(const char *str);

#endif
