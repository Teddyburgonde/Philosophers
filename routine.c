/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/12 16:30:30 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void ft_sleep(t_philo *philo)
{
	long int start_to_sleep;
	if (philo->data->is_dead == 1)
		return;
	start_to_sleep = get_current_time();
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%lu} the philosopher %d falls asleep\n", start_to_sleep, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	while (ft_usleep(philo->data->start_time) - start_to_sleep < philo->data->time_to_sleep) 
	{
		if (philo->data->is_dead == 1)
			return ;
		ft_usleep(5000000);
	}
}

void ft_think(t_philo *philo)
{
	long int start_to_think;
	if (philo->data->is_dead == 1)
		return;
	start_to_think = get_current_time();
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%lu} the philosopher %d thinking\n", start_to_think, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}


void ft_eat(t_philo *philo)
{
	long int start_to_eat;
	if (philo->data->is_dead == 1)
		return;
	start_to_eat = get_current_time();
	// ! si la fourchette gauche est disponible
	// ! si la fourchette droite est disponible
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	printf("At {%lu} the philosopher %d take the left fork\n", start_to_eat, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	printf("At {%lu} the philosopher %d take the right fork\n", start_to_eat, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%lu} the philosopher %d eating\n", start_to_eat, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}