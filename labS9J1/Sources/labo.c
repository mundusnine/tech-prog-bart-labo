#include "labo.h"

/*
* Creer un Noeud, assigner lui la valeur de data, faite un memset 0 sur adj, visited a faux, len a 0, allouer de la memoire pour le QNode et
* assurer vous de mettre la propiete prev de QNode a NULL.
* Retourner ensuite le pointeur vers le Node.
*/
Node* create_node(void* data)
{
	Node* myNode = allocate(sizeof(Node));
	myNode->data = data;
	memset(myNode->adj,0,sizeof(Node*)* UINT8_MAX);

	myNode->visited = 0;
	myNode->len = 0;
	QNode* myQNode = allocate(sizeof(QNode));
	myQNode->prev = NULL;
	myQNode->data = NULL;
	myNode->revPath = myQNode;
	return myNode;
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
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
* La Stack devrait contenir la liste en ordre inverse de celle parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner C -> B -> A
*/
int dfs(Node* root[], int len, Node* curr, void* key, Stack* s)
{
	if (curr == NULL)
	{
		int verif = 0;
		for (int i = 0; i < len; i++)
		{
			verif = dfs(root, len, root[i], key, s);
			if (verif != 0)
			{
				break;
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
			int count =0;
			for (int i = 0; i < curr->len; i++)
			{
				if (curr->adj[i]->visited == 0)
				{
					int verif = 0;
					verif = dfs(root, len, curr->adj[i], key, s);
					if (verif != 0)
					{
						return verif;
					}
				}
				count++;
				if (count == curr->len)
				{
					stack_pop(s);
					return 0;
				}
			}
		}
	}
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s)
{
	/*
		1 push premier dans la q
			node* n = root;
		2 while (n != NULL)
			n =  q_pop(q)
			for(adj)
				q_push(adj)
				node adj.revpath =
			n.visited =1;
			if(n.data == key)
				break
			if(n == NULL)
				bad
			else
				good
	*/
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);

	Node* n = root[0];
	queue_push(q, n);

	int count = 0;
	while (n != NULL)
	{
		n = queue_pop(q);
		n->visited = 1;
		count++;
		if (n->data == key)
		{
			break;
		}
		for (int i = 0; i < n->len; i++)
		{
			if (!n->adj[i]->visited) 
			{
				queue_push(q, n->adj[i]);
				if (n->adj[i]->revPath->data == NULL)
				{
					n->adj[i]->revPath->data = n;//THIS
				}
			}
		}
	}
	while (n != NULL)
	{
		stack_push(s, n);
		n = n->revPath->data;
	}
	return count;
}