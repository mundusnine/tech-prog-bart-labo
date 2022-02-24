#include "labo.h"

void insert(Node* currNode, void* newData)
{
	Node* newNode = allocate(sizeof(Node));
	newNode->next = currNode->next;
	newNode->prev = currNode;
	newNode->data = newData;
	currNode->next = newNode;
}

void insertTail(Node* head, void* newData)
{
	Node* newNode = allocate(sizeof(Node));
	head->prev->next = newNode;
	newNode->prev = head->prev;
	head->prev = newNode;
	newNode->next = head;
	if (head->data == NULL)
	{
		head->data == newData;
	}
}

void insertHead(Node* head, void* newData)
{
	Node* newNode = allocate(sizeof(Node));
	head->next->prev = newNode;
	newNode->prev = head;
	newNode->next = head->next;
	head->next = newNode;
	if (head->data == NULL)
	{
		head->data = newData;
	}
}

Node* removeNode(Node* currNode)
{
	currNode->next->prev = currNode->prev;
	currNode->prev->next = currNode->next;
	currNode->next = NULL;
	currNode->prev = NULL;
	return currNode;
}

void alphabetise(Node* head, char* names[])
{
}
