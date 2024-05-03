// savoir si il est mort 


// int	philo_dead(t_philo *philo)
// {
// 	long int	timestamp;

// 	pthread_mutex_lock(&philo->data->is_dead_mutex);
// 	if (philo->data->is_dead)
// 	{
// 		pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 	timestamp = get_timestamp(philo->data->start);
// 	if ((timestamp - philo->last_time_eaten) > philo->data->time_to_die)
// 	{
// 		pthread_mutex_lock(&philo->data->is_dead_mutex);
// 		philo->data->is_dead = 1;
// 		pthread_mutex_unlock(&philo->data->is_dead_mutex);
// 		print_death(philo);
// 		return (1);
// 	}
// 	return (0);
// }