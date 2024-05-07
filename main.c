/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/05 23:03:31 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// penser, manger et dormir.

// void	*ft_routine(void *arg)
// {
// 	t_philo *philo;
// 	int	i;
// 	t_chopstick *left_chopstick; 
// 	t_chopstick *right_chopstick;
// 	t_chopstick *chopsticks;

// 	chopsticks = malloc(sizeof(t_chopstick));
// 	left_chopstick = malloc(sizeof(t_chopstick));
// 	right_chopstick = malloc(sizeof(t_chopstick));
// 	i = 0;
// 	init_mutex_philosophers(chopsticks);
// 	if (!chopsticks)
// 		return (NULL);
// 	philo = (t_philo *)arg;
// 	while (i < philo->t_data->number_of_philosophers)
// 	{
// 		philo[i].id_philo = i + 1;
// 		i++;
// 	}
// 	while(1)
// 	{
// 		printf("Philosopher thinking.\n");
// 		printf("Philosopher waits before taking the chopsticks.\n");
// 		if ((philo->left_chopstick->is_chopstick_used && philo->right_chopstick->is_chopstick_used) == 0)
// 		{
// 			pthread_mutex_lock(chopsticks->mutex_philosopher);
// 			printf("Philosopher eating.\n");
// 			pthread_mutex_unlock(chopsticks->mutex_philosopher);
// 		}
// 		else
// 		{
// 			printf("Philosopher thinking.\n");
// 			printf("Philosopher waits before taking the chopsticks.\n");
// 		}
// 		printf("Philosopher sleeping.\n");
// 	}
// 	return (NULL);
// }

// void	init_pthread()
// {
// 	pthread_t	philosopher;
		
// 	pthread_create(&philosopher, NULL, ft_routine, NULL);
// }

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	*data;
	t_fork	*fork;

	if (incorrect_number_arguments(argc) == 1)
		return (EXIT_FAILURE);
	if (validate_arguments(argv) == 1)
		return (EXIT_FAILURE);
	philo = initialization_philo();
	if (philo == NULL)
		return (EXIT_FAILURE);
	data = initialization_data() ;
	if (data == NULL)
		return (EXIT_FAILURE);
	fork = initialization_fork();
	if (fork == NULL)
		return (EXIT_FAILURE);
	
	// pthread_mutex_destroy pour détruire les mutex.
}	

	// while (i < data->number_of_philosophers)
	// {
	// 	initialize_philosopher(&philo[i], data, i);
	// 	i++;
	// }

	// for (int i = 0; i < number_of_philosophers; i++)
    // {
    //     philo[i].id_philo = i;
    //     philo[i].nb_fork = 0;
    //     philo[i].data = data;
    //     philo[i].left_fork = forks[i];
    //     philo[i].right_fork = forks[(i + 1) % number_of_philosophers];
    // }
