#include "labo.h"


/*
* Creer une HashTable, assigner lui la valeur max_size, 
* allouer de la memoire pour la quantiter de d'information possible dans la liste data.
* Pour chaque index du tableau data, assigner la valeur NULL. 
* Retourner ensuite le pointeur vers le HashTable.
*/
HashTable* create_hashtable(size_t max_size)
{
	HashTable* myHashTable = allocate(sizeof(HashTable));
	myHashTable->max_size = max_size;
	myHashTable->data = allocate(sizeof(void*) * max_size);
	for (int i = 0; i < max_size; i++)
	{
		myHashTable->data[i] = NULL;
	}
	return myHashTable;
}

/*
* Implementer la fonction de hashing tel que vu en classe. Retourner l'index
*/
size_t hash(char* key, size_t max)
{
	size_t i = 0;
	size_t calculatedIndex = 0;

	while (key[i] != '\0')
	{
		calculatedIndex += key[i] * ((i + 1) + UINT32_MAX);
		i++;
	}
	return calculatedIndex % max;
}

/*
* Ajouter la cle dans le hashtable avec la valeur donner.
* Si l'operation reussi retourner 1. Si jamais il y a deja une valeur dans le tableau retourner 0.
*/
int add_kv(HashTable* table, char* key, void* data)
{
	size_t theChosenIndex = hash(key, table->max_size);

	if (table->data[theChosenIndex] == NULL)
	{
		table->data[theChosenIndex] = data;
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
	size_t theChosenIndex = hash(key, table->max_size);

	void* TempoData = table->data[theChosenIndex];
	table->data[theChosenIndex] = NULL;
	return TempoData;
}

/*
* Si jamais la cle se retrouve dans le tableau,on retourne la valeur qu'il y avait dans le tableau.
* Sinon, on retourne NULL.
*/
void* get_value(HashTable* table, char* key)
{
	size_t theChosenIndex = hash(key, table->max_size);

	void* TempoData = table->data[theChosenIndex];
	return TempoData;
}