/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:00:11 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/26 08:41:08 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialization_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].data = data;
		philo[i].id_philo = i + 1;
		//! nombre de repas mangé
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
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time_philo_must_eat = ft_atoi(argv[5]);
	data->is_dead = 0;
	data->philo_satiated = 0;
	data->start_time = get_current_time();
	return (0);
}

int	initialization_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_data) * data->number_of_philosophers);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks->fork_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&data->is_dead_mutex, NULL);
	pthread_mutex_init(&data->philo_satiated_mutex, NULL);
	pthread_mutex_init(&data->printf_mutex, NULL);
	return (0);
}

void initialization_forks(t_philo *philo)
{
	// ! la je dis que les forks ne sont pas disponibles.
	philo->left_fork->fork_is_available = 1;
	philo->right_fork->fork_is_available = 1;
}

int	verif_initialization(t_data *data, char **argv, t_philo **philo)
{
	if (initialization_data(data, argv) != 0)
	{
		printf("Error\n");
		return (1);
	}
	if (initialization_mutex(data) != 0)
	{
		free(data->forks);
		printf("Error\n");
		return (1);
	}
	*philo = ft_calloc(data->number_of_philosophers, sizeof(t_philo));
	if (initialization_philo(*philo, data) != 0)
	{
		printf("Error\n");
		free(*philo);
		free(data->forks);
		return (1);
	}
	initialization_forks(*philo);
	return (0);
}
