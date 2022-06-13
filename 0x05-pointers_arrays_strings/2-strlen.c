#include "main.h"

/**
 * _strlen - finds the length of a string
 *
 * @s: array of character
 *
 * Return: the length of the string
 *
 */

int _strlen(char *s)
{
	int len;

	len = 0;

	while (*(s + len))
	{
		++len;
	}

	return (len);
}

