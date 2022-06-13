#include "main.h"

/**
 * puts2 - prints the second element of an array starting
 * frm the first element
 *
 * @str: the string
 *
 * Return: void
 */

void puts2(char *str)
{
	int count;

	count = 0;

	while (*(str + count) != '\0')
	{
		if (count % 2 == 0)
			_putchar(*(str + count));
		count += 1;
	}
	_putchar(10);
}
