#include "main.h"
/**
 * print_numbers - prints the numbers
 *
 * Description: a function that prints the numbers, 0 to 9
 *
 */
void print_numbers(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
