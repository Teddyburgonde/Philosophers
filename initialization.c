/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:00:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/07 19:46:47 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



t_philo	*initialization_philo(void)
{
	t_philo	*philo;

	philo = malloc( sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->id_philo = 0;
	philo->nb_fork = 0;
	philo->last_time_eaten = 0;
	philo->thread_id = 0;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	philo->data = NULL;
	return (philo);
}

// t_data	*initialization_data(void)
// {
// 	t_data *data;
	
// 	data = malloc(data->number_of_philosophers * sizeof(t_data));
// 	if (data == NULL)
// 		return (NULL);
// 	if (pthread_mutex_init(&data->printf_mutex, NULL) != 0 
// 		|| pthread_mutex_init(&data->is_dead_mutex, NULL) != 0)
// 	{
// 		free(data); 
// 		return (NULL);
// 	}
// 	data->start = 0;
// 	data->time_philosopher_takes_to_eat = 0;
// 	data->is_dead = 0;
// 	data->id_fork = 0;
// 	data->number_of_philosophers = 0;
// 	data->time_to_die = 0;
// 	data->time_to_eat = 0;
// 	data->time_to_sleep = 0;
// 	return (data);
// }
