#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: the string
 *
 * Return: the number
 */

int _atoi(char *s)
{
	unsigned int count, parity = 1, temp = 0;

	for (count = 0; *(s + count) != 0; count++)
	{
		if (*(s + count) == 45)
			parity *= -1;
		if (*(s + count) >= 48 && *(s + count) <= 57)
		{
			temp = (temp * 10) + (*(s + count) - 48);

			if (*(s + count + 1) < 48 || *(s + count + 1) > 57)
			{
				break;
			}
		}
	}
	return (temp * parity);
}
