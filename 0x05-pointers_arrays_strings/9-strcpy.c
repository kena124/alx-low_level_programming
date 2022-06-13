#include "main.h"

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 *
 * @dest: destination of the string
 * @src: source of the string
 *
 * Return: value of the pointer to the dest
 */

char *_strcpy(char *dest, char *src)
{
	int count;

	count = 0;

	while (*(src + count))
	{
		*(dest + count) = *(src + count);
		count++;
	}
	*(dest + count) = '\0';

	return (dest);
}
