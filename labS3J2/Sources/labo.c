#include "labo.h"



void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	if (currNode->next == NULL)
	{
		n->next = NULL;
	}
	else
	{
		n->next = currNode->next;
	}
	n->prev = currNode;
	currNode->next = n;
	n->data = newData;
}

void insertTail(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));
	head->prev->next = n;
	n->prev = head->prev;
	n->next = head;

	if (head->data == NULL)
	{
		head->data = newData;
	}
}

void insertHead(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));
	if (head->next == NULL)
	{
		n->next = head;
	}
	else
	{
		n->next = head->next;
	}
	n->prev = head;
	head->next = n;

	if (head->data == NULL)
	{
		head->data = newData;
	}
}

Node* removeNode(Node* currNode)
{
	//memset(currNode, 0, sizeof(Node));
	
}