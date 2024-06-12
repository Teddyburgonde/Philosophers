/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/12 10:02:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

//! philosophers 5 800 200 200 7

//number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_ea

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
! 6. Routine eat
? ok. 
! 7. Routine think
? ok.
! 8. Routine sleep
???????????????????????????

! 9. test 
????????????????????????????
*/

void	*ft_routine(t_philo *philo)
{
	ft_taken_fork(philo);
	ft_eat(philo);
	ft_think(philo);
	ft_sleep(philo);
	return (NULL);
}

int	verif_initialization(t_data *data, char **argv, t_philo **philo)
{
	if (initialization_data(data, argv) != 0)
	{
		printf("Error\n");
		return (1);
	}
	if (initialization_mutex(data) != 0)
	{
		free(data->forks);
		printf("Error\n");
		return (1);
	}
	*philo = ft_calloc(data->number_of_philosophers, sizeof(t_philo));
	if (initialization_philo(*philo, data) != 0)
	{
		printf("Error\n");
		free(*philo);
		free(data->forks);
		return (1);
	}
	initialization_forks(*philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	//t_fork	*fork;
	t_data  data;
	int		check;
	int		i;
	
	philo = NULL;
	//fork = NULL;
	check = 0;
	i = 0;
	if (incorrect_number_arguments(argc) == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argv) == 1)
		return (EXIT_FAILURE);
	if (verif_initialization(&data, argv, &philo) != 0)
		return (EXIT_FAILURE);
	if (check_philo_is_dead(philo) == 1)
		return (EXIT_FAILURE);
	while (i < data.number_of_philosophers)
	{	
		philo[i].id_philo = i;
		//! un philo doit avoir son propre pthread car cela lui permet de faire des actions en simultaner (manger, dormir, penser)
		check = pthread_create(&philo->thread_id, NULL, (void *)ft_routine, &philo[i]);
		if (check != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		check = pthread_join(philo[i].thread_id, NULL);
		if (check != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data.number_of_philosophers)
	{
		free(philo);
		i++;
	}
	free(data.forks);
	pthread_mutex_destroy(&philo->data->printf_mutex);
	pthread_mutex_destroy(&data.is_dead_mutex);
	pthread_mutex_destroy(&data.philo_satiated_mutex);
}
