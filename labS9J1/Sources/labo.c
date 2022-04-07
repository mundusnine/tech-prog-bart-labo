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
	while (temp->data != key) // Tant que la clé n'est pas trouvée
	{
		temp->visited = 1;
		int lenComp = 0;
		for (int i = 0; i < temp->len; i++)
		{
			if (temp->adj[i]->visited == 1)
			{
				lenComp++;
			}
		}

		if (lenComp == temp->len)
		{
			temp = stack_pop(s);
		}
		else
		{
			stack_push(s, temp); 
		
		}
		
		
		int count = 0;
		for (int i = 0; i < temp->len; i++) // Pour une qte de fois = à la qte de nodes adjacentes
		{
			if (temp->adj[i]->visited == 0) // Si la node adjacente n'est pas visitée
			{
				temp = temp->adj[i]; // Temp = son adjacente
				break;
			}
			count++;
		}
		

		if (temp->len == count)
		{
			int adjCount = 0;
			for (int i = 0; i < temp->len; i++)
			{
				if (temp->adj[i]->visited == 1)
				{
					adjCount = 1;
				}
			}

			if (adjCount != 1)
			{
				temp = stack_pop(s);
			}
		}
	}

	stack_push(s, temp);
}

/*
Programmer l'algorithme de breath first search afin de trouver la cle. 
Pour programmer cet algorithme, vous avez besoins d'une file/queue, 
	sa definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. 
	i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s) // Queue first in first out ***
{
	while (s->top != -1)
	{
		stack_pop(s);
	}
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	queue_push(q, root[0]);
	Node* t = NULL;

	int o = 1;
	while (o)
	{
		t = queue_pop(q);
		t->visited = 1;

		if (t->data == key)
		{
			break;
		}
		for (int i = 0; i < t->len; i++)
		{
			if (t->adj[i]->visited == 0)
			{
				queue_push(q, t->adj[i]);
				t->adj[i]->revPath->data = t;
			}
			
		}
	}
	
	int nodes_visited = 0;
	while (t != root[0])
	{
		stack_push(s, t);
		t = t->revPath->data;
		nodes_visited++;
	}
	stack_push(s, t);
	nodes_visited++;

	return nodes_visited;

	
}

