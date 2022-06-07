#include "main.h"

/**
 * print_alphabet_x10 - a function that prints 10 times the alphabet
 *
 * Description: a function that prints 10X the lowercase alphabet
 *
 * Return: Always 0 (Success).
 */

void print_alphabet_x10(void)
{
	int alphabet, count;


	count = 0;

	while (count < 10)
	{
		for (alphabet = 'a' ; alphabet <= 'z'; alphabet++)
		{
			_putchar(alphabet);
		}

		count++;

		_putchar('\n');
	}

}
