/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:01 by huygun            #+#    #+#             */
/*   Updated: 2023/07/19 16:08:52 by huygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstrforprint(char *p)
{
	int	i;

	i = 0;
	if (p == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (p[i])
	{
		write(1, &p[i], 1);
		i++;
	}
	return (i);
}

int	ft_printfhexp(unsigned long nb, char a)
{
	int	length;

	length = 0;
	ft_putstrforprint("0x");
	length += ft_printfhex(nb, a);
	return (length +2);
}
