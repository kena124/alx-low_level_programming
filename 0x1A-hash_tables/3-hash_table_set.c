#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds an element to the hash table.
 *
 * @ht: the hash table data structure.
 * @key: the key.
 * @value: the value associated with key.
 *
 * Return: 1 on success 0 (otherwise).
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	unsigned long int size;
	hash_node_t *node;

	if (key == NULL || value == NULL || ht == NULL || *key == '\0')
		return (0);

	size = ht->size;
	index = key_index((const unsigned char *)key, size);

	node = ht->array[index];

	for (; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = NULL;
			node->value = strdup(value);
			return (1);
		}
	}

	node = malloc(sizeof(hash_node_t));

	if (node == NULL)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
