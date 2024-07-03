/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:40:53 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/03 10:25:50 by tebandam         ###   ########.fr       */
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

typedef struct s_fork
{
	int					fork_is_available;
	pthread_mutex_t		fork_mutex;
}	t_fork;

typedef struct s_data
{
	int					number_of_philosophers;
	int					time_to_sleep;
	int					time_to_eat;
	int					time_to_die;
	int					nb_of_times_philo_must_eat;
	int					is_dead;
	int					philo_satiated;
	long int			start_time;
	t_fork				*forks;
	pthread_mutex_t		is_dead_mutex;
	pthread_mutex_t		philo_satiated_mutex;
	pthread_mutex_t		printf_mutex;
}	t_data;

typedef struct s_philo
{
	t_data				*data;
	int					id_philo;
	int					nb_meals_eaten;
	int					nb_forks;
	long int			last_time_eaten;
	pthread_t			thread_id;
	t_fork				*left_fork;
	t_fork				*right_fork;
}	t_philo;

/*
* Parsing
*/

int			check_is_number(char **argv);
int			incorrect_number_arguments(int argc);

/*
* Initilization
*/

int			initialization_philo(t_philo *philo, t_data *data);
int			initialization_data(t_data *data, char **argv);
int			initialization_mutex(t_data *data, int nb_philo);
/*
* time
*/

int			ft_usleep(size_t milliseconds);
long int	get_current_time(void);
long int	get_timestamp(long int start);

/*
* Thread
*/

int			manage_thread_start_ft_routine(t_philo	*philo, t_data *data);

/*
* Routine
*/

void		ft_sleep(t_philo *philo);
void		ft_eat(t_philo *philo);
void		take_forks(t_philo *philo);
void		*ft_routine(t_philo *philo);

/*
* free
*/

/*
* manage philosophers
*/

void		check_and_update_satiety_of_philosopher(t_philo *philo);
void		make_forks_unavailable(t_philo *philo);

/*
* dead
*/

int			is_philo_dead(t_philo *philo);
int			check_philo_is_dead(t_philo *philo);

/*
* print
*/

void		printf_for_take_fork(t_philo *philo,
				t_fork *fork, int is_left_fork);
void		print_message(t_philo *philo, char *state);


/*
* utils for routine
*/

void		philosopher_is_eating(t_philo *philo);

/*
* Utils for parsing
*/

int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);

/*
* Utils for memory
*/

void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		destroy_all_mutex(t_philo *philo, t_data *data);

#endif 
