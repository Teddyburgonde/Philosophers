/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:32:09 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/07 08:37:34 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_is_dead(t_philo *philo)
{
	if (philo->data->is_dead == 1)
	{
		print_message(philo, "died");
		return (-1);
	}
	return (0);
}

int	check_philo_is_dead(t_philo *philo)
{
	long int	current_time;

	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	current_time = get_timestamp(philo->data->start_time);
	if (current_time - philo->last_time_eaten >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		if (philo->data->is_dead == 1)
		{
			pthread_mutex_unlock(&philo->data->is_dead_mutex);
			return (1);
		}
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		philo_is_dead(philo);
		return (1);
	}
	return (0);
}
