#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"

void insert(Node* currNode, void* newData)
{
	Node* test = allocate(sizeof(Node));
	test->data = newData;
	test->next = NULL;
	currNode->next = test;
}

void insertHead(Node* head, void* newData)
{
	Node* test1 = allocate(sizeof(Node));
	test1->data = newData;
	test1->next = head->next;
	head->next = test1;
	if (head->data == NULL)
	{
		head->data = newData;
	}
}

Node* removeByData(Node* head, void* rmData)
{
	int i = 0;
	Node* supprime = head;
	Node* nodeReturn = head;
	while (supprime->data != rmData)
	{
		if (i != 0)
		{
			nodeReturn = nodeReturn->next;
		}

		supprime = supprime->next;

		if (i == 0)
		{
			i++;
		}
	}
	memset(supprime, 0, sizeof(Node));

	if (nodeReturn == supprime)
	{
		return nodeReturn->next;
	}
	else
	{
		return nodeReturn;
	}
}

Node* removeByName(Node* head, char* name)
{
	int i = 0;
	Node* supprime = head;
	Node* nodeReturn = head;
	while (supprime != NULL)
	{
		Person* p = (Person*)supprime->data;
		if (p->name == name)
		{
			memset(supprime, 0, sizeof(Node));
			
			if (nodeReturn == supprime)
			{
				return nodeReturn->next;
			}
			else
			{
				return nodeReturn;
			}
		}

		if (i != 0)
		{
			nodeReturn = nodeReturn->next;
		}

		supprime = supprime->next;

		if (i == 0)
		{
			i++;
		}
	}
}

void sort(Node* head)
{
	int nombreElement = 0;
	Node* checkElement = head;

	while (checkElement != NULL)
	{
		nombreElement++;
		checkElement = checkElement->next;
	}

	for (int i = 0; i < nombreElement; i++)
	{
		Node* element = head;
		Node* nextElement = head->next;
		while (nextElement != NULL)
		{
			Person* pElement = (Person*)element->data;
			Person* pNextElement = (Person*)nextElement->data;
	
			if (pElement->age < pNextElement->age)
			{
				Node* temp = element;
				element->data = nextElement->data;
				nextElement->data = temp->data;
			}
	
			element = element->next;
			nextElement = nextElement->next;
		}
	}
	
}