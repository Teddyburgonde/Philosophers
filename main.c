/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/16 15:38:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdlib.h>


//! philosophers 5 800 200 200 7

/*
! 1. Initialisation mutex 
? ok.
! 2. Initialisation structure 
? ok.
! 3. Parsing 
? ok.
! 4. Crée une fonction pour un temps plus précis
? ok.
! 5. Crée une fonction pour voir si le philosophers est mort
? ok.
! 6. Routine sleep
? ok. 
! 7. Routine think
? ok.
! 8. Routine eat 
? ok.
! 9. test 
????????????????????????????
*/


void	*ft_routine(t_philo *philo)
{
	ft_taken_fork(philo);
	ft_eat(philo);
	ft_think(philo);
	//ft_sleep(philo);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_fork	*fork;
	t_data  data;
	
	philo = NULL;
	fork = NULL;
	if (initialization_data(&data, argv) != 0)
	{
		printf("Error\n");
		return (1);
	}
	if (initialization_mutex(&data) != 0)
	{
		free(data.forks);
		printf("Error\n");
		return (1);
	}
	philo = ft_calloc(data.number_of_philosophers, sizeof(t_philo));
	if (initialization_philo(philo, &data) != 0)
	{
		printf("Error\n");
		free(philo);
		free(data.forks);
		return (1);
	}
	if (incorrect_number_arguments(argc) == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argv) == 1)
		return (EXIT_FAILURE);	
	initialization_forks(philo);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("The philosopher is dead\n");
		pthread_mutex_unlock(&philo->data->printf_mutex);	
		return (EXIT_FAILURE);
	}
	if (pthread_create(&philo->thread_id, NULL, ft_routine(philo), NULL) != 0)
	{
		free(philo);
		free(data.forks);
		return (EXIT_FAILURE);
	}
	// if (pthread_join(philo->thread_id, NULL) != 0) {
    // 	printf("Error\n");
	// 	free(philo);
	// 	free(data.forks);
	// 	return (EXIT_FAILURE);
	// }
	//pthread_detach(philo->thread_id);
	pthread_mutex_destroy(&philo->data->printf_mutex);
	pthread_mutex_destroy(&philo->data->printf_mutex);
	pthread_mutex_destroy(&data.forks->fork_mutex);
	pthread_mutex_destroy(&data.is_dead_mutex);
	pthread_mutex_destroy(&data.philo_satiated_mutex);
	free(philo);
	free(data.forks);
}
