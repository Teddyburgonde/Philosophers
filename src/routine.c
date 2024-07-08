/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:04:48 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/08 05:30:29 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
// action de prendre les fourchettes
void	take_forks(t_philo *philo)
{
	while (philo->nb_forks < 2)
	{
		if (check_philo_is_dead(philo) == 1
			|| philo->data->philo_satiated
			== philo->data->number_of_philosophers)
			break ;
		pthread_mutex_lock(&philo->left_fork->fork_mutex);
		// si la fourchette guache est disponible je la prends
		if (philo->left_fork->fork_is_available == 0)
		{
			printf_for_take_fork(philo, philo->left_fork);
			philo->nb_forks++;
		}
		pthread_mutex_unlock(&philo->left_fork->fork_mutex);
		if (check_philo_is_dead(philo) == 1
			|| philo->data->philo_satiated
			== philo->data->number_of_philosophers)
			break ;
		pthread_mutex_lock(&philo->right_fork->fork_mutex);
		// si la fourchette droite est disponible je la prends
		if (philo->right_fork->fork_is_available == 0)
		{
			printf_for_take_fork(philo, philo->right_fork);
			philo->nb_forks++;
		}
		pthread_mutex_unlock(&philo->right_fork->fork_mutex);
	}
}

void	ft_eat(t_philo *philo)
{
	if (check_philo_is_dead(philo) == 1)
		return ;
	// la derniere fois qu'il a manger
	philo->last_time_eaten = get_timestamp(philo->data->start_time);
	// il mange
	philosopher_is_eating(philo);
	// regarde et update la satietié, ce qui est important pour le dernier argument optionnel dans le terminal
	check_and_update_satiety_of_philosopher(philo);
	// Quand il aura fini manger je rends les fouchettes de nouveau disponible disponible
	make_forks_available(philo);
}

void	ft_sleep(t_philo *philo)
{
	long int	current_time;

	if (check_philo_is_dead(philo))
		return ;
	// l'heure actuel
	current_time = get_timestamp(philo->data->start_time);
	print_message(philo, "sleeping");
	// temps que l'heure du debut du programme - lheure actuel est < au temps maximun qu'il peut dormir 
	// le philosopher dormira
	while (get_timestamp(philo->data->start_time)
		- current_time < philo->data->time_to_sleep)
	{
		if (check_philo_is_dead(philo))
			return ;
		// pour simuler le fait qu'il dort
		ft_usleep(50);
	}
	// si il n'est pas mort apres qu'il est dormi il va penser.
	if (!check_philo_is_dead(philo))
		print_message(philo, "thinking");
}

void	*ft_routine(t_philo *philo)
{
	// pour creer un decalage la je dis que c'est les philosophes paire qui attendent avant de manger.
	// Les impaires eux commencent.
	if (philo->id_philo % 2 == 0)
		ft_usleep(50);
	while (1)
	{
		// si le philo n'est pas mort et si il n'a pas atteint la satieté 
		// il peut faire les actions.
		// Il est important de check a chaque fois qu'il n'est pas mort 
		// car il peut mourir entre les actions. 
		if (check_philo_is_dead(philo) == 1
			|| philo->data->philo_satiated
			== philo->data->number_of_philosophers)
			return (NULL);
		take_forks(philo);
		if (check_philo_is_dead(philo) == 1
			|| philo->data->philo_satiated
			== philo->data->number_of_philosophers)
			return (NULL);
		ft_eat(philo);
		if (check_philo_is_dead(philo) == 1
			|| philo->data->philo_satiated
			== philo->data->number_of_philosophers)
			return (NULL);
		ft_sleep(philo);
	}
	return (NULL);
}
