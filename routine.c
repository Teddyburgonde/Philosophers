/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/06 23:23:23 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

   // Logique pour penser
        // ...

        // Logique pour prendre les fourchettes
        // ...

        // Logique pour manger
        // ...

        // Logique pour relâcher les fourchettes
        // ...

        // Logique pour dormir
        // ...


	// 	pthread_mutex_lock(&philo->data->is_dead_mutex);
	// if (philo->data->is_dead == 1)
	// {
	// 	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	// 	return (1);
#include "philosophers.h"
#include <pthread.h>

// un thread par philo
// chaque philo doit avoir une fourgette 
// une routine par philo 
// pthread_create chaque philosopher a un id et tu boucle sur le 
// phread_create

int	ft_routine(t_philo *philo)
{
	t_fork	*fork;


	// int right_fork = (philo_id + 1) % NUM_PHILOSOPHERS;
	//  usleep(rand() % 1000000);
	while (1)
	{
		pthread_mutex_lock(&philo->data->printf_mutex);
		if (philo->data->is_dead == 1)
		{
			pthread_mutex_unlock(&philo->data->printf_mutex);
			return (1);
		}
		printf("Philosophising is thinking\n");
		pthread_mutex_unlock(&philo->data->printf_mutex);
		pthread_mutex_lock(&philo->data->fork->fork_mutex);
		if (philo->left_fork->mutex_taken == 0 && philo->right_fork->mutex_taken == 0) // la fourchette gauche est libre 
		{
			printf("The philosopher takes both forks\n");
			printf("The philosopher is eating\n");
		}
		pthread_mutex_unlock(&philo->data->fork->fork_mutex);
		pthread_mutex_lock(&philo->data->fork->fork_mutex);
		if (philo->left_fork->mutex_taken == 1 && philo->right_fork->mutex_taken == 1)
		{
			printf("The philosopher puts down the forks\n");
		}
		pthread_mutex_unlock(&philo->data->fork->fork_mutex);
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("The philosopher sleeping\n");
		pthread_mutex_unlock(&philo->data->fork->fork_mutex);
	}
}