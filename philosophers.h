/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:40:53 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/07 22:00:38 by tebandam         ###   ########.fr       */
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


// typedef struct s_data
// {
// 	pthread_t		*tid;
// 	int				philo_num;
// 	int				meals_nb;
// 	int				dead;
// 	int				finished;
// 	t_philo			*philos;
// 	u_int64_t		death_time;
// 	u_int64_t		eat_time;
// 	u_int64_t		sleep_time;
// 	u_int64_t		start_time;
// 	pthread_mutex_t	*forks;
// 	pthread_mutex_t	lock;
// 	pthread_mutex_t	write;
// }	t_data;

// a revoir 
typedef struct s_data{
	pthread_mutex_t		is_dead_mutex;
	int	number_of_philosophers;
	int	meals_nb;
	int	is_dead;
	//int finished;
	t_philo	*philo; 
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		printf_mutex;
}	t_data;

typedef struct s_philo{
	
	t_data				*data;
	pthread_t			thread_id;
	int					id_philo;
	int					eat_cont;
	int					status;
	int					eating;
	long int			last_time_eaten;
	pthread_mutex_t	lock; 
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int		ft_atoi(const char *nptr);
int		check_is_number(char **argv);
int		check_is_number_valid(char **argv);
int		validate_arguments(char **argv);
int		ft_isdigit(int c);
int		incorrect_number_arguments(int argc);
int		ft_routine(t_philo *philo);
int		ft_usleep(size_t milliseconds);
void	initialization_philo(t_data *data);
void	ft_putstr_fd(char *s, int fd);
size_t	get_current_time(void);

#endif 
