/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/08 20:19:58 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data *data;

	data = NULL;
	philo = NULL;
	if (incorrect_number_arguments(argc) == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argv) == 1)
		return (EXIT_FAILURE);
	initialization_philo(data);
	if (philo == NULL)
		return (EXIT_FAILURE);
	ft_sleep(philo);
	// data = initialization_data() ;
	// if (data == NULL)
	// 	return (EXIT_FAILURE);
	

	//! Si le philosophe n'est pas mort on peut faire la routine 
	
	
	
	//! pthread_mutex_destroy pour détruire les mutex.
}	