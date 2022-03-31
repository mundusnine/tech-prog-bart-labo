#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, visited a faux, len a 0, allouer de la m�moire pour le QNode et assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data)
{
	Node* newNode = allocate(sizeof(Node));
	newNode->data = data;
	memset(newNode->adj,0, sizeof(QNode));
	newNode->visited = 0;
	newNode->len = 0;
	newNode->revPath = allocate(sizeof(QNode));
	newNode->revPath->data = NULL;
	newNode->revPath->prev = NULL;
	newNode->revPath->next = NULL;
	newNode->revPath->count = 0;
	return newNode;
}

/*
* Ajouter le node dans la liste d'adjacence de root.
*/

void add_adjacent_node(Node* root, Node* node)
{
	root->adj[root->len++] = node;
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
* La Stack devrait contenir la liste en ordre inverse de celle parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner C -> B -> A
*/

int dfs(Node* root[], int len, Node* curr, void* key, Stack* s)
{
	if (curr == NULL)
	{
		for (int i = 0; i < len; i++)
		{
			dfs(root, len, root[i], key, s);
		}
	}



	
	
	return 0;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/

int bfs(Node* root[], void* key, Stack* s)
{
	return 0;
}
