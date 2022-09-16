#include "lists.h"

/**
 * sum_dlistint - get sum of data in doubly linked list
 * @head: pointer to head of doubly linked list
 * Return: sum
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *temp;

	if (!head)
		return (0);

	temp = head;
	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
