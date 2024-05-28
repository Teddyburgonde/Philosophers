/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:40:53 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/28 20:59:33 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

/*
* Structures
*/

typedef struct s_fork{
	int	fork_is_available;
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


/*
* Utils
*/
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);

/*
* Parsing
*/
int		check_is_number(char **argv);
int		check_is_number_valid(char **argv);
int		validate_arguments(char **argv);
int		incorrect_number_arguments(int argc);

/*
* Initilization
*/
int initialization_philo(t_philo *philo, t_data *data);
int initialization_data(t_data *data, char **argv);
void initialization_forks(t_philo *philo);
int	initialization_mutex(t_data *data);


/*
* time
*/
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
long int	get_timestamp(long int start);

/*
* Routine
*/

void ft_sleep(t_philo *philo);
void ft_think(t_philo *philo);
void ft_eat(t_philo *philo);
void	ft_taken_fork(t_philo *philo);

/*
* dead
*/

int	is_philo_dead(t_philo *philo);
int 	check_philo_is_dead(t_philo *philo);

#endif 
