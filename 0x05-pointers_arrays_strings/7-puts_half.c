#include "main.h"
#include "2-strlen.c"

/**
 * puts_half - prints the second half of the array
 *
 * @str: the string
 *
 * Return: void
 */

void puts_half(char *str)
{
	int len;
	int half;

	len = _strlen(str);
	half = len / 2;

	if (len % 2 != 0)
		half += 1;

	while (*(str + half))
	{
		_putchar(*(str + half));
		half++;
	}
	_putchar(10);
}
