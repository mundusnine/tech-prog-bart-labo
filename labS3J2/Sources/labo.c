#include "labo.h"

//En faisant une list cyclique.
void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	if (currNode->next == NULL)
	{
		n->next = currNode;
		currNode->prev = n;
	}
	else
	{
		n->next = currNode->next;
	}
	n->prev = currNode;
	currNode->next = n;
	n->data = newData;
}

//En faisant une list cyclique
void insertTail(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));

	if (head->prev == NULL)
	{
		n->prev = head;
		n->next = head;
		head->prev = n;
		head->next = n;
	}
	else
	{
		head->prev->next = n;
		n->prev = head->prev;
		n->next = head;
	}

	if (head->data == NULL)
	{
		head->data = newData;
	}
}

//En faisant une list cyclique
void insertHead(Node* head, void* newData)
{
	Node* n = allocate(sizeof(Node));

	if (head->next == NULL)
	{
		n->next = head;
		head->prev = n;
	}
	else
	{
		n->next = head->next;
	}
	n->prev = head;
	head->next = n;

	if (head->data == NULL)
	{
		head->data = newData;
	}
}

Node* removeNode(Node* currNode)
{
	currNode->prev->next = currNode->next;
	currNode->next->prev = currNode->prev;
	currNode->prev = NULL;
	currNode->next = NULL;

	return currNode;
}

//En m'inspirant du bubbleSort
void alphabetise(Node* head, char* names[])
{
	Node* n = memset(sizeof(Node));
	n = head;
	int firstAdress = head;
	int lettreASCII[2] = { 0 }; //pour stocker 2 premier caracteres
	int lettreNextASCII[2] = { 0 }; //pour stocker 2 premier caracteres
	int nbElements = 0; //nb éléments dans la list

	while (n != firstAdress || nbElements == 0)
	{
		nbElements++;
		n = n->next;
	}

	n = head;
	Person* p = memset(sizeof(Person));
	Person* pNext = memset(sizeof(Person));
	int switched = 0;

	for (int i = 0; i < (nbElements - 1); i++)
	{
		p = n->data;

		if (n->next != NULL || n->next != firstAdress)
		{
			pNext = n->next->data;
			lettreASCII[0] = p->name[0];
			lettreASCII[1] = p->name[1];
			lettreNextASCII[0] = pNext->name[0];
			lettreNextASCII[1] = pNext->name[1];
		}
		if (lettreASCII[0] == lettreNextASCII[0])
		{
			if (lettreASCII[1] > lettreNextASCII[1])
			{
				Person* tempData = n->data;
				n->data = n->next->data;
				n->next->data = tempData;
				switched = 1;
			}
		}
		else if (lettreASCII[0] > lettreNextASCII[0])
		{
			Person* tempData = n->data;
			n->data = n->next->data;
			n->next->data = tempData;
			switched = 1;
		}

		if (switched == 1)
		{
			switched = 0;
			n = head;
			i = -1;
		}
		else
		{
			n = n->next;
		}
	}
}