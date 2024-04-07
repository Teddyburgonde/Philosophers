/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/07 17:04:22 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

int	incorrect_number_arguments(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error\nNumber of arguments is wrong\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	validate_arguments(argv);
	incorrect_number_arguments(argc);
	t_philo	*philo;
	t_prog	*data;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (EXIT_FAILURE);
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].id_philo = i + 1;
		philo[i].data = data;
// ?????		philo[i].left_chopstick = &data->chopstick[i];
		
		i++;
	}
}
