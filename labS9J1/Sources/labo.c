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
	n->revPath = allocate(sizeof(n->revPath));
	n->revPath->prev = NULL;

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

// fonctionnel
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s)
{
	Node* temp = root[0];
	while (temp->data != key)
	{
		stack_push(s, temp); // +1
		temp->visited = 1;

		
		int count = 0;
		for (int i = 0; i < temp->len; i++)
		{
			if (temp->adj[i]->visited == 0)
			{
				temp = temp->adj[i];
				break;
			}
			count++;
		}

		if (temp->len == count)
		{
			stack_pop(s); // -1
			temp = stack_pop(s);

		}
	}

	// Lorsque while est vrai
	stack_push(s, temp);



	/*
	stack_push(s, root[0]);
	root[0]->visited = 1;
	if (root[0]->data == key)
	{
		return;
	}

	// E
	Node* temp = root[0]->adj[0];
	stack_push(s, temp);
	temp->visited = 1;
	if (temp->data == key)
	{
		return;
	}

	// f
	if (temp->len > 0 && temp->adj[0]->visited == 0)
	{
		temp = temp->adj[0];
		stack_push(s, temp);
		temp->visited = 1;
		if (temp->data == key)
		{
			return;
		}
	}

	// Si son voisin est visité, va visiter le 2e s'il en a un et n'est pas visité
	if (temp->len > 0 && temp->adj[0]->visited == 1)
	{
		if (temp->len > 1 && temp->adj[1]->visited == 0)
		{
			temp = temp->adj[1];
			stack_push(s, temp);
			temp->visited = 1;
			if (temp->data == key)
			{
				return;
			}
		}
		else // Sinon ça chie, donc retourner a root
		{
			temp = root[0];
		}
	}

	temp = stack_pop(s); 

	temp = stack_pop(s);
	*/

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