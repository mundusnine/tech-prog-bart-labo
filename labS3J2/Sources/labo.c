#include "labo.h"

void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	currNode->next = n;
	n->prev = currNode;
	n->next = NULL;
}

void insertTail(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));;
	if (head != NULL)
	{
		head->prev->next = head;
		head->prev = n;
		head->prev->prev = head;
		n = newData;
		n->prev = head;
	}
	else
	{
		head->data = newData;
		head->next = NULL;
		head->prev = NULL;
	}
}

void insertHead(Node* head, void* newData)
{
	
	if (head->data != NULL)
	{
		Node* n = allocate(sizeof(Node));
		if (head->prev != NULL)
		{
			head->prev->next = n;
		}
		head->next = n;
		n->data = newData;
		n->prev = head;
		n->next = head->prev;
	}
	else
	{
		head->data = newData;
		head->next = NULL;
		head->prev = NULL;
	}
}

Node* removeNode(Node* currNode)
{
	if (currNode != NULL)
	{
		currNode->next->prev = currNode->prev;
		currNode->prev->next = currNode->next;
		currNode->data = NULL;
		currNode->next = NULL;
		currNode->prev = NULL;
	}
}

//j'ai fait le sort() dans l'autre lab
void alphabetise(Node* head, char* names[])
{

}