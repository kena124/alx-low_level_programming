#include "main.h"

/**
 * _memcpy - copy memory
 *
 * @dest: the destination memory
 * @src: the source memory
 * @n: length of the memory
 *
 * Return: the address
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
