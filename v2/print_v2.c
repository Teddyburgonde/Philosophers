/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:08:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/29 17:14:31 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	printf_for_take_fork(t_philo *philo, char *fork_str)
{
	printf("At {%li} the philosopher %d take the %s forks \n",
			get_timestamp(philo->data->start_time), philo->id_philo, fork_str);
}
