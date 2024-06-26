/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/26 08:17:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_taken_fork(t_philo *philo)
{
	//! la je rends les forks disponibles.
	philo->left_fork->fork_is_available = 0;
	philo->right_fork->fork_is_available = 0;
	if (philo->data->is_dead == 1)
		return ;
	if (philo->left_fork->fork_is_available == 0)
	{
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("At {%li} the philosopher %d take the left forks \n",
			get_timestamp(philo->data->start_time), philo->id_philo);
		pthread_mutex_unlock(&philo->data->printf_mutex);
	}
	if (philo->right_fork->fork_is_available == 0)
	{
		pthread_mutex_lock(&philo->data->printf_mutex);
		printf("At {%li} the philosopher %d take the right fork \n",
			get_timestamp(philo->data->start_time), philo->id_philo);
		pthread_mutex_unlock(&philo->data->printf_mutex);
	}
	//! Fourchettes indisponible
	philo->left_fork->fork_is_available = 1;
	philo->right_fork->fork_is_available = 1;
}

void	ft_sleep(t_philo *philo)
{
	long int	start_to_sleep;

	if (philo->data->is_dead == 1)
		return ;
	start_to_sleep = get_timestamp(philo->data->start_time);
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%li} the philosopher %d falls asleep\n",
		start_to_sleep, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	while (ft_usleep(philo->data->start_time)
		- start_to_sleep < philo->data->time_to_sleep)
	{
		if (philo->data->is_dead == 1)
			return ;
		ft_usleep(500);
	}
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
	long int	start_to_eat;
	if (philo->data->is_dead == 1)
		return ;
	start_to_eat = get_timestamp(philo->data->start_time);
	// ! si la fourchette gauche est disponible
	// ! si la fourchette droite est disponible
	// pthread_mutex_lock(&philo->left_fork->fork_mutex);
	// printf("At {%li} the philosopher %d take the left fork\n", start_to_eat, philo->id_philo);
	// pthread_mutex_unlock(&philo->data->printf_mutex);
	
	// pthread_mutex_lock(&philo->right_fork->fork_mutex);
	// printf("At {%li} the philosopher %d take the right fork\n", start_to_eat, philo->id_philo);
	// pthread_mutex_unlock(&philo->data->printf_mutex);
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%li} the philosopher %d eating\n", start_to_eat, philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}

void	*ft_routine(t_philo *philo)
{
	ft_taken_fork(philo);
	ft_eat(philo);
	ft_think(philo);
	ft_sleep(philo);
	return (NULL);
}
