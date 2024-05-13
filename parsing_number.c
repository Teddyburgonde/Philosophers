/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:01:46 by tebandam          #+#    #+#             */
/*   Updated: 2024/05/13 10:35:24 by tebandam         ###   ########.fr       */
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
			return (1);
		}
		while (argv[j][i])
		{
			if (ft_isdigit(argv[j][i]) == 0)
			{
				ft_putstr_fd("Error\nPlease write only numbers\n", 2);
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	check_is_number_valid(char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (ft_atoi(argv[1]) > 200)
	{
		ft_putstr_fd("Error\nYou can't have more than 200 philosophers!\n", 2);
		return (1);
	}
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (ft_atoi(argv[j]) <= 0)
			{
				ft_putstr_fd("Error , you must enter arg greater than 0\n", 2);
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	validate_arguments(char **argv)
{
	if ((check_is_number(argv) == 1) || (check_is_number_valid(argv) == 1))
		return (1);
	return (0);
}

int	incorrect_number_arguments(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error\nNumber of arguments is wrong\n", 2);
		return (1);
	}
	return (0);
}
