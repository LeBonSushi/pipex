/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:15:41 by macorso           #+#    #+#             */
/*   Updated: 2024/10/22 13:56:31 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t	i;

	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(d + i) = *(char *)(s + i);
		i++;
	}
	return (d);
}
