#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retreives a value associated with a key.
 * @ht: the hash table we want to look into.
 * @key: the key we are looking into.
 *
 * Return: the value associated with the element, or
 * NULL (if key couldn't be found)
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int size;
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	size = ht->size;
	index = key_index((const unsigned char *) key, size);
	node = ht->array[index];

	for (; node != NULL; node = node->next)
		if (strcmp(node->key, key) == 0)
			return (node->value);
	return (NULL);
}
