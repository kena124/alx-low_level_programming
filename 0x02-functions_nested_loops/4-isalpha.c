#include "main.h"

/**
 * _isalpha - Check for alphabetic character
 *
 * @c: An input character to be checked
 *
 * Description: a function that checks for alphabetic character.
 *
 *
 * Return: 1 or 0 .
 */

int _isalpha(int c)
{

	if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z'))
	{
		return (1);
	}

	else
	{
		return (0);
	}

}
