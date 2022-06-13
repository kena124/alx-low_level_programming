#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random password
 * Return: Always 0
 */

int main(void)
{
	int r = 0, count = 0;
	time_t t;

	srand((unsigned int) time(&t));
	while (count < 2772)
	{
		r = rand() % 128;
		if ((count + r) > 2772)
			break;
		count = count + r;
		printf("%c", r);
	}
	printf("%c\n", (2772 - count));
	return (0);
}
