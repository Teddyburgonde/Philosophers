/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philosophers_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:20:22 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/08 05:21:50 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
// incrementation la variable de la satieté
void	check_and_update_satiety_of_philosopher(t_philo *philo)
{
	if (philo->nb_meals_eaten == philo->data->nb_of_times_philo_must_eat)
	{
		pthread_mutex_lock(&philo->data->philo_satiated_mutex);
		philo->data->philo_satiated++;
		pthread_mutex_unlock(&philo->data->philo_satiated_mutex);
	}
}
// rendre les fourchettes disponibles
void	make_forks_available(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork_mutex);
	philo->left_fork->fork_is_available = 0;
	pthread_mutex_unlock(&philo->left_fork->fork_mutex);
	pthread_mutex_lock(&philo->right_fork->fork_mutex);
	philo->right_fork->fork_is_available = 0;
	pthread_mutex_unlock(&philo->right_fork->fork_mutex);
}
