/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:24:26 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/26 08:27:21 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_thread_start_ft_routine(t_philo	*philo, t_data *data)
{
	int	i;
	int	check;

	i = 0;
	while (i < data->number_of_philosophers)
	{	
		philo[i].id_philo = i;
		//! un philo doit avoir son propre pthread car cela lui permet de faire des actions en simultaner (manger, dormir, penser)
		check = pthread_create(&philo->thread_id, NULL, (void *)ft_routine, &philo[i]);
		if (check != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	manage_thread(t_philo *philo, t_data *data)
{
	int	i;
	int	check;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		check = pthread_join(philo[i].thread_id, NULL);
		if (check != 0)
			return (-1);
		i++;
	}
	return (0);
}
