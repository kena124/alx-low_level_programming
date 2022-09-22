#include "hash_tables.h"
#include <stdio.h>

#define PRINT 1
#define NOTPRINT 0


/**
 * hash_table_print - prints a hash table.
 *
 * @ht: the hash table.
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int size;
	unsigned long int index;
	hash_node_t *node;
	short bool;

	if (ht == NULL)
		return;


	size = ht->size;
	bool = NOTPRINT;

	printf("{");
	for (index = 0; index < size; index++)
	{
		node = ht->array[index];

		if (node == NULL)
			continue;
		if (bool == PRINT && index < size)
		{
			printf(", ");
			bool = NOTPRINT;
		}

		for (; node != NULL; node = node->next)
		{
			printf("'%s': '%s'", node->key, node->value);
			bool = PRINT;
			if (node->next != NULL)
				printf(", ");
		}

	}
	printf("}\n");
}
