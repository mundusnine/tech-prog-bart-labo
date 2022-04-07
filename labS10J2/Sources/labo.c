#include"labo.h"

HashTable* create_hashtable(size_t max_size)
{
	HashTable* newTable = allocate(sizeof(HashTable));
	newTable->data = allocate(sizeof(void*) * max_size);
	newTable->max_size = max_size;
	for (int i = 0; i < max_size; i++)
	{
		newTable->data[i] = NULL;
	}
	return newTable;
}

size_t hash(char* key, size_t max)
{
	size_t out = 0;
	size_t i = 0;
	
	while (key[i] != '\0')
	{
		out += key[i] * ((i + 1) + UINT32_MAX);
		i++;
	}

	return out % max;
}

int add_kv(HashTable* table, char* key, void* data)
{
	int index = hash(key, table->max_size);
	if (index < table->max_size && table->data[index] == NULL)
	{
		table->data[index] = data;
		return 1;
	}
	else
	{
		return 0;
	}
}

void* del_kv(HashTable* table, char* key)
{
	int index = hash(key, table->max_size);
	if (index < table->max_size)
	{
		void* data = table->data[index];
		table->data[index] = NULL;
		return data;
	}
	else
	{
		return NULL;
	}
}

void* get_value(HashTable* table, char* key)
{
	int index = hash(key, table->max_size);
	if (index < table->max_size)
	{
		return table->data[index];
	}
	else
	{
		return NULL;
	}
}