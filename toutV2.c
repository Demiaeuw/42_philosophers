#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int				main(int ac, char **av);

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meal_needed;
	int				start_time;
	int				someone_died;
	pthread_mutex_t	someone_died_mutex;
	pthread_mutex_t	printex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				nb_meal;
	int				check_full;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
	struct timeval	last_meal;
}	t_philo;
//00
void			main_error(void (*f)(), t_data *data, t_philo *philo);
void			error_argument(void);
void			error_thread(void);
void			error_mutex(void);
//01
void			init_data(t_data *data, int ac, char **av);
void			initphilo(t_philo *p, pthread_mutex_t *f, int i, t_data *data);
pthread_mutex_t	*init_forks(int nb_philo);
t_philo			*init_philo(t_data *data);
int				init_struct(t_data **data, t_philo **philo, int ac, char **av);
//02
void			destroy_forks(t_philo *philo, int nb_philo, int *destro, int i);
void			free_philo(t_philo *philo, int nb_philo);
void			cleanup(t_data *data, t_philo *philo);
//03
int				create_thread(t_data *data, t_philo *philo);
int				check_death(t_philo *philo);
void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
//04
void			check_and_print(t_philo *philo, char *message);
void			eat_and_sleep(t_philo *philo);
void			*routine(void *arg);
//05
long			get_timestamp(void);
int				get_duration(t_data *data);
void			gestion_one_forks(t_philo *philo);
int				check_meals(t_philo *philo);
//10
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
//11
int				check_is_numbr(char *str);
int				check_int(char *str);
int				argument_checker(int ac, char **av);
//12
void			ft_putstr_printf(char *str, int *count);
void			ft_pr_pf(long long int nb, int base, int *count);
int				ft_printf(const char *str, ...);
void			print_struct(t_data *data);
//13
void			printmessage(t_philo *philo, char *str);
int				strc(char *s1, char *s2);

#endif





void	main_error(void (*f)(), t_data *data, t_philo *philo)
{
	f();
	cleanup(data, philo);
	exit(EXIT_FAILURE);
}

void	error_argument(void)
{
	ft_printf("\n\nError !\n\nArgument issue\n\n");
}

void	error_thread(void)
{
	ft_printf("\n\nError !\n\nThread issue\n\n");
}

void	error_mutex(void)
{
	ft_printf("\n\nError !\n\nMutex issue\n\n");
}



void	init_data(t_data *data, int ac, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meal_needed = ft_atoi(av[5]);
	else
		data->nb_meal_needed = -1;
	if (pthread_mutex_init(&data->printex, NULL) != 0
		|| pthread_mutex_init(&data->someone_died_mutex, NULL) != 0)
	{
		error_mutex();
		free(data);
		exit(EXIT_FAILURE);
	}
	data->someone_died = 0;
	data->start_time = get_timestamp();
}

void	initphilo(t_philo *p, pthread_mutex_t *f, int i, t_data *data)
{
	p->id = i + 1;
	p->nb_meal = 0;
	p->left_fork = &f[i];
	p->right_fork = &f[(i + 1) % data->nb_philo];
	p->data = data;
	gettimeofday(&p->last_meal, NULL);
	if (p->data->nb_meal_needed >= 0)
		p->check_full = 0;
	else
		p->check_full = -1;
}

pthread_mutex_t	*init_forks(int nb_philo)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			perror("pthread_mutex_init");
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&forks[i]);
			}
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_philo	*init_philo(t_data *data)
{
	int				i;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (NULL);
	forks = init_forks(data->nb_philo);
	if (!forks)
	{
		free(philo);
		return (NULL);
	}
	i = 0;
	while (i < data->nb_philo)
	{
		initphilo(&philo[i], forks, i, data);
		i++;
	}
	return (philo);
}

int	init_struct(t_data **data, t_philo **philo, int ac, char **av)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (-1);
	init_data(*data, ac, av);
	*philo = init_philo(*data);
	if (!*philo)
	{
		free(*data);
		return (-1);
	}
	return (0);
}


void	destroy_forks(t_philo *philo, int nb_philo, int *destro, int i)
{
	if (philo[i].left_fork && !destro[i])
	{
		pthread_mutex_destroy(philo[i].left_fork);
		destro[i] = 1;
	}
	if (philo[i].right_fork && !destro[(i + 1) % nb_philo])
	{
		pthread_mutex_destroy(philo[i].right_fork);
		destro[(i + 1) % nb_philo] = 1;
	}
}

void	free_philo(t_philo *philo, int nb_philo)
{
	int		i;
	int		*destroyed;

	destroyed = calloc(nb_philo, sizeof(int));
	if (!destroyed)
		return ;
	i = 0;
	if (philo)
	{
		while (i < nb_philo)
		{
			destroy_forks(philo, nb_philo, destroyed, i);
			i++;
		}
		if (nb_philo > 0 && philo[0].left_fork)
			free(philo[0].left_fork);
		free(philo);
	}
	free(destroyed);
}

void	cleanup(t_data *data, t_philo *philo)
{
	if (philo)
		free_philo(philo, data->nb_philo);
	if (data)
	{
		pthread_mutex_destroy(&data->printex);
		pthread_mutex_destroy(&data->someone_died_mutex);
		free(data);
	}
}


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

