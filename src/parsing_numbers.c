/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 08:15:31 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/08 04:55:40 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Parsing pour gerer differents cas d'erreurs
int	check_number_size(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
		{
			ft_putstr_fd("Error\nOverflow\n", 2);
			return (-1);
		}
		else if (ft_atoi(argv[i]) == 0)
		{
			ft_putstr_fd("Error\n0 is not allowed\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

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
			ft_putstr_fd("Error\nArgument\n", 2);
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
