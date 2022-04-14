#include "labo.h"

/*
* Creer une HashTable, assigner lui la valeur max_size, allouer de la memoire pour la quantiter de d'information possible dans la liste data.
* Pour chaque index du tableau data, assigner la valeur NULL. Retourner ensuite le pointeur vers le HashTable.
*/
HashTable* create_hashtable(size_t max_size)
{
	HashTable* hashTable = allocate(sizeof(HashTable));
	hashTable->max_size = max_size;
	hashTable->data = allocate(sizeof(hashTable->data) * max_size);

	for (int i = 0; i < max_size; i++)
	{
		hashTable->data[i] = NULL;
	}

	return hashTable;
}

/*
* Implementer la fonction de hashing tel que vu en classe. Retourner l'index
*/
size_t hash(char* key, size_t max)
{
	int i = 0;
	size_t out = 0;
	while (key[i] != '\0')
	{
		out += key[i] * (i + 20000);
		i++;
	}
	
	out = out % max;
	return out;
}

/*
* Ajouter la cle dans le hashtable avec la valeur donner.
* Si l'operation reussi retourner 1. Si jamais il y a deja une valeur dans le tableau retourner 0.
*/
int add_kv(HashTable* table, char* key, void* data)
{
	size_t idx = hash(key, table->max_size);
	if (table->data[idx] == NULL)
	{
		table->data[idx] = data;
		return 1;
	}

	return 0;
}

/*
* Si jamais la cle se retrouve dans le tableau, on assigne la valeur du tableau a NULL et on retourne la valeur qu'il y avait dans le tableau.
* Sinon, on retourne NULL.
*/
void* del_kv(HashTable* table, char* key)
{
	size_t idx = hash(key, table->max_size);

	if (table->data[idx] != NULL)
	{
		void* data = table->data[idx];
		table->data[idx] = NULL;
		return data;
	}

	return NULL;
}

/*
* Si jamais la cle se retrouve dans le tableau,on retourne la valeur qu'il y avait dans le tableau.
* Sinon, on retourne NULL.
*/
void* get_value(HashTable* table, char* key)
{
	size_t idx = hash(key, table->max_size);

	if (table->data[idx] != NULL)
	{
		return table->data[idx];
	}

	return NULL;
}