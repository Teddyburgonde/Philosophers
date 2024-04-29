/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/29 11:06:43 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// Créer un thread séparé pour chaque philosophe 
// afin de représenter leurs activités (réflexion, repas).

// penser, manger et dormir.

void	*ft_routine(void *arg)
{
	t_philo *philo;
	int	i;
	i = 0;
	
	philo = (t_philo *)arg;
	while (i < philo->t_data->number_of_philosophers)
	{
		philo[i].id_philo = i + 1;
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	pthread_t	philosopher;

	int		i;

	if (validate_arguments(argv) == 1)
		return (1);
	if (incorrect_number_arguments(argc) == 1)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	i = 0;
	pthread_create(&philosopher, NULL, ft_routine, (void*)philo);
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (philo == NULL)
		return (EXIT_FAILURE);
	while (i < data->number_of_philosophers)
	{
		initialize_philosopher(&philo[i], data, i);
		i++;
	}
}
