#include "hash_tables.h"

/**
 * key_index - gives the index of the a key
 *
 * @size: the size of the array of the hash table.
 * @key: the key
 *
 * Return: the index at which the key/value pair should be
 * stored in the array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int index;

	hash_value = hash_djb2(key);

	index = hash_value % size;

	return (index);
}
