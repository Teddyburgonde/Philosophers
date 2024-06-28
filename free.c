/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/28 09:22:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutex(t_philo *philo, t_data *data)
{
	// int	i;
	// i = 0;
	// while (i < data->number_of_philosophers)
	// {
	// 	free(philo);
	// 	i++;
	// }
	// free(data->forks);
	pthread_mutex_destroy(&philo->data->printf_mutex);
	pthread_mutex_destroy(&data->is_dead_mutex);
	pthread_mutex_destroy(&data->philo_satiated_mutex);
}
