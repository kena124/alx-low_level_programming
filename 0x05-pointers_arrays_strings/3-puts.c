#include "main.h"

/**
 * _puts - prints a string, followed by a new line
 *
 * @str: a string to be printed
 *
 * Return: void
 */

void _puts(char *str)
{
	int len;

	len = 0;

	while (*(str + len))
	{
		_putchar(*(str + len));
		++len;
	}
	_putchar(10);
}
