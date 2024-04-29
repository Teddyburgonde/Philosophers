/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:40:53 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/29 18:28:04 by tebandam         ###   ########.fr       */
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

typedef struct s_chopstick{
	int				id_chopstick;
	pthread_mutex_t	*is_chopstick_used;
}	t_chopstick;

typedef struct s_data{
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				is_dead;
	long int		start;
	t_chopstick		*chopstick;
}	t_data;

typedef struct s_philo{
	t_data		*t_data;
	int			id_philo;
	t_chopstick	*left_chopstick;
	t_chopstick	*right_chopstick;
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