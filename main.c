/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/14 15:20:16 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
