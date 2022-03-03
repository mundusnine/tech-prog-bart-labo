#include "labo.h"
#include <stdlib.h>

void push(Queue* q, Node* n)
{
	if (q->next == NULL && q->prev == NULL)
	{
		q->data = n->data;
		q->next = NULL;
		q->prev = n;
		return;
	}
	else
	{
		q->prev->next = n;
		q->prev = n; //le prev de head pointe vers le dernier element qui est n.
		n->next = NULL; //le next du dernier element pointe sur NULL.
	}
}

Node* pop(Queue* q)
{
	if (q->data = NULL && q->next == NULL && q->prev == NULL)
	{
		return NULL;
	}
	if (q->prev == q && q->next == NULL)
	{
		Node* temp = allocate(sizeof(Node));
		temp->data = q->data;
		temp->prev = NULL;
		temp->next = NULL;
		memset(q, 0, sizeof(Queue));
		return temp;
	}
}

Node* peek(Queue* q)
{
	if (q->data == NULL && q->next == NULL && q->prev == NULL)
	{
		return NULL;
	}
	else
	{
		return q->prev;
	}
}

void pushAsPriorityQueue(Queue* q, Node* n)
{
}

void sprtQueue(Queue* q)
{

}