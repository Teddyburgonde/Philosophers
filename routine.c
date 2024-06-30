/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/30 14:46:06 by tebandam         ###   ########.fr       */
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
	long int start_
	if (check_philo_is_dead(philo) == -1)
		return ;
	
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

int	check_philo_is_dead(t_philo *philo)
{
	if (philo->data->is_dead == 1)
	{
		print_message(philo, "dead");
		return (-1);
	}
	return (0);
}

void	eat(t_philo *philo)
{
	if (check_philo_is_dead(philo) == -1)
		return ;
	taken_fork(philo);
	if (philo->nb_forks == 2)
	{
		action_eat()
	}
	
}

void	*ft_routine(t_philo *philo)
{
	if (philo->id_philo % 2 == 0)
	{
		usleep(50);
	}
	taken_fork(philo);
	//ft_eat(philo);
	// ft_think(philo);
	// ft_sleep(philo);
	return (NULL);
}
