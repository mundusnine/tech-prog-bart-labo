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
	if (head->data != NULL)
	{
		Node* newNode = allocate(sizeof(Node));
		newNode->data = newData;
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev = newNode;
	}
	else
	{
		head->data = newData;
	}
}
/*
* Cr�er un noeud et l'ajouter apr�s le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	if (head->data != NULL)
	{
		Node* newNode = allocate(sizeof(Node));
		newNode->data = newData;
		newNode->prev = head;
		newNode->next = head->next;
		head->next = newNode;
		//Init pour la premiere fois le head.prev
		if (head->prev == NULL)
		{
			head->prev = newNode;
		}
	}
	else
	{
		head->data = newData;
	}
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune r�f�rence(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode)
{
	Node* RemoveNode = currNode;
	Node* PreviousNode = currNode->prev;
	Node* NextNode = currNode->next;

	RemoveNode->next = NULL;
	RemoveNode->prev = NULL;
	PreviousNode->next = NextNode;
	NextNode->prev = PreviousNode;

	return RemoveNode;
}

void alphabetise(Node* head, char* names[])
{}