#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"

void insert(Node* currNode, void* newData) {
	Node* nextNode = allocate(sizeof(Node));
	nextNode->data = newData;
	nextNode->next = NULL;
	currNode->next = nextNode;
}

void insertHead(Node* head, void* newData) {
	if (head->data == NULL) {
		head->data = newData;
	}
	else {
		Node* nextNode2 = allocate(sizeof(Node));
		nextNode2->data = newData;
		nextNode2->next = NULL;
		head->next = nextNode2;
	}
}

Node* removeByData(Node* head, void* rmData) {
	Node* n = head;
	int i = 0;
	while (head->next != NULL) {
		if (head->data == rmData) {
			memset(head, 0, sizeof(Node));
			return n;
		}
		head = head->next;
		if (i >= 1)
		{
			n = n->next;
		}
		i++;
	}
}

Node* removeByName(Node* head, char* name) {
	Person* p = head;
	Person* p2 = head;
	int i = 0;
	while (head->next != NULL) {
		if (p->name == name) {
			memset(head, 0, sizeof(Node));
			return p2;
		}
		p = head->next;
		if (i >= 1)
		{
			p2 = head->next;
		}
		i++;
	}
}

void sort(Node* head) {

	/*Person* p = head->data;
	Person* p2 = other->data;
	if(p->age < p2->age){
		swap()
	}*/

	for (int i = 1; i < sizeof(Node); i++) {
		int y = i;
		while (y > 0) {

		}
	}
}