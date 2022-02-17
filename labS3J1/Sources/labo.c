#include "labo.h"
#include <string.h>

void insert(Node* currNode, void* newData)
{
	//done
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	currNode->next = n ;
	n->next = NULL;
	
}

void insertHead(Node* head, void* newData)
{
	//maybe?
	Node* n = head;
	if (n->data == NULL)
	{
		head->data = newData;
	}
	else
	{
		n = allocate(sizeof(Node));
		n->data = newData;
		head->next = n;
		n->next = NULL;
	}
}

Node* removeByData(Node* head, void* rmData)
{
	Node* n = head;
	Node* previousNode;
	while (n != NULL)
	{
		if (n->data == rmData)
		{
			memset(n, 0, sizeof(Node));
			return previousNode;
		}
		previousNode = n;
		n = n->next;
	}
}

Node* removeByName(Node* head, char* name)
{
	Node* n = head;
	Node* previousNode;
	while (n != NULL)
	{
		if (n->data == name)
		{
			memset(n, 0, sizeof(Node));
			return previousNode;
		}
		previousNode = n;
		n = n->next;
	}
}

void sort(Node* head)
{
	Person* p = head->data;
	Node* n = head;
	Node* previousNode = n;
	int young;
	young = p->age;
	while (n != NULL)
	{

		if (young < p->age)
		{
			swap(previousNode, n);
			p = n->data;
		}
		previousNode = n;
		n = n->next;
	}
}

void swap(Node* a, Node* b)
{
	Node* Temp;
	Temp = a;
	a = b;
	b = Temp;
}