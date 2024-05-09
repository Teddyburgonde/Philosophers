/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/09 22:18:02 by tebandam         ###   ########.fr       */
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
}

// int	ft_routine_eat(t_philo *philo)
// {

// 	// int right_fork = (philo_id + 1) % NUM_PHILOSOPHERS;
// 	//  usleep(rand() % 1000000);
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philo->data->printf_mutex);
// 		if (philo->data->is_dead == 1)
// 		{
// 			pthread_mutex_unlock(&philo->data->printf_mutex);
// 			return (1);
// 		}
// 		printf("Philosophising is thinking\n");
// 		pthread_mutex_unlock(&philo->data->printf_mutex);
// 		pthread_mutex_lock(&philo->data->fork->fork_mutex);
// 		if (philo->left_fork->mutex_taken == 0 && philo->right_fork->mutex_taken == 0) // la fourchette gauche est libre 
// 		{
// 			printf("The philosopher takes both forks\n");
// 			printf("The philosopher is eating\n");
// 		}
// 		pthread_mutex_unlock(&philo->data->fork->fork_mutex);
// 		pthread_mutex_lock(&philo->data->fork->fork_mutex);
// 		if (philo->left_fork->mutex_taken == 1 && philo->right_fork->mutex_taken == 1)
// 		{
// 			printf("The philosopher puts down the forks\n");
// 		}
// 		pthread_mutex_unlock(&philo->data->fork->fork_mutex);
// 		pthread_mutex_lock(&philo->data->printf_mutex);
// 		printf("The philosopher sleeping\n");
// 		pthread_mutex_unlock(&philo->data->fork->fork_mutex);
// 	}
// }