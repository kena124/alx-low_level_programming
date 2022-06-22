#include "main.h"

/**
 * _memset - fill memory
 *
 * @s: th memory location
 * @b: the byte
 * @n: length of the memory
 *
 * Return: the address
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}
