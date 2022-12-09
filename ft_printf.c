/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/12/08 20:49:01 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/08 20:49:01 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdarg.h>
// #include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int i;

	i = -1;
	if (s == NULL)
		s = "(null)";
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	ft_putnb(int nb)
{
	int len;

	if (nb == INT_MIN)
	{
		len = ft_putstr("-2147483648");
		return (len);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		len += 1;
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnb(nb / 10);
		len += 1;
	}
	ft_putchar(nb % 10 + '0');

	// if (nb < 10)
	// 	ft_putchar(nb % 10 + '0');
	// else
	// {
	// 	ft_putnb(nb / 10);
	// 	len += 1;
	// }
	return (len);
}

int	sort_args(char type, va_list arg, int i)
{
	int len;

	len = i;
	if (type == 'c')
		ft_putchar(va_arg(arg, int));
	else if (type == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		len += ft_putnb(va_arg(arg, int));
	else if (type == 'u')
		len += ft_putnb(va_arg(arg, int));
		// type U is not correct; len also returning wrong
	return (len - 1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int len;
	int i;

	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			len = sort_args(str[i], args, i);
		}
		else
			ft_putchar(str[i]);
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	char *teststr;
	int testint;
	unsigned int testuint;
	int len;
	int len_orig;

	teststr = "TESTING STR: %s";
	testint = INT_MIN;
	testuint = INT_MAX;
	// len = ft_printf(teststr, NULL);
	// printf("\n");
	// len_orig = printf(teststr, NULL);
	// printf("\n len ft_printf: %d \n len printf: %d", len, len_orig);
	// printf("\n");
	len = ft_printf("TESTING INT: %d", testint);
	printf("\n");
	len_orig = printf("TESTING INT: %d", testint);
	printf("\n len ft_printf: %d \n len    printf: %d", len, len_orig);
	printf("\n");
	len = ft_printf("TESTING UINT: %u", testuint);
	printf("\n");
	len_orig = printf("TESTING UINT: %u", testuint);
	printf("\n len ft_printf: %d \n len    printf: %d", len, len_orig);
	printf("\n");
	return (0);
}
/*
NEXT STEPS:
- acertar calculo %u + len
	como printf interpreta numeros negativos quando passados como %u?
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