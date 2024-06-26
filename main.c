/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/26 08:28:49 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//! philosophers 5 800 200 200 7

// number_of_philosophers
// time_to_die
// time_to_eat 
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]


int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data  data;
	int		check;
	int		i;
	
	philo = NULL;
	i = 0;
	if (incorrect_number_arguments(argc) == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argv) == 1)
		return (EXIT_FAILURE);
	if (verif_initialization(&data, argv, &philo) != 0)
		return (EXIT_FAILURE);
	if (check_philo_is_dead(philo) == 1)
		return (EXIT_FAILURE);
	check = create_thread_start_ft_routine(philo, &data);
	if (check != 0)
		return (EXIT_FAILURE);
	check = 0; //! je dois le remettre a 0 ou pas ?
	check = manage_thread(philo, &data);
	if (check != 0)
		return (EXIT_FAILURE);
	cleanup_ressources(philo, &data);
}
