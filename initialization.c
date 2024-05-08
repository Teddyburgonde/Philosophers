/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:00:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/08 20:19:08 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	initialization_philo(t_data *data)
{
	int	i;

	i = 0;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return ;
	while (i < data->number_of_philosophers)
	{
		data->philo[i].data = data; 
		data->philo[i].id_philo = i + 1;
		data->philo[i].last_time_eaten = data->is_dead;
		data->philo[i].eat_cont = 0;
		data->philo[i].eating = 0;
		data->philo[i].status = 0;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		// pthread_mutex_init(&data->philo[i].left_fork, NULL);
		// pthread_mutex_init(&data->philo[i].right_fork, NULL);
		i++;
	}
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
