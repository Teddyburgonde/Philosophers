/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:21:51 by tebandam          #+#    #+#             */
/*   Updated: 2024/07/02 19:35:17 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	handle_sign(const char *nptr, int *i, int *sign)
{
	while (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i + 1] == '+')
			return (0);
		if (nptr[*i] == '-')
			*sign *= -1;
		if (nptr[*i + 1] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	a;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	if (!nptr)
		return (-1);
	while (is_whitespace(nptr[i]))
		i++;
	if (!handle_sign(nptr, &i, &sign))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		a = a * 10 + (nptr[i] - '0');
		i++;
	}
	return (a * sign);
}
