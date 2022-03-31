#include "labo.h"

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
* La Stack devrait contenir la liste en ordre du chemin parcouru. i.e. si le chemin est A -> B -> C la stack avec son pop devrait retourner A -> B -> C
*/
int bfs(Node* root[], void* key, Stack* s)
{
	Queue* q;
	queue_init(q);
	queue_push(q, root[0]);
	Node* n = root[0];
	while (n!=NULL)
	{
		n = queue_pop(q);
		n->visited = 1;
		if (n->data == key)
		{
			break;
		}
		for (int i = 0; i < n->len; i++)
		{
			queue_push(q, n->adj[i]);
			
		}
	}
	if (n == NULL)
	{
		return 0;
	}
	else
	{
		

	}

}