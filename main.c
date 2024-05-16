/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/16 13:48:13 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


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

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_fork	*fork;
	t_data  data;
	(void)argc;
	
	philo = NULL;
	fork = NULL;
	if (initialization_data(&data, argv) != 0)
	{
		printf("Error\n");
		return (1);
	}
	printf("OooooooooooooKKKKKKKKK\n");
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
	if (philo == NULL)
		return (1);
	if (incorrect_number_arguments(argc) == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argv) == 1)
		return (EXIT_FAILURE);	
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("The philosopher is dead\n");
		pthread_mutex_unlock(&philo->data->printf_mutex);	
		return (1);
	}
	initialization_forks(philo);
	while (1)
	{

		printf("SALUT JE PASSE ICI AUUUUUUUSISSIISISISISI\n");
		ft_taken_fork(philo);
		ft_eat(philo);
		ft_think(philo);
		ft_sleep(philo);
	}
	free(philo);
	free(data.forks);

	//!pthread_create(&thread1, NULL, ft_write_word, NULL);
	//! Si le philosophe n'est pas mort on peut faire la routine 
	
	//! pthread_mutex_destroy pour détruire les mutex.

}
