//test va_list to read arguments

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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
	// test_va(teststr, 'v');
	// printf("Characters: %c %c \n", 'a', 65);
	// printf("Decimals: %d %ld\n", 1977, 650000L);
	// printf("Preceding with blanks: %10d \n", 1977);
	// printf("Preceding with zeros: %010d \n", 1977);
	// printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100,
	// 		100);
	// printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf("Width trick: %*d \n", 5, 10);
	// printf("%s \n", "A string");
	printf("Some different radices: %d %i %u \n", INT_MIN, INT_MIN, INT_MIN);
	return (0);
}