/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:15:34 by macorso           #+#    #+#             */
/*   Updated: 2024/11/04 13:08:10 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memBlock, int c, size_t n)
{
	size_t	i;

	if (memBlock == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(memBlock + i) == (unsigned char)c)
			return ((void *)(memBlock + i));
		i++;
	}
	return (NULL);
}
