#include <stdio.h>

#include "ft_printf.h"

int	ft_printf(const char *str, ...);

int	main (void)
{
	int	len;
	int lenorig;

	lenorig = printf(" %c %c %c \n", '0', 0, '1');
	len = ft_printf(" %c %c %c \n", '0', 0, '1');
	printf("\norig:%d \n", lenorig);
	printf("\n len:%d \n", len);
}