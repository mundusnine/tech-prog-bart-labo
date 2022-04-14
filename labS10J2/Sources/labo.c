#include "labo.h"

/*
* Creer une HashTable, assigner lui la valeur max_size, allouer de la memoire pour la quantiter de d'information possible dans la liste data.
* Pour chaque index du tableau data, assigner la valeur NULL. Retourner ensuite le pointeur vers le HashTable.
*/
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

/*
* Implementer la fonction de hashing tel que vu en classe. Retourner l'index
*/
size_t hash(char* key, size_t max)
{
	size_t out = 0;
	size_t i = 0;

	while (key[i]!='\0')
	{
		out += key[i] * ((i + 1) + UINT32_MAX);
		i++;
	}
	return out % max;
}

/*
* Ajouter la cle dans le hashtable avec la valeur donner.
* Si l'operation reussi retourner 1. Si jamais il y a deja une valeur dans le tableau retourner 0.
*/
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

/*
* Si jamais la cle se retrouve dans le tableau, on assigne la valeur du tableau a NULL et on retourne la valeur qu'il y avait dans le tableau.
* Sinon, on retourne NULL.
*/
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

/*
* Si jamais la cle se retrouve dans le tableau,on retourne la valeur qu'il y avait dans le tableau.
* Sinon, on retourne NULL.
*/
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