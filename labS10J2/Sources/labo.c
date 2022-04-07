#include "labo.h"

HashTable* create_hashtable(size_t max_size)
{
	HashTable* table = allocate(sizeof(HashTable));
	table->max_size = max_size;
	table->data = allocate(sizeof(void*) * table->max_size);

	for (int i = 0; i < table->max_size; i++)
	{
		table->data[i] = NULL;
	}

	return table;
}

size_t hash(char* key, size_t max)
{
	int out = 0;
	int index = 0;

	while (key[index] != '\0')
	{
		out += key[index] * (index + UINT32_MAX);
		index++;
	}

	return out % max;
}

int add_kv(HashTable* table, char* key, void* data)
{
	int index = hash(key, table->max_size);
	if (table->data[index] == NULL)
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
	if (table->data[index] == NULL)
	{
		return NULL;
	}
	else
	{
		void* returnData = table->data[index];
		table->data[index] = NULL;
		return returnData;
	}
}

void* get_value(HashTable* table, char* key)
{
	int index = hash(key, table->max_size);
	if (table->data == NULL)
	{
		return NULL;
	}
	else
	{
		return table->data[index];
	}
}