/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:17:05 by macorso           #+#    #+#             */
/*   Updated: 2024/10/14 16:22:36 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *f, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (f[i] || s[i]))
	{
		if (f[i] != s[i])
			return ((unsigned char)f[i] - (unsigned char)s[i]);
		i++;
	}
	return (0);
}
