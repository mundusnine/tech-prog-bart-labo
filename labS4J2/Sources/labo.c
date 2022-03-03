#include<stdio.h>
#include"labo.h"

void push(Queue* q, Node* n)
{
	if (q->data == NULL)
	{
		q->next = NULL;
		q->prev = NULL;
		q->data = n->data;
		return;
	}

	Node* node = allocate(sizeof(Node));
	node->next = q->next;
	node->prev = q;
	node->data = q->data;

	if (node->next != NULL)
	{
		node->next->prev = node;
	}

	q->next = node;
	q->data = n->data;

	Node* lastNode = q;

	if (q->prev == NULL)
	{
		while (lastNode->next != NULL)
		{
			lastNode = lastNode->next;
		}
		if (q != lastNode)
		{
			q->prev = lastNode;
		}
		else
		{
			q->prev = NULL;
		}
	}
}

Node* pop(Queue* q)
{
	if (q->data == NULL && q->prev == NULL && q->next == NULL || q == NULL)
	{
		return NULL;
	}
	else if(q->prev == NULL && q->next == NULL)
	{
		Node temp = *q;
		q->data = NULL;
		return &temp;
	}

	Node* lasteNode = q->prev;

	if (q->prev != NULL && q->prev != q->next)
	{
		q->prev->prev->next = NULL;
		q->prev = q->prev->prev;
	}
	else
	{
		q->prev = NULL;
		q->next = NULL;
	}

	return lasteNode;
}

Node* peek(Queue* q)
{
	if (q->data == NULL && q->prev == NULL && q->next == NULL || q == NULL)
	{
		return NULL;
	}

	if (q->prev != NULL)
	{
		return q->prev;
	}
	else
	{
		return q;
	}

}

void pushAsPriorityQueue(Queue* q, Node* n)
{
	push(q, n);

	if (q->next == NULL)
	{
		return;
	}
	else if(q->next->next == NULL)
	{
		Person* p1 = q->data;
		Person* p2 = q->next->data;

		if (p1->age >= p2->age)
		{
			return;
		}
		else
		{
			Node temp = *q;
			q->data = q->next->data;
			q->next->data = temp.data;
		}
		return;
	}
	
	Node* element = q;
	Node* elementPlusGrand = q;
	Person* p1 = q->data;
	int change = 0;
	int stop = 0;

	while (element != NULL && stop == 0)
	{
		Person* p2 = element->data;

		if (p1->age > p2->age)
		{
			stop = 1;
		}
		else if (p1->age < p2->age)
		{
			change = 1;
			elementPlusGrand = element;
		}

		element = element->next;
	}

	if (change == 1)
	{
		Node* newNode = allocate(sizeof(Node));

		newNode->next = elementPlusGrand->next;
		newNode->prev = elementPlusGrand;
		newNode->data = q->data;

		if (elementPlusGrand->next != NULL)
		{
			elementPlusGrand->next->prev = newNode;
		}
		else if(elementPlusGrand->next == NULL && q->prev == elementPlusGrand)
		{
			q->prev = newNode;
		}
		elementPlusGrand->next = newNode;

		Node* garbage = q->next;

		q->data = q->next->data;
		q->next = q->next->next;

		garbage = memset(garbage, 0, sizeof(Node));
	}
}

void sortQueue(Queue* q)
{
	int nombreElement = 0;
	Node* element = q;

	while (element != NULL)
	{
		nombreElement++;
		element = element->next;
	}

	element = q;
	Person** p = allocate(sizeof(void*) * nombreElement);

	for (int i = 0; i < nombreElement; i++)
	{
		p[i] = element->data;
		element = element->next;
	}

	for (int i = 0; i < nombreElement; i++)
	{
		pop(q);
	}

	Node* newNode = allocate(sizeof(Node));
	for (int i = 0; i < nombreElement; i++)
	{
		newNode->data = p[i];
		pushAsPriorityQueue(q, newNode);
	}
	newNode = memset(newNode, 0, sizeof(Node));
	p = memset(p, 0, sizeof(void*) * nombreElement);
}