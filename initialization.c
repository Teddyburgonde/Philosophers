/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:00:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/29 06:15:20 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialization_philo(t_philo *philo, t_data *data)
{
	int	i;

	if (!philo || !data || !data->forks)
		return (-1);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].data = data;
		philo[i].id_philo = i + 1;
		philo[i].nb_meals_eaten = 0;
		philo[i].nb_forks = 0;
		philo[i].left_fork = &data->forks[i];
		// ! si c'est le dernier , sa sera la fourchette de gauche du premier
		// ! sinon c'est la fourchette de gauche du philo a ta droite 
		if (philo[i].id_philo == data->number_of_philosophers)
			philo[i].right_fork = &data->forks[0];
		else
			philo[i].right_fork = &data->forks[i + 1];
		i++;
	}
	return (0);
}

int	initialization_data(t_data *data, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers > 200 || data->number_of_philosophers <= 0)
	{
		ft_putstr_fd("Error\nYou can't have more than 200 philosophers!\n", 2);
		return (-1);
	}
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die <= 0)
	{
		ft_putstr_fd("Error\nTime too short for time to die!\n", 2);
		return (-1);
	}
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time_philo_must_eat = ft_atoi(argv[5]);
	data->is_dead = 0;
	data->philo_satiated = 0;
	data->start_time = get_current_time();
	if (data->start_time <= 0)
	{
		ft_putstr_fd("Error\nTime too short for start_time!\n", 2);
		return (-1);
	}
	return (0);
}

int	initialization_mutex(t_data *data, int nb_philo)
{
	int	i;
	int	check;

	i = 0;
	while (i < nb_philo)
	{
		check = pthread_mutex_init(&data->forks->fork_mutex, NULL);
		if (check != 0)
			return (-1);
		i++;
	}
	check = pthread_mutex_init(&data->is_dead_mutex, NULL);
	if (check != 0)
		return (-1);
	check = pthread_mutex_init(&data->philo_satiated_mutex, NULL);
	if (check != 0)
		return (-1);
	check = pthread_mutex_init(&data->printf_mutex, NULL);
	if (check != 0)
		return (-1);
	return (0);
}
