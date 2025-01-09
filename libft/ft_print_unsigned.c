/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:52:38 by macorso           #+#    #+#             */
/*   Updated: 2024/11/19 07:52:16 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int num)
{
	char	*res;
	int		len;

	len = ft_num_len(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = 0;
	while (num != 0)
	{
		res[len - 1] = num % 10 + 48;
		num /= 10;
		len--;
	}
	return (res);
}

int	ft_print_unsigned(unsigned int num)
{
	int		print_len;
	char	*to_print;

	print_len = 0;
	if (num == 0)
		print_len += write(1, "0", 1);
	else
	{
		to_print = ft_unsigned_itoa(num);
		print_len += ft_printstr(to_print);
		free(to_print);
	}
	return (print_len);
}
