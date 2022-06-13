#include "main.h"
#include "2-strlen.c"

/**
 * rev_string - print a string in a reverse order
 *
 * @s: the string
 * Return: void
 *
 */

void rev_string(char *s)
{
	int len;
	int count;
	char temp;
	int end_index;

	len = _strlen(s);
	count = 0;

	while (count < len / 2)
	{
		end_index = len - (count + 1);
		temp = *(s + count);
		*(s + count) = *(s + end_index);
		*(s + end_index) = temp;
		count++;
	}
}

