/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/27 16:21:36 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

//! philosophers 5 800 200 200 7

// number_of_philosophers
// time_to_die
// time_to_eat 
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;
	int		check;
	int		i;

	philo = NULL;
	i = 0;
	if (incorrect_number_arguments(argc) == -1)
		return (EXIT_FAILURE);
	if (check_is_number(argv) == -1)
		return (EXIT_FAILURE);
	if (initialization_data(&data, argv) == -1)
		return (EXIT_FAILURE);
	philo = ft_calloc(sizeof(t_philo), data.number_of_philosophers);
	data.forks = ft_calloc(sizeof(t_fork), data.number_of_philosophers);
	if (!philo || !data.forks)
		return (-1);
	check = create_thread_start_ft_routine(philo, &data);
	if (check != 0)
	{
		free(philo);
		free(data.forks);
		return (EXIT_FAILURE);
	}
	// manage_thread(philo, &data);
	free(philo);
	free(data.forks);
	// cleanup_ressources(philo, &data);
}
