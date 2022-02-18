#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"


/*
* Cr�er un noeud et l'ajouter apr�s le noeud currNode. Consid�rer la propri�t� next et prev.
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
* Cr�er un noeud et l'ajouter apr�s le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData)
{
	
}