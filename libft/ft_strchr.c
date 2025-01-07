/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:16:31 by macorso           #+#    #+#             */
/*   Updated: 2024/10/14 16:16:32 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searched)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)searched)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)searched)
		return ((char *)(str + i));
	return (NULL);
}
