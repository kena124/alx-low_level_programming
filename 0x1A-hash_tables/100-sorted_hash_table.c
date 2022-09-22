#include "hash_tables.h"
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a hash table.
 *
 * @size: the size of hash table.
 *
 * Return: the address of the hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int index;
	shash_node_t **array;
	shash_table_t *shash_table;

	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);
	array = malloc(sizeof(shash_node_t *) * size);
	if (array == NULL)
		return (NULL);
	for (index = 0; index < size; index++)
		array[index] = NULL;
	shash_table->size = size;
	shash_table->array = array;
	shash_table->shead = NULL;
	shash_table->stail = NULL;

	return (shash_table);
}

/**
 * shash_table_set_sorted - adds an element in the sorted linked list
 *
 * @ht: the hash table
 * @new: the new node to be added
 *
 * Return: 1 on success or 0 on failure.
 */
int shash_table_set_sorted(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *shead, *stail;

	if (ht == NULL || new == NULL)
		return (0);

	shead = ht->shead;
	stail = ht->stail;

	while (shead != NULL)
	{
		if (strcmp(new->key, shead->key) < 0)
		{
			new->sprev = shead->sprev;
			new->snext = shead;
			if (shead->sprev != NULL)
			{
				shead->sprev->snext = new;
			}
			else
				ht->shead = new;
			shead->sprev = new;
			return (1);
		}
		if (strcmp(stail->key, new->key) < 0)
		{
			new->snext = stail->snext;
			new->sprev = stail;
			if (stail->snext != NULL)
				stail->snext->sprev = new;
			stail->snext = new;

			if (new->snext == NULL)
				ht->stail = new;
			return (1);
		}
		shead = shead->snext;
		stail = stail->sprev;
	}
	ht->shead = new, ht->stail = new;
	return (1);
}

/**
 * shash_table_set - adds an element to the hash table.
 *
 * @ht: the hash table data structure.
 * @key: the key for the value.
 * @value: the value associated value with the key.
 *
 * Return: 1 on success and 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int size;
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	size = ht->size;
	index = key_index((const unsigned char *)key, size);

	node = ht->array[index];

	for (; node != NULL; node = node->next)
		if (strcmp(node->key, key) == 0)
		{
			free(node->value), node->value = NULL;
			node->value = strdup(value);
			return (1);
		}

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ht->array[index];
	node->sprev = NULL;
	node->snext = NULL;
	ht->array[index] = node;

	return (shash_table_set_sorted(ht, node));
}

/**
 * shash_table_get - gives a value associated with @key
 * @ht: the hash table.
 * @key: the key.
 *
 * Return: the value associated with the @key or NULL(on failure).
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	unsigned long int size;
	shash_node_t *node;

	if (ht == NULL)
		return (NULL);
	size = ht->size;
	index = key_index((const unsigned char *)key, size);

	node = ht->array[index];

	for (; node != NULL; node = node->next)
		if (strcmp(node->key, key) == 0)
			return (node->value);

	return (NULL);
}

/**
 * shash_table_print - print the hash table in sorted order.
 *
 * @ht: the hash table.
 *
 * Return: void.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *shead;

	if (ht == NULL)
		return;


	shead = ht->shead;
	printf("{");

	while (shead != NULL)
	{
		printf("'%s': '%s'", shead->key, shead->value);

		shead = shead->snext;
		if (shead != NULL)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - print the hash table in reversed.
 *
 * @ht: the hash table.
 *
 * Return: void.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *stail;

	if (ht == NULL)
		return;

	stail = ht->stail;
	printf("{");

	while (stail != NULL)
	{
		printf("'%s': '%s'", stail->key, stail->value);

		stail = stail->sprev;
		if (stail != NULL)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes the sorted hash table.
 *
 * @ht: the sorted hash table
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int size, index;
	shash_node_t *node, *prev;

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
}
