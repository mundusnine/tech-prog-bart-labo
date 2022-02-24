#include<stdio.h>
#include"labo.h"

//Labo non tester

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

	//while (lastNode->next != NULL)
	//{
	//	lastNode = lastNode->next;
	//}

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
	int nombreElemen = 0;
	Node* checkElememt = head;
	int change = 0;

	while(checkElememt->next != NULL)
	{
		nombreElemen++;
		checkElememt = checkElememt->next;
	}

	for (int i = 0; i < nombreElemen; i++)
	{
		int a = 0;

		Node* element1 = head;
		Node* element2 = head->next;

		while (a < nombreElemen - 1 - i)
		{
			Person* p1 = element1->data;
			Person* p2 = element2->data;

			for (int b = 0; b < 1; b++)
			{
				if (p1->name[b] > p2->name[b] && change == 0)
				{
					change = 1;
				}
			}

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
			a++;
		}
	}

	int y = 0;

	while (head->next != NULL)
	{
		int z = 0;
		Person* person = head->data;
		while(person->name[z] != '\0')
		{
			printf("%c", person->name[z]);
			names[y] = person->name[z];
			z++;
			y++;
		}
		names[y] = ' ';
		y++;
	
		head = head->next;
	}

	//int t = 0;
	//while (names[t] != '\n')
	//{
	//	printf("%c", names[t]);
	//}

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