/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:50:41 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/05 20:50:41 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		x;

	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		write (1, &str[i], 1);
		if (str[i] == '%')
		// then goes to aux function 
	}
	va_end(args);
	return (0); //return count
}

int	main (void)
{
	const char	*teststr;

	teststr = "cibele";
	ft_printf("cocolkawf;lkasfa %", 1, 13, 14, 15);
	return (0);
}
/*
STEPS:
1)structure for defining different formats
2)main function: 
 -check if not %
 -if % -> evaluate which kind of variable is being received
3)(aux) functions for each format
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