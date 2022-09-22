#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 *
 * @size: the size of the array.
 *
 * Return: a pointer to the newly created hash table.
 *         on failure it returns NULL.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int count = 0;
	hash_node_t **array;
	hash_table_t *hash_table;

	hash_table = malloc(sizeof(hash_table_t));

	if (hash_table == NULL)
		return (NULL);

	array = malloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (; count < size; count++)
		array[count] = NULL;

	hash_table->size = size;
	hash_table->array = array;

	return (hash_table);
}
