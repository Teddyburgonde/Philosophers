/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/04/07 12:07:19 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	incorrect_number_arguments(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Error\nNumber of arguments is wrong\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	validate_arguments(argv);
	incorrect_number_arguments(argc);
	
	
}
