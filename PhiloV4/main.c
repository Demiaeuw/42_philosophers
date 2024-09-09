/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:14:08 by acabarba          #+#    #+#             */
/*   Updated: 2024/09/09 04:29:15 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_monitoring	monitor;

	// Vérification des arguments
	if (argc < 5 || argc > 6)
		return (print_error("Usage: ./philo num_philosophers time_to_die time_to_eat time_to_sleep [num_meals_required]"));

	// Initialisation du monitoring et des philosophes
	if (init_monitoring(&monitor, argc, argv) != 0)
		return (print_error("Error: Failed to initialize monitoring"));

	if (init_philosophers(&monitor) != 0)
	{
		shutdown_sim(&monitor); // Libération des ressources en cas d'erreur
		return (print_error("Error: Failed to initialize philosophers"));
	}

	// Attendre la fin de la simulation (les threads des philosophes et le monitoring)
	free_philosophers(&monitor); // Attend la fin de tous les threads

	// Libération des ressources
	free_monitoring(&monitor);

	return (0);
}
