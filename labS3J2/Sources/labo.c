#include <assert.h>
#include <stdint.h>
#include "labo.h"


// PREV , DATA, NEXT

/*
* Cr�er un noeud et l'ajouter apr�s le noeud currNode. Consid�rer la propri�t� next et prev.
*/
void insert(Node* currNode, void* newData)
{
	Node* NewNode = allocate(sizeof(Node));
	NewNode->data = newData;
	NewNode->prev = currNode;
	NewNode->next = currNode->next;


	currNode->next = NewNode;

}

/*
* Cr�er un noeud et l'ajouter apr�s le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData)
{
	Node* NewNode = allocate(sizeof(Node));

	NewNode->prev = head->prev;
	NewNode->next = head;
	Node* Temp = head->prev;

	Temp->next = NewNode;

	head->prev = NewNode;
	if (head->data == NULL)
	{
		head->data = newData;
		NewNode->data = NULL;
	}
	else
	{
		NewNode->data = newData;
	}

	



}

/*
* Cr�er un noeud et l'ajouter apr�s le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	Node* NewNode = allocate(sizeof(Node));


	NewNode->next = head->next;
	NewNode->prev = head;
	head->next = NewNode;

	if (head->data == NULL)
	{
		head->data = newData;
		NewNode->data = NULL;
	}
	else
	{
		NewNode->data = newData;
	}

}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune r�f�rence(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode)
{
	Node* prev = currNode->prev;
	Node* next = currNode->next;

	prev->next = next;
	next->prev = prev;

	currNode->next = NULL;
	currNode->prev = NULL;

	return currNode;
}


/*
* Ajouter dans le tableau le nom de chacun en ordre alphab�tic. Par simplicit�, consid�rer seulement les deux premi�re lettre.
*/
void alphabetise(Node* head, char* names[]);