#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, visited a faux, len a 0, allouer de la m�moire pour le QNode et assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data)
{
	Node* noeud = allocate(sizeof(Node));
	noeud->data = data;
	memset(noeud->adj, 0, sizeof(noeud->adj));
	noeud->visited = 0;
	noeud->len = 0;
	noeud->revPath = allocate(sizeof(Node));
	noeud->revPath->prev = NULL;
	noeud->revPath->next = NULL;
	noeud->revPath->count = 0;
	return noeud;
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
	int x = 0;

	if (curr == NULL)
	{
		for (int i = 0; i < len; i++)
		{
			x = dfs(root, len, root[i], key, s);
			if (x == 1)
			{
				break;
			}
		}
		return s->top;
	}
	else
	{
		stack_push(s, curr);
		curr->visited = 1;
		if (curr->data == key)
		{
			return 1;
		}
		for (int i = 0; i < curr->len; i++)
		{
			if (curr->adj[i]->visited == 0)
			{
				x = dfs(root, len, curr->adj[i], key, s);
				if (x == 1)
				{
					return x;
				}
			}
			if (i == curr->len - 1 && curr->adj[i]->visited == 1)
			{
				stack_pop(s);
			}
		}
		return 0;
	}
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s)
{

}