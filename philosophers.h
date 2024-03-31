/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:40:53 by tebandam          #+#    #+#             */
/*   Updated: 2024/03/31 15:39:44 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <cstddef>
# include <unistd.h>
# define EMPTY '\0'

typedef struct{
	// pthread_t		thread;

	// Chaque philosophe possède un numéro allant de 1 ànombre_de_philosophes.
	int	number_of_philosophers;
	int number_of_times_each_philosopher_must_eat;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	//pthread_mutex_t	*r_fork;
	//pthread_mutex_t	*l_fork;
	
} t_philo;

// typedef struct{
// 	int dead_flag;
// } t_prog;
// Créé une boucle qui se brisera dès que le drapeau mort sera à 1, autrement dit dès qu'un philo sera mort.

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
int		check_is_number(char **argv);
int		check_is_number_valid(char **argv);
int		validate_arguments(char **argv);
int		ft_isdigit(int c);

#endif 