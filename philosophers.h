/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:40:53 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/03 21:29:05 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

# define EMPTY '\0'

typedef struct s_fork{
	int	mutex_taken;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_data{
	t_fork *fork;
	//
	//
	// 
	long int	start;
	int	time_philosopher_takes_to_eat;
	int	is_dead;
	int	id_fork;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	pthread_mutex_t		printf_mutex;
}	t_data;

typedef struct s_philo{
	
	t_data		*data;
	int			id_philo;
	//
	//
	//
	int			nb_fork;
	t_fork	*left_fork;
	t_fork	*right_fork;
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
int		check_is_number(char **argv);
int		check_is_number_valid(char **argv);
int		validate_arguments(char **argv);
int		ft_isdigit(int c);
int		incorrect_number_arguments(int argc);
void	initialize_philosopher(t_philo *philo, t_data *data, int index);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

#endif 
