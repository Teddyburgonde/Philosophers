/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:19:35 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/10 07:21:29 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philosopher_is_eating(t_philo *philo)
{
	long int	start_of_meal;
	long int	current_time;

	if (check_philo_is_dead(philo) == 1)
		return ;
	start_of_meal = get_timestamp(philo->data->start_time);
	current_time = get_timestamp(philo->data->start_time);
	print_message(philo, "eating");
	philo->nb_forks = 0;
	philo->nb_meals_eaten++;
	// si le temos courant - le temps qu'il a commencé a manger sont inferieur au temps qu'il peut rester sans manger
	// il mangera
	while (current_time - start_of_meal < philo->data->time_to_eat)
	{
		if (check_philo_is_dead(philo) == 1)
		{
			ft_usleep(500);
			return ;
		}
		// check le temps pour permettre que la while puisse s'arreter a un moment.
		current_time = get_timestamp(philo->data->start_time);
	}
}
