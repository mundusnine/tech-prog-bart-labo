#include "labo.h"
/*
typedef struct {
	void** data;
	size_t max_size;

}HashTable;
*/
/*
* Creer une HashTable, assigner lui la valeur max_size, 
allouer de la memoire pour la quantiter de d'information possible dans la liste data.
* Pour chaque index du tableau data, assigner la valeur NULL. Retourner ensuite le pointeur vers le HashTable.
*/
HashTable* create_hashtable(size_t max_size)
{
	HashTable* newHash = allocate(sizeof(HashTable));
	newHash->max_size = max_size;

	newHash->data = allocate(sizeof(newHash->data) * max_size);


	for (int i = 0; i < max_size; i++)
	{
		
		newHash->data[i] = NULL;
		
	}


	return newHash;
}

/*
* Implementer la fonction de hashing tel que vu en classe. Retourner l'index
*/
size_t hash(char* key, size_t max)
{
	size_t sumSize = 0;
	int i = 0;
	while (key[i] != '\0')
	{
		sumSize += key[i] * (i  + 150000);
		i++;
	}

	sumSize = sumSize % max;
	return sumSize;
}

/*
* Ajouter la cle dans le hashtable avec la valeur donner.
* Si l'operation reussi retourner 1. Si jamais il y a deja une valeur dans le tableau retourner 0.
*/
int add_kv(HashTable* table, char* key, void* data)
{
	size_t keyPos = hash(key, table->max_size);

	if (table->data[keyPos] == NULL)
	{
		table->data[keyPos] = data;
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
	size_t keyPos = hash(key, table->max_size);

	if (table->data[keyPos] != NULL)
	{
		void* data = table->data[keyPos];
		table->data[keyPos] = NULL;
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
	size_t keyPos = hash(key, table->max_size);

	if (table->data[keyPos] != NULL)
	{
		return table->data[keyPos];

	}
	else
	{
		return NULL;
	}
}