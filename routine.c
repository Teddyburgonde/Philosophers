/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/09 09:37:41 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>


void	ft_sleep(t_philo *philo)
{
	long int	start_to_eat;
	
	start_to_eat = get_current_time();
	philo = malloc(sizeof(t_philo));
	if (philo->data->is_dead == 1)
		return ;
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%lu} the philosopher %d falls asleep\n", start_to_eat, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}

	
// ! Routine sleep 

// int	ft_sleep_routine(t_data *data)
// {
// 	pthread_mutex_lock(&data->printf_mutex);
// 	//! dans le printf il faut ajouter le time et id du philo
// 	//! 	printf("{%ld} | %d is sleeping\n", ((abso((philo->arg->time_start.tv_usec / 1000) - (philo->time_now.tv_usec / 1000))) +
// 	//! abso((philo->arg->time_start.tv_sec * 1000) - (philo->time_now.tv_sec * 1000))), 
// 	printf("Philosophising is sleeping\n");
// 	pthread_mutex_unlock(&data->printf_mutex);
// }


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