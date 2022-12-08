/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:49:01 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/08 20:49:01 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
// #include <unistd.h>
// # include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
		s = "(null)";
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	sort_args(char type, va_list arg, int i) //recebo o index ou um len?
{
	int	len;

	len = i;
	if (type == 'c')
		ft_putchar(va_arg(arg, int));
	else if (type == 's')
		len += (ft_putstr(va_arg(arg, char*))) - 1;
	return (len);
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
		// ajustar calculo len
		else
			ft_putchar(str[i]);
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	const char *teststr;
	int			len;
	int			len_orig;

	teststr = "cibele %s";
	len = ft_printf(teststr, NULL);
	printf("\n");
	len_orig = printf(teststr, NULL);
	printf("\n len ft_printf: %d \n len printf: %d", len, len_orig);
	return (0);
}
/*
NEXT STEPS:
- acertar determinacao da len
(nao contar placeholder% + contar strlen do que for impresso na auxiliar
*/

/*
REMINDER:
The var_type argument must be one of int, long, decimal, double, struct, union, or pointer, or a typedef of one of these types.

TEST:
passar: null, off limits, no argument, etc e comparar com os resultados do printf original
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