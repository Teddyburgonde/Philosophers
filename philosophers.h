/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:40:53 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/09 16:05:28 by tebandam         ###   ########.fr       */
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
	int	mutex_id;
	pthread_mutex_t fork_mutex;
}t_fork;

typedef struct s_data{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_philo_must_eat;
	int	is_dead;
	int	philo_satiated;
	long int	start_time;
	t_fork	*forks;
	pthread_mutex_t		is_dead_mutex;
	pthread_mutex_t		philo_satiated_mutex;
	pthread_mutex_t		printf_mutex;
}	t_data;

typedef struct s_philo{
	t_data				*data;
	int					id_philo;
	int					nb_meals_eaten;
	int					nb_forks;
	long int			last_time_eaten;
	pthread_t			thread_id;
	t_fork	*left_fork;
	t_fork	*right_fork;
}	t_philo;

int		ft_atoi(const char *nptr);
int		check_is_number(char **argv);
int		check_is_number_valid(char **argv);
int		validate_arguments(char **argv);
int		ft_isdigit(int c);
int		incorrect_number_arguments(int argc);
void	*ft_routine(void *arg);
int		ft_usleep(size_t milliseconds);
void	initialize_philosopher(t_philo *philo, t_data *data, int index);
void	ft_putstr_fd(char *s, int fd);
int initialization_philo(t_philo *philo, t_data *data);
void initialization_data(t_data *data, char **argv);
void	ft_sleep(t_philo *philo);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	get_current_time(void);

#endif 
