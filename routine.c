/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/28 15:41:48 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_taken_fork(t_philo *philo)
{
	// //! la je rends les forks disponibles.
	// philo->left_fork->fork_is_available = 0;
	// philo->right_fork->fork_is_available = 0;
	while (philo->nb_forks < 2)
	{
		if (philo->data->is_dead == 1)
		{
			pthread_mutex_lock(&philo->data->printf_mutex);
			printf("The philosopher is dead\n");
			pthread_mutex_unlock(&philo->data->printf_mutex);
			break;
		}
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		if (philo->left_fork->fork_is_available == 0)
		{
			printf("At {%li} the philosopher %d take the left forks \n",
				get_timestamp(philo->data->start_time), philo->id_philo);
			philo->left_fork->fork_is_available = 1;
			philo->nb_forks++;
		}
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		if (philo->right_fork->fork_is_available == 0)
		{
			printf("At {%li} the philosopher %d take the right forks \n",
				get_timestamp(philo->data->start_time), philo->id_philo);
			philo->right_fork->fork_is_available = 1;
			philo->nb_forks++;
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	}
}

void	ft_sleep(t_philo *philo)
{
	long int	start_to_sleep;

	if (philo->data->is_dead == 1)
		return ;
	start_to_sleep = get_timestamp(philo->data->start_time);
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%li} the philosopher %d falls asleep\n",
		get_timestamp(philo->data->start_time), philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	while (get_timestamp(philo->data->start_time)
		- start_to_sleep < philo->data->time_to_sleep)
	{
		if (philo->data->is_dead == 1)
			return ;
		ft_usleep(500);
	}
	//! utiliser ma fonction ou la vrai pour ft_usleep
}

void	ft_think(t_philo *philo)
{
	long int	start_to_think;

	if (philo->data->is_dead == 1)
		return ;
	start_to_think = get_timestamp(philo->data->start_time);
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%li} the philosopher %d thinking\n",
		start_to_think, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}

void	ft_eat(t_philo *philo)
{
	//long int	start_to_eat;

	if (philo->data->is_dead == 1)
		return ;
	
	if (philo->nb_forks == 2) {
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("At {%li} the philosopher %d is eating\n",
		get_timestamp(philo->data->start_time), philo->id_philo);
		pthread_mutex_unlock(&philo->data->printf_mutex);
		usleep(philo->data->time_to_eat);
		philo->nb_forks = 0;
		philo->right_fork->fork_is_available = 0;
		philo->left_fork->fork_is_available = 0;
	}
}

void	*ft_routine(t_philo *philo)
{
	if (philo->id_philo % 2 == 0) {
		usleep(500);
	}
	ft_taken_fork(philo);
	ft_eat(philo);
	// ft_think(philo);
	// ft_sleep(philo);
	return (NULL);
}
