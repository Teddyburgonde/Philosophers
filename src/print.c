/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:08:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/06 22:12:31 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <string.h>

void	printf_for_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (!check_philo_is_dead(philo))
		printf("%li %d has taken a fork\n",
			get_timestamp(philo->data->start_time), philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	fork->fork_is_available = 1;
}

void	print_message(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (strncmp(state, "died", 4) != 0 && !check_philo_is_dead(philo)) 
		printf("%li %d is %s\n",
			get_timestamp(philo->data->start_time), philo->id_philo, state);
	else
	{
		printf("%li %d %s\n",
			get_timestamp(philo->data->start_time), philo->id_philo, state);
	}
	pthread_mutex_unlock(&philo->data->printf_mutex);
}