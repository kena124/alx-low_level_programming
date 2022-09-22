#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 *
 * @ht: the hash table.
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int size;
	unsigned long int index;
	hash_node_t *node, *prev;

	if (ht == NULL)
		return;

	size = ht->size;

	for (index = 0; index < size; index++)
	{
		node = ht->array[index];
		prev = NULL;

		while (node != NULL)
		{
			prev = node, node = node->next;
			free(prev->key), free(prev->value), free(prev);
			prev = NULL;
		}
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}
