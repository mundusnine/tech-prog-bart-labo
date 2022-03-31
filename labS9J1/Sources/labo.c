#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, 
visited a faux, len a 0, 
allouer de la m�moire pour le QNode et 
assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data)
{
	Node* n = allocate(sizeof(Node));
	n->data = data;
	memset(n->adj, 0, 1);
	n->len = 0;
	n->visited = 0;
	allocate(sizeof(n->revPath));
	n->revPath.prev = NULL;

	return n;
}

/*
* Ajouter le node dans la liste d'adjacence de root.
*/
void add_adjacent_node(Node* root, Node* node)
{
	root->adj[root->len] = node;
	root->len++;
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. 
Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
* La Stack devrait contenir la liste en ordre inverse de celle parcouru. 
	i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner C -> B -> A
*/
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s)
{
	Node* current = root[0];


	// Check initial 
	stack_push(s, current);
	current->visited = 1;
	if (key == current->data)
	{
		return;
	}
	// Ici, on a regardé si la node #1 contenait la key

	int pos = 0;
	int Adjpos = 0;
	
	
	// Boucle pour les nodes (len - 1) restants
	for (int i = 0; i < len-1; i++)
	{
		// si la node adjacente au current est != NULL et n'est pas visitée
		if (current->adj[Adjpos] != NULL && current->adj[Adjpos]->visited == 0)
		{
			current = current->adj[Adjpos];
			current->visited = 1;
			stack_push(s, current);

			if (current->data == key)
			{
				return;
			}
		}
		else if (current->adj[Adjpos] != NULL 
			&& current->adj[Adjpos]->visited != 0)
		{
			Adjpos++;
			i--;
		}
	}
	
	
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. 
Pour programmer cet algorithme, vous avez besoins d'une file/queue, sa definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. 
	i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s)
{

}