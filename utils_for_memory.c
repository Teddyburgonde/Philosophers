/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:30:29 by tebandam          #+#    #+#             */
/*   Updated: 2024/06/26 08:30:40 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*tab;

	tab = s;
	i = 0;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	long int	size_alloc;

	size_alloc = nmemb * size;
	if (size_alloc < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_memset(ptr, '\0', nmemb * size);
	return (ptr);
}