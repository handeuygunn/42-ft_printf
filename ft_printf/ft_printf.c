/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:42 by huygun            #+#    #+#             */
/*   Updated: 2023/07/19 14:49:58 by huygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

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

static int	ft_control(va_list args, char p)
{
	size_t	length;

	length = 0;
	if (p == 'c')
		length += ft_putchar(va_arg(args, int));
	if (p == 's')
		length += ft_putstrforprint(va_arg(args, char *));
	if (p == '%')
		length += ft_putchar('%');
	if (p == 'd' || p == 'i')
		length += ft_printfd(va_arg(args, int));
	if (p == 'u')
		length += ft_printfd(va_arg(args, unsigned int));
	if (p == 'x' || p == 'X')
		length += ft_printfhex(va_arg(args, unsigned int), p);
	if (p == 'p')
		length += ft_printfhexp((unsigned long)va_arg(args, void *), p);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	length;

	length = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			length += ft_control(args, *format);
		}
		else
		{
			write(1, format, 1);
			length++;
		}
		format++;
	}
	va_end(args);
	return ((int)length);
}
