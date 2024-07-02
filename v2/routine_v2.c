/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/02 18:58:29 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	try_to_take_fork(t_philo *philo, t_fork *fork, char *fork_str)
{
	pthread_mutex_lock(&fork->fork_mutex);
	if (fork->fork_is_available == 0)
	{
		printf_for_take_fork(philo, fork, fork_str);
		philo->nb_forks++;
	}
	pthread_mutex_unlock(&fork->fork_mutex);
}

void	take_forks(t_philo *philo)
{
	while (philo->nb_forks < 2)
	{
		if (check_philo_is_dead(philo) == 1)
			break ;
		try_to_take_fork(philo, philo->left_fork, "left");
		try_to_take_fork(philo, philo->right_fork, "right");
	}
}

void	print_mutex(t_philo *philo, char *to_print)
{
	pthread_mutex_lock(&philo->data->printf_mutex);
	printf("At {%li} the philosopher %d %s\n",
		get_timestamp(philo->data->start_time), philo->id_philo, to_print);
	pthread_mutex_unlock(&philo->data->printf_mutex);
}

void	do_action(t_philo * philo, char *action, int action_time, int takes_time)
{
	long int start;

	if (philo->data->is_dead == 1)
		return ;
	start = get_timestamp(philo->data->start_time);
	print_mutex(philo, action);
	while (takes_time && get_timestamp(philo->data->start_time)
		- start < action_time)
	{
		if (philo->data->is_dead == 1)
			return ;
		ft_usleep(500);
	}
}

void	ft_sleep(t_philo *philo)
{
	do_action(philo, "falls asleep", philo->data->time_to_sleep, 1);
}

void	ft_think(t_philo *philo)
{
	do_action(philo, "thinking", 0, 0);
}

void	ft_eat(t_philo *philo)
{
	if (philo->data->is_dead == 1)
		return ;
	if (philo->nb_forks == 2)
	{
		do_action(philo, "is eating", philo->data->time_to_eat, 1);
		philo->nb_forks = 0;
		philo->right_fork->fork_is_available = 0;
		philo->left_fork->fork_is_available = 0;
	}
}

void	*ft_routine(t_philo *philo)
{
	if (philo->id_philo % 2 == 0)
	{
		usleep(50);
	}
	take_forks(philo);
	//ft_eat(philo);
	// ft_think(philo);
	// ft_sleep(philo);
	return (NULL);
}
