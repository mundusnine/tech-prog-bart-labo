#include "labo.h"

/*
struct Node
{
	Node* prev;
	void* data;
	Node* next;
};
Ajouter l'élément sur la queue/file.
*/
void push(Queue* q, Node* n)
{
	if (q->next == NULL)
	{
		q->next = n;
		q->prev = n;

		n->prev = q;
		n->next = NULL;
		return;
	}
	else
	{
		Node* temp = q->next;

		q->next = n;
		temp->prev = n;

		n->next = temp;
		n->prev = q;
	}
	
	

}

/*
* Enlever l'élément de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q)
{
	if (q->prev == NULL)
	{
		return NULL;
	}
	else if (q->prev->prev != q)
	{
		Node* temp = q->prev->prev;
		Node* copy = q->prev;

		temp->next = NULL;
		q->prev = temp;

		Node retour = *copy;

		copy = NULL;

		return &retour;
	}
}



/*
* Retourner l'élément de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'élément, retourner NULL.
*/
Node* peek(Queue* q)
{
	if (q->prev == NULL)
	{
		return NULL;
	}
	else
	{
		Node* temp = q->prev;
		return temp;
	}
}

/*
* Ajouter l'élément sur la queue/file comme si elle serait une priority queue. Utiliser l'âge afin de "trier" à chaque push.La personne au premier pop() est la plus jeune.
* On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n)
{

}


/*
* Trier la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le même algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q)
{

}