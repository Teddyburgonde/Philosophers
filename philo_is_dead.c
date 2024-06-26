/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:32:09 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/01 07:43:28 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philo_is_dead(t_philo *philo)
{
	if (philo->data->is_dead == 1)
	{
		print_message(philo, "dead");
		return (-1);
	}
	return (0);
}

int	is_philo_dead(t_philo *philo)
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
	//! Vérifie si le temps écoulé depuis le dernier repas dépasse 'time_to_die'
	//! time_to_die est le temps maximun qui philo peut passé sans manger.
	//! dans cette boucle le philo est 
	//! mort car le temps passé depuis son dernier repas
	//! est supperieur au temps maximal sans manger.
	if (current_time - philo->last_time_eaten > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		check_philo_is_dead(philo);
		return (1);
	}
	return (0);
}
