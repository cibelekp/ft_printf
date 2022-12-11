#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	int len;
	int lenorig;
	void * test = NULL;

	printf("ORIGINAL:");
	printf("\n");
	lenorig = printf("%p", test);
	printf("\n");
	printf("FT:");
	printf("\n");
	len = ft_printf("%p", test);
	printf("\n");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
	printf("\n");
	lenorig = printf("%%");
	printf("\n");
	len = ft_printf("%%");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
}
