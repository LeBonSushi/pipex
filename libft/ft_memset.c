/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:16:02 by macorso           #+#    #+#             */
/*   Updated: 2024/10/22 13:55:42 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int v, size_t c)
{
	size_t			i;
	unsigned char	*str;

	if (s == NULL)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (i < c)
	{
		str[i] = (unsigned char)v;
		i++;
	}
	return (s);
}
