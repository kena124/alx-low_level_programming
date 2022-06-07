#include "main.h"

/**
 * print_sign - a function that prints the sign of a number
 *
 * @n: print integer
 *
 * Description: a function that prints the sign of a number
 *
 *
 * Return: 1 or 0 .
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar ('+');
		return (1);
	}

	else if (n == 0)
	{
		_putchar ('0');
		return (0);
	}

	else
	{
		_putchar ('-');
		return (-1);
	}

}
