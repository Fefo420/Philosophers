/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:58:41 by fileonar          #+#    #+#             */
/*   Updated: 2025/05/08 23:28:29 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_bzero(void *mem, size_t count)
{
	unsigned char	*s;
	size_t			x;

	s = (unsigned char *)mem;
	x = 0;
	while (x < count)
	{
		s[x] = '\0';
		x++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *)malloc(count * size);
	if (!mem)
		return (0);
	ft_bzero(mem, count * size);
	return (mem);
}