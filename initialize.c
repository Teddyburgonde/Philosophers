/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:18:25 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/29 09:46:27 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_philosopher(t_philo *philo, t_data *data, int index)
{
	philo[index].id_philo = index + 1;
	philo[index].t_data = data;
	if (philo[index].id_philo == data->number_of_philosophers)
		philo[index].left_chopstick = &data->chopstick[0];
	else
		philo[index].left_chopstick = &data->chopstick[index];
}
