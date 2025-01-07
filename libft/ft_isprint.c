/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:14:40 by macorso           #+#    #+#             */
/*   Updated: 2024/11/04 14:54:45 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}

// int main(void)
// {
// 	int test = 'É';
// 	int test2 = 'e';

// 	printf("%d\n", ft_isprint(test));
// 	printf("%d\n", ft_isprint(test2));

// 	return (0);
// }