/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:09:16 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/08 05:21:24 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// temps courant en miliseconde. 
long int	get_current_time(void)
{
	struct timeval	time;
	long int		save;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 22);
		return (-1);
	}
	save = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (save);
}
// temps depuis la creation du system linux
long int	get_timestamp(long int start)
{
	long int	timestamp;

	timestamp = get_current_time() - start;
	return (timestamp);
}
// creation de notre propre usleep pour etre plus precis que la fonction usleep de base.
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
