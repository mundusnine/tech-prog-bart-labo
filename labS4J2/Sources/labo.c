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
	
	q->next = node;
	q->data = n->data;
	
	Node* lastNode = q;
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

Node* pop(Queue* q)
{
	if (q->data  == NULL && q->prev == NULL && q->next == NULL || q == NULL)
	{

		return NULL;
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
	Node* newNode = allocate(sizeof(Node));

}

void sortQueue(Queue* q)
{

}