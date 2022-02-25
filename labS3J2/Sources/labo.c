#include "labo.h"

void insert(Node* currNode, void* newData)
{
	Node* newNode = allocate(sizeof(Node));
	newNode->next = currNode->next;
	newNode->prev = currNode;
	newNode->data = newData;
	currNode->next = newNode;
	checkHead(currNode);
}

void checkHead(Node* currNode)
{
	Node* lastNode = currNode;
	Node* head = currNode;
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	while (head->prev != NULL && head->prev != lastNode && head->prev != lastNode->prev)
	{
		head = head->prev;
	}
	if (head != lastNode)
	{
		head->prev = lastNode;
	}
	else
	{
		head->prev = NULL;
	}
}

void insertTail(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data == newData;
		return;
	}
	Node* newNode = allocate(sizeof(Node));
	Node* dernierNode = head->prev;
	head->prev = newNode;
	dernierNode->next = newNode;
	newNode->data = newData;
	newNode->next = NULL;
	newNode->prev = dernierNode;
}

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
		return;
	}
	Node* newNode = allocate(sizeof(Node));
	newNode->prev = head;
	newNode->next = head->next;
	newNode->data = newData;
	head->next = newNode;
}

Node* removeNode(Node* currNode)
{
	if(currNode->next != NULL)
	{
		currNode->next->prev = currNode->prev;
	}
	currNode->prev->next = currNode->next;
	currNode->next = NULL;
	currNode->prev = NULL;
	return currNode;
}

void alphabetise(Node* head, char* names[])
{
}
