/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/01 16:00:07 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	taken_fork(t_philo *philo)
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

void	philosopher_is_eating(t_philo *philo)
{
	long int start_of_meal;
	long int	current_time;

	if (check_philo_is_dead(philo) == -1)
		return ;
	start_of_meal = get_timestamp(philo->data->start_time);
	current_time = get_timestamp(philo->data->start_time);
	print_message(philo, "eating");
	philo->nb_forks = 0;
	philo->nb_meals_eaten++;
	while (current_time - start_of_meal < philo->data->time_to_eat)
	{
		//printf("start_of_meal : %ld current_time : %ld time_to_eat : %d\n", start_of_meal, current_time, philo->data->time_to_eat);
		
		if (check_philo_is_dead(philo) == -1)
		{
			usleep(500);
			return ;
		}
		current_time = get_timestamp(philo->data->start_time);
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
	// mettre une boucle
	if (philo->id_philo % 2 == 0)
	{
		usleep(500);
	}
	//! take_forks par pitie et je t'en supplie
	//! change la logique des return lorsqu'un philo meurt, par pitie, actuellement tu n'as aucun moyen de savoir si une fonction a return car un philo est mort.
	
	taken_fork(philo);
	eat(philo);
	// ft_think(philo);
	// ft_sleep(philo);
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
