/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:14:09 by macorso           #+#    #+#             */
/*   Updated: 2024/11/05 13:19:45 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t element_count, size_t element_size)
{
	void	*ptr;

	if (element_size && element_count > SIZE_MAX / element_size)
		return (0);
	ptr = (void *) malloc(element_count * element_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, element_count * element_size);
	return (ptr);
}
