/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:09:55 by acabarba          #+#    #+#             */
/*   Updated: 2024/06/18 19:17:01 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
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
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	long	nbr;

	nbr = ft_atol(str); // Utilise ft_atol pour convertir la chaîne en long
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

int	check_arg_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac) // Parcourt tous les arguments sauf le nom du programme
	{
		if (!check_is_numbr(av[i]) || !check_int(av[i]))
			return (1); // Échec si l'un des arguments n'est pas un entier valide
		i++;
	}
	return (0); // Succès si tous les arguments sont des entiers valides
}

void	main_init(int ac, char **av, t_data *data, t_philo **philo)
{
	if ((ac != 5 && ac != 6) || check_arg_int(ac, av))
	{
		ft_putstr("\n\nError\nInvalid arguments\n");
		exit(1);
	}

	data->nb_philo = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_meal = ft_atoi(av[5]);
	else
		data->nb_meal = -1; // Valeur par défaut si l'argument est manquant
	data->start_time = 0;

	init_struct(data, philo);
	init_mutex(data);
}

void	init_struct(t_data *data, t_philo **philo)
{
	data->forks = (pthread_mutex_t *)malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		ft_putstr("\n\nError\nMemory allocation failed for forks\n");
		exit(1);
	}

	*philo = (t_philo *)malloc(data->nb_philo * sizeof(t_philo));
	if (!*philo)
	{
		ft_putstr("\n\nError\nMemory allocation failed for philosophers\n");
		exit(1);
	}

	for (int i = 0; i < data->nb_philo; i++)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].nb_eaten = 0;
		(*philo)[i].last_meal = 0; // Initialise à 0, sera mis à jour lors de l'exécution
		(*philo)[i].data = data;
	}
}

void	init_mutex(t_data *data)
{
	for (int i = 0; i < data->nb_philo; i++)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			ft_putstr("\n\nError\nMutex initialization failed\n");
			exit(1);
		}
	}

	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		ft_putstr("\n\nError\nMutex initialization failed\n");
		exit(1);
	}
}

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1)
	{
		// Philosopher is thinking
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("Philosopher %d is thinking\n", philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);

		// Philosopher is taking forks
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->nb_philo]);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("Philosopher %d has taken forks\n", philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);

		// Philosopher is eating
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("Philosopher %d is eating\n", philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
		usleep(philo->data->time_eat * 1000);

		// Philosopher has finished eating
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->nb_philo]);

		// Philosopher is sleeping
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("Philosopher %d is sleeping\n", philo->id);
		pthread_mutex_unlock(&philo->data->print_mutex);
		usleep(philo->data->time_sleep * 1000);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	// Vérification des arguments et initialisation des données
	main_init(ac, av, &data, &philo);

	// Initialisation des threads des philosophes
	for (int i = 0; i < data.nb_philo; i++)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
		{
			ft_putstr("\n\nError\nThread creation failed\n");
			exit(1);
		}
	}

	// Attente de la fin des threads
	for (int i = 0; i < data.nb_philo; i++)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			ft_putstr("\n\nError\nThread join failed\n");
			exit(1);
		}
	}

	// Nettoyage des ressources
	for (int i = 0; i < data.nb_philo; i++)
		pthread_mutex_destroy(&data.forks[i]);
	pthread_mutex_destroy(&data.print_mutex);
	free(data.forks);
	free(philo);

	return (0);
}
