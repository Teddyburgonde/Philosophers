/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:32:09 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/13 07:01:36 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

// savoir si il est mort 


// int	philo_dead(t_philo *philo)
// {
// 	long int	timestamp;

// 	pthread_mutex_lock(&philo->data->is_dead_mutex);
// 	if (philo->data->is_dead)
// 	{
// 		pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 	timestamp = get_timestamp(philo->data->start);
// 	if ((timestamp - philo->last_time_eaten) > philo->data->time_to_die)
// 	{
// 		pthread_mutex_lock(&philo->data->is_dead_mutex);
// 		philo->data->is_dead = 1;
// 		pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 		print_death(philo);
// 		return (1);
// 	}
// 	return (0);
// }


// Elle vérifie ensuite si le temps écoulé depuis la dernière fois que le philosophe a mangé est supérieur 
// au temps qu'il peut survivre sans manger (`time_to_die`). Si c'est le cas, la fonction verrouille à nouveau le mutex,
// marque le philosophe comme mort (`is_dead` est mis à 1), déverrouille le mutex, imprime un message de décès et retourne 1.

// Si le philosophe n'est pas mort et que le temps écoulé depuis la dernière fois qu'il a mangé
// n'est pas supérieur au temps qu'il peut survivre sans manger, la fonction retourne simplement 0.

// En résumé, cette fonction vérifie si un philosophe est mort, soit parce que le champ 
//`is_dead` est vrai, soit parce que le philosophe n'a pas mangé dans le délai imparti. La fonction utilise un mutex pour garantir la sécurité des threads lors de l'accès au champ `is_dead`.



int	is_philo_dead(t_philo *philo)
{	
	long int current_time;

	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	current_time = get_current_time();
	if (current_time - philo->last_time_eaten > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->is_dead_mutex);
		philo->data->is_dead = 1;
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("The philosopher is dead\n");
		pthread_mutex_unlock(&philo->data->printf_mutex);
		return (1);
	}
	return (0);
}

// int	philo_dead(t_philo *philo)
// {
// 	long int	timestamp;

// 	pthread_mutex_lock(&philo->data->is_dead_mutex);
// 	if (philo->data->is_dead)
// 	{
// 		pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 	timestamp = get_timestamp(philo->data->start);
// 	if ((timestamp - philo->last_time_eaten) > philo->data->time_to_die)
// 	{
// 		pthread_mutex_lock(&philo->data->is_dead_mutex);
// 		philo->data->is_dead = 1;
// 		pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 		print_death(philo);
// 		return (1);
// 	}
// 	return (0);
// }