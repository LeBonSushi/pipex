/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:14:25 by macorso           #+#    #+#             */
/*   Updated: 2024/11/04 14:29:18 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// int main(void)
// {
// 	int test = '%';
// 	int test2 = 'B';

// 	printf("%d\n", ft_isalnum(test));
// 	printf("%d\n", ft_isalnum(test2));
// 	return (0);
// }
