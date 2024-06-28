/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:24:26 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/28 15:40:02 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	manage_thread_start_ft_routine(t_philo	*philo, t_data *data)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread_id,NULL, (void *)ft_routine, &philo[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

