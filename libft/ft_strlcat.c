/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:16:47 by macorso           #+#    #+#             */
/*   Updated: 2024/11/04 16:42:04 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	i;
	size_t	index;
	size_t	d_len;

	d_len = ft_strlen(d);
	index = 0;
	while (d[index])
		index++;
	i = 0;
	while (s[i] && (i + index + 1) < n)
	{
		d[index + i] = s[i];
		i++;
	}
	if (i < n)
		d[index + i] = 0;
	if (n <= d_len)
		return (ft_strlen(s) + n);
	else
		return (ft_strlen(s) + d_len);
}
