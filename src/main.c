/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/07 08:13:18 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;
	int		check;

	philo = NULL;
	check = 0;
	if (incorrect_number_arguments(argc) == -1 || check_is_number(argv) == -1
		|| check_number_size(argc, argv) == -1)
		return (-1);
	if (initialization_data(&data, argv) == -1)
		return (-1);
	philo = ft_calloc(sizeof(t_philo), data.number_of_philosophers);
	data.forks = ft_calloc(sizeof(t_fork), data.number_of_philosophers);
	if (!philo || !data.forks)
		return (-1);
	if (initialization_mutex(&data) == -1
		|| initialization_philo(philo, &data) == -1)
		return (-1);
	if (manage_thread_start_ft_routine(philo, &data) == -1)
		return (-1);
	destroy_all_mutex(philo, &data);
	free(philo);
	free(data.forks);
	return (0);
}
