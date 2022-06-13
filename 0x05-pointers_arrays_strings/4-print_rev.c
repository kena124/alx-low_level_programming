#include "main.h"
#include "2-strlen.c"

/**
 * print_rev - prints a string, in reverse, followed by a new line.
 *
 * @s: the string
 *
 * Return: void
 */

void print_rev(char *s)
{
	int len;
	int last_index;

	len = _strlen(s);
	last_index = len - 1;

	while (last_index >= 0)
	{
		_putchar(*(s + last_index));
		last_index--;
	}
	_putchar(10);
}

