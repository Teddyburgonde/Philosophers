/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:08:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/08 05:08:07 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}
// Message pour dire que a telle heure , le philosopher x a pris une fourchette 
void	printf_for_take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (!check_philo_is_dead(philo))
		printf("%li %d has taken a fork\n",
			get_timestamp(philo->data->start_time), philo->id_philo);
	pthread_mutex_unlock(&philo->data->printf_mutex);
	fork->fork_is_available = 1;
}

// Message pour dire que a telle heure , le philosopher x a fait cette* action
// j'ai fais un strncmp pour differencier le message de la mort
void	print_message(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->data->printf_mutex);
	if (ft_strncmp(state, "died", 4) != 0 && !check_philo_is_dead(philo))
		printf("%li %d is %s\n",
			get_timestamp(philo->data->start_time), philo->id_philo, state);
	else
	{
		printf("%li %d %s\n",
			get_timestamp(philo->data->start_time), philo->id_philo, state);
	}
	pthread_mutex_unlock(&philo->data->printf_mutex);
}
