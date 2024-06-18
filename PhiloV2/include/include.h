/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:31:02 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 18:44:16 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <unistd.h>
# include <stdarg.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_data
{
	int		nb_philo;				//Nombre de philosophes.
	int		time_death;				//Temps (en millisecondes) avant qu'un philosophe meurt s'il n'a pas mangé.
	int		time_eat;				//Temps (en millisecondes) qu'un philosophe met à manger.
	int		time_sleep;				//Temps (en millisecondes) qu'un philosophe met à dormir.
	int		nb_meal;				//Nombre de fois qu'un philosophe doit manger (optionnel).
	pthread_mutex_t	*forks;			//Tableau de mutex pour protéger les fourchettes.
	pthread_mutex_t	print_mutex;	//Mutex de protection pour les prints
	long long start_time;			//Temps de départ de la simulation.
}	t_data;

typedef struct s_philo
{
	int		id;					//Numero du Philosophe
	int		nb_eaten;			//Nombre de repas pris
	long long	last_meal;		//Temps depuis le dernier repas(debut du repas)
	t_data	*data;				//pointeur vers la donné global 
	pthread_t	thread;			//Thread du Philosophe
}	t_philo;

int		main(int ac, char **av);
void	main_init(int ac, char **av, t_data *data, t_philo *philo);
void	init_struct(t_data *data, t_philo **philo);
void	init_mutex(t_data *data, t_philo *philo);
void	main_free(t_data *data, t_philo *philo);
void	ft_putstr(char *str, int *count);
void	ft_putnbrbase(long long int nb, int base, int *count);
int		ft_printf(const char *str, ... );
int		check_arg_int(int ac, char **av);
int		check_is_numbr(char *str);
int		check_int(char *str);
long	ft_atol(const char *str);

#endif