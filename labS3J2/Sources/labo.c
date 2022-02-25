#include<stdio.h>
#include"labo.h"

void insert(Node* currNode, void* newData)
{
	Node* newNode = allocate(sizeof(Node));
	newNode->next = currNode->next;
	newNode->prev = currNode;
	currNode->next = newNode;
	newNode->data = newData;

	checkHead(currNode);
}

void insertTail(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
		return;
	}
	Node* lastNode = head->prev;
	Node* newNode = allocate(sizeof(Node));

	head->prev = newNode;
	lastNode->next = newNode;
	newNode->prev = lastNode;
	newNode->data = newData;
	newNode->next = NULL;
}

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
		return;
	}
	Node* newNode = allocate(sizeof(Node));
	newNode->next = head->next;
	newNode->prev = head;
	newNode->data = newData;
	head->next = newNode;
}

Node* removeNode(Node* currNode)
{
	Node* prevNode = currNode->prev;
	Node* nextNode = currNode->next;
	if (nextNode != NULL)
	{
		nextNode->prev = prevNode;
	}
	if (prevNode != NULL)
	{
		prevNode->next = nextNode;
	}
	currNode->next = NULL;
	currNode->prev = NULL;
	return currNode;
}

void alphabetise(Node* head, char* names[])
{
	int change = 0;
	int dontChange = 0;
	Node* checkElement = head;
	int nombreElement = 0;
	while (checkElement != NULL)
	{
		nombreElement++;
		checkElement = checkElement->next;
	}

	for (int i = 0; i < nombreElement; i++)
	{
		Node* element1 = head;
		Node* element2 = head->next;
		for (int a = 0; a < nombreElement - i - 1; a++)
		{
			Person* p1 = element1->data;
			Person* p2 = element2->data;
			for (int b = 0; b < 2; b++)
			{
				if (p1->name[b] > p2->name[b] && change != 1 && dontChange != 1)
				{
					change = 1;
				}
				else if (p1->name[b] == p2->name[b])
				{
					dontChange = 0;
				}
				else
				{
					dontChange = 1;
				}
			}
			dontChange = 0;
			if (change == 1)
			{
				Node temp1 = *element1;
				Node temp2 = *element2;

				*element1 = temp2;
				*element2 = temp1;
				element2->next = temp2.next;
				element1->next = element2;
				change = 0;
			}

			element1 = element1->next;
			element2 = element2->next;
		}
	}

	Node* n = head;
	int positionTable = 0;
	for (int i = 0; i < nombreElement; i++)
	{
		int a = 0;
		Person* p = n->data;
		
		//je narrive pas a ajouter les nom dans le tableau de char :(
		names[positionTable] = p->name;

		while (p->name[a] != 0)
		{
			positionTable++;
			a++;
		}
		positionTable--;
		n = n->next;
	}

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