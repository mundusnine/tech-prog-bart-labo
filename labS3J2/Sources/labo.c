#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"


/*
* Créer un noeud et l'ajouter après le noeud currNode. Considérer la propriété next et prev.
*/
void insert(Node* currNode, void* newData)
{
	Node* newNode = allocate(sizeof(Node));
	newNode->data = newData;
	newNode->prev = currNode;
	newNode->next = currNode->next;
	currNode->next = newNode;
}

/*
* Créer un noeud et l'ajouter après le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData)
{
	
}