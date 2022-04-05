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
			int found = dfs(root, len, root[i], key, s);
			if (found != 0)
			{
				return s->top;
			}
		}
	}

	else
	{
		curr->visited = 1;
		stack_push(s, curr);
		if (curr->data == key)
		{
			return 1;
		}
		else
		{
			for (int i = 0; i < curr->len; i++)
			{
				if (curr->adj[i]->visited != 1)
				{
					int found = dfs(root, len, curr->adj[i], key, s);
					if (found != 0)
					{
						return 1;
					}
				}
			}
			stack_pop(s);
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
	while (s->top != -1)
	{
		stack_pop(s);
	}
	
	Node* n = root[0];
	
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	queue_push(q, n);
	
	while (n != NULL)
	{
		n = queue_pop(q);
		n->visited = 1;
		if (n->data == key)
		{
			break;
		}
		
		for (int i = 0; i < n->len; i++)
		{
			if (n->adj[i]->visited != 1)
			{
				queue_push(q, n->adj[i]);
				n->adj[i]->revPath->data = n;
			}
		}
	}

	if (n == NULL)
	{
		return 0;
	}
	else
	{
		while (n != NULL)
		{
			stack_push(s, n);
			n = n->revPath->data;
		}
		return s->top + 1;
	}
}
