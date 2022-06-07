#include "main.h"

/**
 * _islower -  a function that checks for lowercase character.
 *
 * @c: contains value to be checked
 *
 * Description: checks for lowercase character.
 *
 * Return: Always 0 (Success).
 */

int _islower(int c)
{

	if (c > 'a' && c < 'z')
	{
		return (1);
	}

	else
	{
		return (0);
	}

}
