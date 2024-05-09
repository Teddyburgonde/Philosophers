/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/09 22:26:20 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//! philosophers 5 800 200 200 7

/*
! 1. Initialisation structure 
? ok.
! 2. Parsing 
? ok.
! 3. Crée une fonction pour un temps plus précis
? ok.
! 4. Crée une fonction pour voir si le philosophers est mort
? ok.
! 4. Routine sleep

! 5. Routine think
? ok.
! 6. Routine eat 
! 7. test 
*/


int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data data;
	
	philo = NULL;
	if (incorrect_number_arguments(argc) == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argv) == 1)
		return (EXIT_FAILURE);
	initialization_data(&data, argv);
	philo = ft_calloc(data.number_of_philosophers, sizeof(t_philo));
	if (philo == NULL)
		return (1);
	data.forks = ft_calloc(data.number_of_philosophers, sizeof(t_fork));	
	if (data.forks == NULL)
		return (1);
	if (initialization_philo(philo, &data) != 0)
	{
		printf("Error\n");
		free(philo);
		free(data.forks);
		return (1);
	}
	ft_sleep(philo);
	
	free(philo);
	free(data.forks);

	//! Si le philosophe n'est pas mort on peut faire la routine 
	
	//! pthread_mutex_destroy pour détruire les mutex.
}	