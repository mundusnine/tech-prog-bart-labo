#include <assert.h>
#include <stdint.h>
#include "labo.h"


/*
* Créer un noeud et l'ajouter après le noeud currNode. Considérer la propriété next et prev.
*/
void insert(Node* currNode, void* newData)
{
	Node* NewNode = allocate(sizeof(Node));
	NewNode->data = newData;
	NewNode->prev = currNode;
	NewNode->next = currNode->next;

	
	currNode->next = NewNode;

	if (NewNode->next != NULL)
	{
		Node* OtherNode = NewNode->next;
		OtherNode->prev = NewNode;
	}
	
	HeadLast(currNode);
}

/*
* Créer un noeud et l'ajouter après le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
		return;
	}
	
	Node* NewNode = allocate(sizeof(Node));

	
	NewNode->prev = head->prev;
	head->prev = NewNode;

	Node* Temp = NewNode->prev;
	Temp->next = NewNode;
	NewNode->next = NULL;
	
	
	NewNode->data = newData;
	
}

/*
* Créer un noeud et l'ajouter après le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
		return;
	}


	Node* NewNode = allocate(sizeof(Node));
	NewNode->data = newData;


	NewNode->next = head->next;
	NewNode->prev = head;
	head->next = NewNode;
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune référence(i.e. next et prev == NULL)
*/

Node* removeNode(Node* currNode)
{
	if (currNode->next != NULL)
	{
		Node* prev = currNode->prev;
		Node* next = currNode->next;

		prev->next = next;
		next->prev = prev;


		currNode->next = NULL;
		currNode->prev = NULL;

		HeadLast(currNode);


		return currNode;
	}
	else if (currNode->next == NULL)
	{
		Node* prev = currNode->prev;
		prev->next = NULL;

		currNode->next = NULL;
		currNode->prev = NULL;

		HeadLast(currNode);

		return currNode;
	}
}


/*
* Ajouter dans le tableau le nom de chacun en ordre alphabétic. Par simplicité, considérer seulement les deux première lettre.
*/
void alphabetise(Node* head, char* names[]) {
	 // J'ai efface la boucle qui verifie le alphabetise car je ne l'ai pas fait. J'ai fait l'autre tri.
}

void HeadLast(Node* currNode)
{
	Node* head = currNode;
	Node* LastNode = currNode;

	while (LastNode->next != NULL)
	{
		LastNode = LastNode->next;
	}
	while (head->prev != NULL && head->prev != LastNode && head->prev != LastNode->prev)
	{
		head = head->prev;
	}
	if (head != LastNode)
	{
		head->prev = LastNode;
	}
	else
	{
		head->prev = NULL;
	}
};