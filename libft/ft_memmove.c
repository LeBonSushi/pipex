/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:15:59 by macorso           #+#    #+#             */
/*   Updated: 2024/10/14 16:16:00 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	int	i;

	if (!d || !s)
		return (NULL);
	if (d > s)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(d + i) = *(char *)(s + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(d + i) = *(char *)(s + i);
			i++;
		}
	}
	return (d);
}
