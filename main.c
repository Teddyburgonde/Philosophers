/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/02 18:57:29 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//! philosophers 5 800 200 200 7
// number_of_philosophers
// time_to_die
// time_to_eat 
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]


//! Error 
//! change la logique des return lorsqu'un philo meurt, par pitie, actuellement
// tu n'as aucun moyen de savoir si une fonction a return car un philo est mort.

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;
	int		check;

	philo = NULL;
	check = 0;
	if (incorrect_number_arguments(argc) == -1 || check_is_number(argv) == -1)
		return (-1);
	if (initialization_data(&data, argv) == -1)
		return (-1);
	philo = ft_calloc(sizeof(t_philo), data.number_of_philosophers);
	data.forks = ft_calloc(sizeof(t_fork), data.number_of_philosophers);
	if (!philo || !data.forks)
		return (-1);
	if (initialization_mutex(&data, data.number_of_philosophers) == -1
		|| initialization_philo(philo, &data) == -1)
		return (-1);
	//! No leak, no conditional jump, everything's fine ok 😊
	if (manage_thread_start_ft_routine(philo, &data) == -1)
		return (-1);
	free(philo);
	free(data.forks);
	//destroy_all_mutex(philo, &data);
	return (0);
}
