/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/02 19:22:34 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	while (philo->nb_forks < 2)
	{
		if (check_philo_is_dead(philo) == 1)
			break ;
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		if (philo->left_fork->fork_is_available == 0)
		{
			printf_for_take_fork(philo, philo->left_fork, 1);
			philo->nb_forks++;
		}
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		if (philo->right_fork->fork_is_available == 0)
		{
			printf_for_take_fork(philo, philo->right_fork, 0);
			philo->nb_forks++;
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	}
}

void	eat(t_philo *philo)
{
	long int start_of_meal;

	if (check_philo_is_dead(philo) == -1)
		return ;
	philosopher_is_eating(philo);
	check_and_update_satiety_of_philosopher(philo);
	start_of_meal = get_timestamp(philo->data->start_time);
	make_forks_unavailable(philo);
}

void	*ft_routine(t_philo *philo)
{
	
	if (philo->id_philo % 2 == 0)
	{
		usleep(500);
	}
	while (1)
	{
		take_forks(philo);
		eat(philo);
	}
	// ft_sleep(philo);
	// ft_think(philo);
	return (NULL);
}

// void	ft_sleep(t_philo *philo)
// {
// 	long int	start_to_sleep;

// 	if (philo->data->is_dead == 1)
// 		return ;
// 	start_to_sleep = get_timestamp(philo->data->start_time);
// 	pthread_mutex_lock(&philo->data->printf_mutex);
// 	printf("At {%li} the philosopher %d falls asleep\n",
// 		get_timestamp(philo->data->start_time), philo->id_philo);
// 	pthread_mutex_unlock(&philo->data->printf_mutex);
// 	while (get_timestamp(philo->data->start_time)
// 		- start_to_sleep < philo->data->time_to_sleep)
// 	{
// 		if (philo->data->is_dead == 1)
// 			return ;
// 		ft_usleep(500);
// 	}
// }

// void	ft_think(t_philo *philo)
// {
// 	long int	start_to_think;

// 	if (philo->data->is_dead == 1)
// 		return ;
// 	start_to_think = get_timestamp(philo->data->start_time);
// 	pthread_mutex_lock(&philo->data->printf_mutex);
// 	printf("At {%li} the philosopher %d thinking\n",
// 		start_to_think, philo->id_philo);
// 	pthread_mutex_unlock(&philo->data->printf_mutex);
// }