void	take_forks(t_philo *philo)
{
	// if (philo->id % 2 == 0)
	// 	usleep(1000);
	pthread_mutex_lock(philo->right_fork);
	printmessage(philo, "take right fork");
	pthread_mutex_lock(philo->left_fork);
	printmessage(philo, "take left fork");
	pthread_mutex_lock(&philo->data->someone_died_mutex);
	if (philo->data->someone_died == 0)
	{
		pthread_mutex_lock(&philo->data->printex);
		ft_printf("%d Philosophe n° %d had two forks.\n",
			get_duration(philo->data), philo->id);
			printf("\n\nphilo %d, nb de meal %d\n\n", philo->id, philo->nb_meal);
		pthread_mutex_unlock(&philo->data->printex);
	}
	pthread_mutex_unlock(&philo->data->someone_died_mutex);
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}


void	check_and_print(t_philo *philo, char *message)
{
	if (check_death(philo))
		return ;
	printmessage(philo, message);
}

void	eat_and_sleep(t_philo *philo)
{
	if (check_death(philo))
	{
		drop_forks(philo);
		return ;
	}
	printmessage(philo, "eating");
	gettimeofday(&philo->last_meal, NULL);
	usleep(1000 * philo->data->time_to_eat);
	philo->nb_meal++;	
	drop_forks(philo);
	if (check_meals(philo))
		return ;
	printmessage(philo, "sleeping");
	usleep(1000 * philo->data->time_to_sleep);
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
		if (philo->check_full == 1)
		{
			break ;
		}
		pthread_mutex_unlock(&philo->data->someone_died_mutex);
		if (check_death(philo))
			break ;
		check_and_print(philo, "thinking");
		take_forks(philo);
		eat_and_sleep(philo);
	}
	return (NULL);
}

long	get_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	get_duration(t_data *data)
{
	return (get_timestamp() - data->start_time);
}

void	gestion_one_forks(t_philo *philo)
{
	printmessage(philo, "thinking");
	pthread_mutex_lock(philo->right_fork);
	usleep(philo->data->time_to_die * 1000);
	pthread_mutex_unlock(philo->right_fork);
	printmessage(philo, "dead");
}

int	check_meals(t_philo *philo)
{
	if (philo->data->nb_meal_needed > 0
		&& philo->nb_meal == philo->data->nb_meal_needed)
	{
		printmessage(philo, "full");
		philo->check_full = 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	result = result * sign;
	return (result);
}

long	ft_atol(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}

int	check_is_numbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	check_int(char *str)
{
	int			i;
	int long	nbr;

	i = 0;
	while (str[i])
	{
		nbr = ft_atol(str);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int	argument_checker(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 5 || ac == 6)
	{
		while (i < ac)
		{
			if (check_is_numbr(av[i]) == -1)
				return (-1);
			if (check_int(av[i]) == -1)
				return (-1);
			i++;
		}
		return (0);
	}
	else
		return (-1);
}

void	ft_putstr_printf(char *str, int *count)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
}

void	ft_pr_pf(long long int nb, int base, int *count)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (nb < 0)
	{
		nb = -nb;
		*count += write (1, "-", 1);
	}
	if (nb >= base)
	{
		ft_pr_pf((nb / base), base, count);
	}
	*count += write(1, &tab[nb % base], 1);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr_printf(va_arg(arg, char *), &count);
			else if (str[i] == 'd')
				ft_pr_pf((long long int)va_arg(arg, int), 10, &count);
			else if (str[i] == 'x')
				ft_pr_pf((long long int)va_arg(arg, unsigned int), 16, &count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	return (va_end(arg), count);
}

void	print_struct(t_data *data)
{
	ft_printf("\n\n\n");
	ft_printf("\033[32mVoici la structure DATA\n\n\033[0m");
	ft_printf("\033[34mNb of Philosopher\033[0m : %d\n", data->nb_philo);
	ft_printf("\033[34mTime to die\033[0m : %d\n", data->time_to_die);
	ft_printf("\033[34mTime to eat\033[0m : %d\n", data->time_to_eat);
	ft_printf("\033[34mTime to sleep\033[0m : %d\n", data->time_to_sleep);
	ft_printf("\033[34m(optional) Nb"
		" of meal\033[0m : %d\n", data->nb_meal_needed);
	ft_printf("\n\n\n");
}

void	printmessage(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->someone_died_mutex);
	if (philo->data->someone_died == 0)
	{
		pthread_mutex_lock(&philo->data->printex);
		if (strcmp(message, "thinking") == 0)
			printf("%d Philosophe n° %d thinking.\n",
				get_duration(philo->data), philo->id);
		else if (strcmp(message, "eating") == 0)
			printf("%d Philosophe n° %d start eating.\n",
				get_duration(philo->data), philo->id);
		else if (strcmp(message, "sleeping") == 0 || strc(message, "bed") == 0)
			printf("%d Philosophe n° %d go to bed.\n",
				get_duration(philo->data), philo->id);
		else if (strcmp(message, "full") == 0)
			printf("%d Philosophe n° %d has eaten enough.\n",
				get_duration(philo->data), philo->id);
		else if (strcmp(message, "dead") == 0 || strc(message, "died") == 0)
			printf("%d Philosophe n° %d is dead.\n",
				get_duration(philo->data), philo->id);
		else
			printf("%d Philosophe n° %d %s.\n",
				get_duration(philo->data), philo->id, message);
		pthread_mutex_unlock(&philo->data->printex);
	}
	pthread_mutex_unlock(&philo->data->someone_died_mutex);
}

int	strc(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}


int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (argument_checker(ac, av) == -1)
	{
		error_argument();
		return (-1);
	}
	if (init_struct(&data, &philo, ac, av) == -1)
	{
		main_error(error_argument, data, philo);
		return (-1);
	}
	if (create_thread(data, philo) == -1)
	{
		main_error(error_thread, data, philo);
		return (-1);
	}
	cleanup(data, philo);
	return (0);
}

