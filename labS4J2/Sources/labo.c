
#include "labo.h"


/*
* Ajouter l'�l�ment sur la queue/file.
*/
void push(Queue* q, Node* n)
{
	if(q != NULL)
	{ 
	
	}
	else
	{
		q->data = n->data;
		q->next = NULL;
		q->prev = q;
	}
}

/*
* Enlever l'�l�ment de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q)
{

}


/*
* Retourner l'�l�ment de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
Node* peek(Queue* q)
{

}

/*
* Ajouter l'�l�ment sur la queue/file comme si elle serait une priority queue. Utiliser l'�ge afin de "tri�" � chaque push.La personne au premier pop() est la plus jeune.
* On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n)
{

}


/*
* Tri�e la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le m�me algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q)
{

}