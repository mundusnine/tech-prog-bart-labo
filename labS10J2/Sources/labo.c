#include "labo.h"

HashTable* create_hashtable(size_t max_size)
{
	HashTable* hash = allocate(sizeof(HashTable));
	hash->max_size = max_size;
	hash->data = allocate(sizeof(hash->data) * max_size);

	for (int i = 0; i < max_size; i++)
	{
		hash->data[i] = NULL;
	}

	return hash;
}

size_t hash(char* key, size_t max)
{
	int i = 0;
	size_t idx = 0;
	while (key[i] != '\0')
	{
		idx += key[i] * (i + 999999999999999999);
		i++;
	}
	
	idx = idx % max;
	return idx;
}

int add_kv(HashTable* table, char* key, void* data)
{
	int position = hash(key, table->max_size);

	if (table->data[position] == NULL)
	{
		table->data[position] = data;
		return 1;
	}
	else
	{
		return 0;
	}
}

void* del_kv(HashTable* table, char* key)
{
	int position = hash(key, table->max_size);

	if (table->data[position] != NULL)
	{
		void* data = table->data[position];
		table->data[position] = NULL;
		return data;
	}
	else
	{
		return NULL;
	}
}

void* get_value(HashTable* table, char* key)
{
	int position = hash(key, table->max_size);

	if (table->data[position] != NULL)
	{

		return table->data[position];
	}
	else
	{
		return NULL;
	}
}

