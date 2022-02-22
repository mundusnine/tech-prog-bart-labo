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
		Person* p = n->data;
		if (p->name == name)
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
	Person* p;
	Person* p2;
	Node* n = head;
	Node* previousNode = n;
	while (n != NULL)
	{
		p = previousNode->data;
		p2 = n->data;
		if (p2->age > p->age)
		{
			swap(n, previousNode);
			previousNode = n;
			n = n->next;
		}
	}
}

void swap(Node* a, Node* b)
{
	Node* Temp;
	Temp = a;
	a = b;
	b = Temp;
}