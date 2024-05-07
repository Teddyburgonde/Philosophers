/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:00:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/07 21:59:27 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialization_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philo[i].data = data; 
		data->philo[i].id_philo = i + 1;
		data->philo[i].last_time_eaten = data->is_dead;
		data->philo[i].eat_cont = 0;
		data->philo[i].eating = 0;
		data->philo[i].status = 0;
		pthread_mutex_init(&data->philo->lock, NULL);
		i++;
		//pthread_mutex_init(&data->philo[i].left_fork, NULL);
		//pthread_mutex_init(&data->philo[i].right_fork, NULL);
	}
}

// initialization data 
