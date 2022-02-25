#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"

void insert(Node* currNode, void* newData)
{
	Node* nextNode = allocate(sizeof(Node));
	nextNode->data = newData;
	nextNode->prev = currNode;
	nextNode->next = currNode->next;
	currNode->next = nextNode;
}

void insertTail(Node* head, void* newData)
{
	if (head->data == NULL) {
		head->data = newData;
	}
	else {
		Node* nextNode2 = allocate(sizeof(Node));
		head->prev = nextNode2;
		nextNode2->data = newData;
		nextNode2->next = head;
	}
}

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL) {
		head->data = newData;
	}
	else {
		Node* nextNode2 = allocate(sizeof(Node));
		nextNode2->data = newData;
		nextNode2->prev = head;
		head->next = nextNode2;
	}
}

Node* removeNode(Node* currNode)
{
	if (currNode == NULL)
	{
		return currNode;
	}
	else
	{
		while (currNode != NULL)
		{
			currNode->next;
		}
		currNode->next = NULL;
		currNode->prev = NULL;
		return currNode;
	}

}

void alphabetise(Node* head, char* names[])
{

}