/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:09:16 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/27 07:15:53 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// ! l'heure actuel 
long int	get_current_time(void)
{
	struct timeval	time;
	int				save;

	save = 0;
	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 22);
		return (-1);
	}
	save = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (save);
}

// ! le temps ecouler depuis le debut du programme
long int	get_timestamp(long int start)
{
	long int	timestamp;

	timestamp = get_current_time() - start;
	return (timestamp);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
