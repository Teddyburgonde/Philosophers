/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:01:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/27 15:43:41 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_is_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		if (argv[j][i] == '\0')
		{
			ft_putstr_fd("Error\n'\0' argument\n", 2);
			return (-1);
		}
		while (argv[j][i])
		{
			if (ft_isdigit(argv[j][i]) == 0)
			{
				ft_putstr_fd("Error\nPlease write only numbers\n", 2);
				return (-1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	incorrect_number_arguments(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error\nNumber of arguments is wrong\n", 2);
		return (-1);
	}
	return (0);
}
