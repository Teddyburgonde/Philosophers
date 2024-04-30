/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/30 10:09:14 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

/*

Pour simuler le processus de prise des baguettes et éviter les conditions de concurrence, vous devrez intégrer des mécanismes de synchronisation tels que des mutex ou des sémaphores. Ces mécanismes permettront à chaque philosophe de prendre les baguettes de manière sûre et équitable.

Voici une approche générale que vous pourriez prendre :

1.Chaque philosophe tente de prendre les deux baguettes (mutex) à sa gauche et à sa droite.
2.Si les deux baguettes sont disponibles, le philosophe les prend et commence à manger.
3. Sinon, le philosophe attend que les baguettes soient disponibles avant de tenter à nouveau de les prendre.
*/


// penser, manger et dormir.

// je suis a verouiller un mutex
// pthread_mutex_destroy(&nameofmutex);
void	*ft_routine(void *arg)
{
	t_philo *philo;
	size_t	i;
	t_chopstick *left_chopstick; 
	t_chopstick *right_chopstick;
	pthread_mutex_t	mutex_philosopher;

	pthread_mutex_init(&mutex_philosopher, NULL);
	left_chopstick = 0;
	right_chopstick = 0;
	i = 0;
	philo = (t_philo *)arg;
	while (i < philo->t_data->number_of_philosophers)
	{
		philo[i].id_philo = i + 1;
		i++;
	}
	while(1)
	{
		printf("Philosopher thinking.\n");
		printf("Philosopher waits before taking the chopsticks.\n");
		if ((philo->left_chopstick->is_chopstick_used && philo->right_chopstick->is_chopstick_used) == 0)
		{
			pthread_mutex_lock(&mutex_philosopher);
			printf("Philosopher eating.\n");
			pthread_mutex_unlock(&mutex_philosopher);
		}
		else 
		{
			printf("Philosopher thinking.\n");
			printf("Philosopher waits before taking the chopsticks.\n");
		}
		printf("Philosopher sleeping.\n");
	}
	return (NULL);
}

void	init_pthread()
{
	pthread_t	philosopher;
		
	pthread_create(&philosopher, NULL, ft_routine, NULL);
}



int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	pthread_t	philosopher;

	int		i;

	if (validate_arguments(argv) == 1)
		return (1);
	if (incorrect_number_arguments(argc) == 1)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	i = 0;
	pthread_create(&philosopher, NULL, ft_routine, (void*)philo);
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (philo == NULL)
		return (EXIT_FAILURE);
	while (i < data->number_of_philosophers)
	{
		initialize_philosopher(&philo[i], data, i);
		i++;
	}
}
