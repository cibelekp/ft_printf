//test va_list to read arguments

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	test_va(const char *str, ...)
{
	va_list	args;
	int		num;
	char	c;
	char	*s;

	va_start(args, str);
	// num = va_arg(args, int);
	// printf("num = %d \n", num);
	// num = va_arg(args, int);
	// printf("num 2 = %d \n", num);
	// c = va_arg(args, int);
	ft_putchar(va_arg(args, int));
	// if (s)
	// {
	// 	s = va_arg(args, char *);
	// 	printf("s = %s \n", s);
	// }
	va_end(args);
	return (0);
}

int	main(void)
{
	const char *teststr;

	teststr = "cibele";
	test_va(teststr, 'v');
	return (0);
}