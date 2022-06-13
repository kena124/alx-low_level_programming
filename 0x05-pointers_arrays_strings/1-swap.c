#include "main.h"

/**
 * swap_int - swaps the valuees of two integers
 *
 * @a: first number
 * @b: next number
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
