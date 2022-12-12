#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	int len;
	int lenorig;
	int d_test = INT_MIN;
	unsigned int u_test = UINT_MAX;
	char c_test = 0;
	char *s_test = "stringtest";
	void *p_test = NULL;

	printf("ORIGINAL:");
	printf("\n");
	lenorig = printf("%c", c_test);
	printf("\n");
	printf("FT_PRINTF:");
	printf("\n");
	len = ft_printf("%c", c_test);
	printf("\n");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
	printf("------------\n");

	printf("ORIGINAL:");
	printf("\n");
	lenorig = printf("%p", p_test);
	printf("\n");
	printf("FT_PRINTF:");
	printf("\n");
	len = ft_printf("%p", p_test);
	printf("\n");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
	printf("------------\n");

	printf("ORIGINAL:");
	printf("\n");
	lenorig = printf("%u", u_test);
	printf("\n");
	printf("FT_PRINTF:");
	printf("\n");
	len = ft_printf("%u", u_test);
	printf("\n");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
	printf("------------\n");

	printf("ORIGINAL:");
	printf("\n");
	lenorig = printf("%d", d_test);
	printf("\n");
	printf("FT_PRINTF:");
	printf("\n");
	len = ft_printf("%d", d_test);
	printf("\n");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
	printf("------------\n");

	printf("ORIGINAL:");
	printf("\n");
	lenorig = printf("%s", s_test);
	printf("\n");
	printf("FT_PRINTF:");
	printf("\n");
	len = ft_printf("%s", s_test);
	printf("\n");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
	printf("------------\n");
	printf("ORIGINAL:");
	printf("\n");
	lenorig = printf("%%");
	printf("\n");
	printf("FT_PRINTF:");
	printf("\n");
	len = ft_printf("%%");
	printf("\norig len:%d", lenorig);
	printf("\n  my len:%d \n", len);
}
