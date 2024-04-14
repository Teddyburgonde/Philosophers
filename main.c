/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/14 15:04:17 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <stdio.h>

void	initialize_philosopher(t_philo *philo, t_prog *data, int index)
{
	philo[index].id_philo = index + 1;
	philo[index].data = data;
	philo[index].left_chopstick = &data->chopstick[index];
	if (philo[index].id_philo == data->number_of_philosophers)
		philo[index].left_chopstick = &data->chopstick[0];
	else
		philo[index].left_chopstick = &data->chopstick[index + 1];
	index++;
}

int	main(int argc, char **argv)
{
	t_prog	*data;
	t_philo	*philo;
	int		i;

	if (validate_arguments(argv) == 1)
		return (1);
	if (incorrect_number_arguments(argc) == 1)
		return (1);
	data = malloc(sizeof(t_prog));
	if (!data)
		return (1);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	i = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (philo == NULL)
		return (EXIT_FAILURE);
	while (i < data->number_of_philosophers)
	{
		initialize_philosopher(&philo[i], data, i);
		i++;
	}
}
