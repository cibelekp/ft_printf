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
/*   Created: 2022/12/05 20:50:41 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/05 20:50:41 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	sort_args(char type, va_list arg, int i) //recebo o index ou um len?
{
	int	len;

	len = i;//valor recebido fe printf
	if (type == 'c')
		ft_putchar(va_arg(arg, int));
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

	teststr = "cibele %c mais %c. \n";
	len = ft_printf(teststr, 'Y', 'x');
	printf("%d", len);
	return (0);
}
/*
NEXT STEPS:
- acertar determinacao da len
(nao contar placeholder% + contar strlen do que for impresso na auxiliar
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