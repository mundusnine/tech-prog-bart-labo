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
	n->next = NULL;
	currNode->next = n;
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
		n->next = head->next;
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
	
	while (n != NULL)
	{
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
			previousNode = n;
			n = n->next;
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
	Node* nPrev = head;
	Person* p = n->data;

	while (n != NULL)
	{
		if (p->name == name)
		{
			memset(n, 0, sizeof(Node));
			return nPrev;
		}
		else
		{
			nPrev = n;
			n = n->next;
			p = n->data;
		}
	}
}
/*
* Trier par l'�ge. Utiliser l'algorithme que vous connaissez le mieux.
*/

//le sort semble fonctionner, le probleme doit venir d'ailleur dans mes fonctions.
void sort(Node* head) 
{
	Node* n = head;
	Person* p = n->data;
	Person* pNext = n->next->data;
	int nbElements = 0;

	while (n != NULL)
	{
		nbElements++;
		n = n->next;
	}

	n = head;

	int switched = 0;

	for (int i = 0; i < (nbElements - 1); i++)
	{
		if (p->age > pNext->age)
		{
			Person* temp = n->data;
			n->data = n->next->data;
			n->next->data = temp;
			switched = 1;
		}
		if (switched == 1)
		{
			switched = 0;
			i = -1;
			n = head;
			p = n->data;
			pNext = n->next->data;
		}
		else
		{
			n = n->next;
			p = n->data;
			if (n->next != NULL)
			{
				pNext = n->next->data;
			}
		}
	}
}