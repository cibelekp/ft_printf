//test va_list to read arguments

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	test_va(const char *str, ...)
{
	va_list	args;
	int		x;

	va_start(args, str);
	x = va_arg(args, int);
	while (args) //erro no while aqui!
		printf("x = %d", x);
	va_end(args);
	return (0);
}

int	main (void)
{
	const char	*teststr;

	teststr = "cibele";
	test_va(teststr, 1, 13, 14, 15);
	return (0);
}