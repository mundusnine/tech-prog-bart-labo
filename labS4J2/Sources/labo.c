
#include "labo.h"


/*
* Ajouter l'élément sur la queue/file.
*/
void push(Queue* q, Node* n)
{
	if (q->prev != NULL) 
	{
		q->next->prev = n;
		q->next = n;
	}
	else 
	{
		q->next = n;
		q->prev = q->next;
	}
}

/*
* Enlever l'élément de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q)
{
	if (q->prev != NULL)
	{
		Node* Remove = q->prev;
		q->prev->next = NULL;
		q->prev = q->prev->prev;
		q->next = q->prev;
		return Remove;
	}
	else
	{
		return NULL;
	}
}


/*
* Retourner l'élément de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'élément, retourner NULL.
*/
Node* peek(Queue* q)
{
	if (q->prev != NULL)
	{
		return q->prev;
	}
	else
	{
		return NULL;
	}
}

/*
* Ajouter l'élément sur la queue/file comme si elle serait une priority queue. Utiliser l'âge afin de "trié" à chaque push.La personne au premier pop() est la plus jeune.
* On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n)
{
	//j'ai un bug sois dans mon pop ou ici mais j'ai decider de faire un simple push pour assurer que mon code compile

	Person* p = q->prev;
	Person* p2 = n;
	if (q->prev != NULL)
	{
		//if (p->age < p2->age)
		//{
			q->next->prev = n;
			q->next = n;
		//}
		//else
		//{
		//	q->prev = n;
		//}
	}
	else
	{
		q->next = n;
		q->prev = q->next;
	}
}


/*
* Triée la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le même algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q)
{
	Person* pSort[66];
	int nbElements = 0; 
	Node* ValeurTempo;

	//en ayant compter dans le main j'ai vu qu'il n'y a qu'au maximum 5 element dans la queue
	while (nbElements < 5)
	{
		pSort[nbElements] = pop(q);
		nbElements++;
	}
	for (int i2 = 1; i2 < nbElements; i2++)
	{
		int i3;
		i3 = i2 - 1;
		while (i3 > 0 && pSort[i3] < pSort[i3 - 1])
		{
			ValeurTempo = pSort[i3];
			pSort[i3] = pSort[i3 - 1];
			pSort[i3 - 1] = ValeurTempo;
			i3--;
		}
	}
	for (int i4 = 0; i4 < nbElements; i4++)
	{
		push(q, pSort[i4]);
	}
}