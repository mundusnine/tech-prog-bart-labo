#include "labo.h"


void insert(Node* currNode, void* newData)
{
	Node* newNode = allocate(sizeof(Node));
	newNode->next = currNode->next;
	newNode->data = newData;
	currNode->next = newNode;
}

void insertHead(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
	}
	else
	{
		Node* newNode = allocate(sizeof(Node));
		newNode->next = head->next;
		head->next = newNode;
	}
}

Node* removeByData(Node* head, void* rmData)
{
	Node* copyNode = head;
	Node* prevNode = head;
	
	while (copyNode != NULL)
	{
		if (copyNode->data == rmData)
		{
			memset(copyNode,0,sizeof(Node));
			return prevNode;
		}
		else if(copyNode->data != rmData)
		{
			prevNode = copyNode;
			copyNode = copyNode->next;
		}
	}
}

Node* removeByName(Node* head, char* name)
{
	Node* newNode = allocate(sizeof(Node));
	newNode = head;
	Node* prevNode = head;
	Person* person = newNode->data;
	while (newNode != NULL)
	{
		if (person->name == name)
		{
			memset(newNode, 0, (sizeof(Node)));
			return prevNode;
		}
		else if (person->name != name)
		{
			prevNode = newNode;
			newNode = newNode->next;
		}
	}
}

void sort(Node* head)
{
	Node* newNode = head;
	Node* tempNode;
	Person* person = head;
	Person* nextPerson = head->next;
	int count = 0;
	int swap = 0;

	while (newNode != NULL)
	{
		count += 1;
		newNode = newNode->next;
	}
	newNode = head;

	for (int i = 0; i < count - 1; i++)
	{
		if (person->age > nextPerson->age)
		{
			tempNode = newNode;
			newNode = newNode->next;
			newNode->next = tempNode;
			swap = 1;
		}
		
		if (swap == 1)
		{
			swap = 0;
			i = -1;
		}
	}
}
