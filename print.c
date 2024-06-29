/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:08:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/29 06:11:41 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printf_for_take_fork(t_philo *philo, t_fork *fork, int is_left_fork)
{
	if (is_left_fork)
	{
		printf("At {%li} the philosopher %d take the left forks \n",
			get_timestamp(philo->data->start_time), philo->id_philo);
	}
	else
	{
		printf("At {%li} the philosopher %d take the right forks \n",
			get_timestamp(philo->data->start_time), philo->id_philo);
	}
	fork->fork_is_available = 1;
}
