/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:24 by huygun            #+#    #+#             */
/*   Updated: 2023/07/18 19:27:38 by huygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 15)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

int	ft_printfhex(unsigned long nb, char a)
{
	size_t	length;

	length = ft_len(nb);
	if (nb >= 16)
	{
		ft_printfhex(nb / 16, a);
		ft_printfhex(nb % 16, a);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
		{
			if (a == 'x' || a == 'p')
				ft_putchar(nb - 10 + 'a');
			else
				ft_putchar(nb - 10 + 'A');
		}
	}
	return ((int)length);
}
