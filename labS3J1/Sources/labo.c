#include "labo.h"
#include <stdio.h>
#include <stdlib.h>



/*
* Cr�er un noeud et l'ajouter apr�s le noeud currNode. Utiliser la fonction allocate pour allouer de la m�moire.
*/
void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	currNode->next = n;
	n->next = NULL;
}
/*
* Cr�er un noeud et l'ajouter apr�s le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
	}
	else
	{
		Node* n = allocate(sizeof(Node));
		n->data = newData;
		n->next = NULL;
		head->next = n;
	}
}

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicit�, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData)
{
	Node* n = head;
	Node* previousNode = head;
	int iterator = 1;
	while (n != NULL)
	{
		if (iterator > 2)
		{
			previousNode = previousNode->next;
		}
		if (n->data == rmData)
		{
			if (n == head)
			{
				return head;
			}
			else
			{
				memset(n, 0, sizeof(Node));
				return previousNode;
			}
		}
		else
		{
			n = n->next;
			iterator++;
		}
	}
}
/*
* Supprimer le noeud ayant le nom passer par name. Par simplicit�, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name) //le data dans Node est une personne de la struct person_t
{
	Node* n = head;
	Person* p = n->data;
	Person* p2;

	while (n != NULL)
	{
		if (p->name == name)
		{
			if (p == head->data)
			{
				return head;
			}
			else
			{
				memset(n, 0, sizeof(Node));
				return p2;
			}
		}
		else
		{
			p2 = p;
			n = n->next;
			p = n;
		}
	}
}
/*
* Trier par l'�ge. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head)
{
	Node* n = head;
	Person* p = n->data;
	int nbElements = 0;

	while (n != NULL)
	{
		nbElements++;
		n = n->next;
	}

	n = head;
	p = n->data;
	
	for (int i = 1; i < nbElements; i++)
	{
		int y = i;
		while(y > 0 && )
	}
}