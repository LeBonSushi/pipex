/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:14:32 by macorso           #+#    #+#             */
/*   Updated: 2024/11/04 14:49:59 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}

// int main(void)
// {
// 	int test = 'É';
// 	int test2 = 'e';

// 	printf("%d\n", ft_isascii(test));
// 	printf("%d\n", ft_isascii(test2));

// 	return (0);
// }