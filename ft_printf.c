/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:13:45 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/17 14:13:45 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	sort_args(char type, va_list arg)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnb(va_arg(arg, int)));
	else if (type == 'u')
		return (ft_putu(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (ft_puthexa(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_puthexa(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (type == 'p')
	{
		write (1, "0x", 2);
		return (2 + ft_putptr(va_arg(arg, unsigned long int), "0123456789abcdef"));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len;
	int i;

	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				len += write(1, &str[i], 1);
			else
				len += sort_args(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}

/*
NEXT STEPS:
- corrigir %p %u %x %X
*/

/*
REMINDER:
The var_type argument must be one of int, long, decimal, double, struct, union,
	or pointer, or a typedef of one of these types.

TEST:
passar: null, off limits, no argument,
	etc e comparar com os resultados do printf original
*/

/*
INSTRUCTIONS:
-prototyped similarly to printf
-won’t do the buffer management in the printf function
-manage following conversions: sSpdDioOuUxXcC
-manage %%
-manage flags #0-+space
-manage min field-width
-manage precision
-manage flags hh, h, 1, 11, j, z
*/