/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:56:04 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/12 22:56:04 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int c)
{
	if (c < 0)
		c += 256;
	//	write(1, &c, 1); return (1); OR:
	return (write(1, &c, 1));
}

static int	ft_putstr(char *s)
{
	int i;

	i = -1;
	if (s == NULL)
		s = "(null)";
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

static int	ft_puthexa(unsigned long int nb, char *base)
{
	int len;

	len = 0;
	if (nb >= 16)
		len += ft_puthexa(nb / 16, base);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

static int	ft_putnb(int nb)
{
	int len;

	len = 0;
	if (nb == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnb(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len);
}

static int	sort_args(char type, va_list arg, int len)
{
	unsigned long int ptr;

	if (type == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		len += ft_putnb(va_arg(arg, int));
	else if (type == 'u')
	{
	//	aux = va_arg(arg, unsigned int);
	//	if (aux < INT_MAX)
			len += ft_putnb(va_arg(arg, unsigned int));
	}
	else if (type == 'x')
		len += ft_puthexa(va_arg(arg, unsigned long int), "0123456789abcdef");
	else if (type == 'X')
		len += ft_puthexa(va_arg(arg, unsigned long int), "0123456789ABCEDF");
	else if (type == 'p')
	{
		ptr = va_arg(arg, unsigned long int); // maybe put it inside puthexa
		if (!ptr)
			len += ft_putstr("(nil)");
		else
		{
			len += ft_putstr("0x");
			len += ft_puthexa(va_arg(arg, unsigned long int), "0123456789abcdef");
		}
	}
	return (len);
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
			{
				write(1, &str[i], 1);
				len += 1;
			}
			else
				len = sort_args(str[i], args, len);
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
- corrigir %c
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