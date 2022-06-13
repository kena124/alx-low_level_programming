#include <stdio.h>
#include "main.h"

/**
 * print_array -  prints n elements of an array of
 * integers, followed by a new line.
 *
 * @a: array of integer
 * @n: the starting of the index
 * Return: void
 *
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			printf("%d, ", *(a + i));
		else
			printf("%d", *(a + i));
	}
	printf("\n");
}


