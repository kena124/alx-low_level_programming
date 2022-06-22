#include "main.h"

/**
 * _strchr - locate a character
 *
 * @s: the string
 * @c: the character
 *
 * Return: the location of the character
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			return (s + i);
		}
		i++;
	}

	if (*(s + i) == c)
	{
		return (s + i);
	}
	return ('\0');
}
