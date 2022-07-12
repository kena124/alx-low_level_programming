#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_strings - prints the string parameters
 * @separator: input string
 * @n: number of the other input strings
 * Return: nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;
	char *str;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			printf("%s", "(nil)");
		else
			printf("%s", str);
		if (i != n - 1 && separator)
			printf("%s", separator);
	}
	va_end(ap);
	printf("\n");
}
