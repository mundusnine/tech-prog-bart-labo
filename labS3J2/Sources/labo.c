#include "labo.h"


void insert(Node* currNode, void* newData)
{
	Node* n = allocate(sizeof(Node));
	n->next = currNode->next;
	n->prev = currNode;
	currNode->next = n;
	n->data = newData;
	
}

//Ca me marque que l'insertTail a failed mais je ne trouve pas l'erreur.
void insertTail(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
	}
	else
	{
		Node* n = allocate(sizeof(Node));
		if (head->prev == NULL)
		{
			head->prev = n;
			n->prev = head;
			n->next = NULL;
			n->data = newData;
		}
		else
		{
			n->prev = head->prev;
			head->prev->next = n;
			head->prev = n;
			n->data = newData;
			n->next = NULL;
		}
	}
}


void insertHead(Node* head, void* newData)
{
	
	if (head->data == NULL)
	{
		head->data = newData;
	}
	else
	{
		Node* n = allocate(sizeof(Node));
		if (head->next == NULL)
		{
			n->next = NULL;
			head->prev = n;
		}
		else
		{
			n->next = head->next;
		}
		n->prev = head;
	    head->next = n;
		n->data = newData;
	}
}

//j'ai supposément une erreur dans cette fonction.
Node* removeNode(Node* currNode)
{
	Node* nodePrev = currNode->prev;
	Node* nodeNext = currNode->next;
	if (nodeNext != NULL && nodePrev != NULL)
	{
		nodeNext->prev = nodePrev;
		nodePrev->next = nodeNext;
	}
	currNode->next = NULL;
	currNode->prev = NULL;

	return currNode;
}

//En m'inspirant du bubbleSort
void alphabetise(Node* head, char* names[])
{
	/*Node* n = head;
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
	Person* p = allocate(sizeof(Person));
	Person* pNext = allocate(sizeof(Person));
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
	}*/
}