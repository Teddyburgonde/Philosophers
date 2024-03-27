/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:43 by tebandam          #+#    #+#             */
/*   Updated: 2024/03/27 10:18:33 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	programme doit recevoir 4 ou 5 arguments 
	Analysons l'entrée que nous recevrons : 5 800 200 200 7
	5 — Le nombre de philosophes
	800 — Le moment où un philosophe mourra s'il ne mange pas
	200 — Le temps qu'il faut à un philosophe pour manger
	200 — Le temps qu'il faut à un philosophe pour dormir
	7 Nombre de fois que tous les philosophes doivent manger avant de terminer le programme ** argument facultatif

	l'entrée ne contient que des nombres
	ils doivent tous être supérieurs à 0 sauf le nombre de repas que chaque philo doit manger (cas limite)
	Dans le formulaire d'évaluation, il est indiqué que nous ne devons pas tester avec plus de 200 philos afin que vous puissiez fixer la limite à ne pas dépasser 200.
*/

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
		ft_putstr_fd("Error\nNumber of arguments is wrong\n", 2);
	(void)argv;
			
}