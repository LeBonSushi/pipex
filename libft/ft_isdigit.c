/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:14:36 by macorso           #+#    #+#             */
/*   Updated: 2024/11/04 14:54:11 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int main(void)
// {
// 	int test = '7';
// 	int test2 = 'e';

// 	printf("%d\n", ft_isdigit(test));
// 	printf("%d\n", ft_isdigit(test2));

// 	return (0);
// }