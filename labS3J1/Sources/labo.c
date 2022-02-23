#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"



/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) 
{
	Node* newNode = allocate(sizeof(Node));
	newNode->data = newData;
	newNode->next = NULL;
	currNode->next = newNode;
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	if (head->data == NULL)
	{
		head->data = newData;
	}
	else
	{
		Node* newNode = allocate(sizeof(Node));
		newNode->data = newData;
		newNode->next = NULL;
		head->next = newNode;
	}
}

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData)
{
	Node* previousNode;
	Node* currNode = head;
	while (currNode != NULL)
	{
		if (currNode->data == rmData)
		{
			previousNode->next = currNode->next;
			memset(currNode, 0, sizeof(Node));
			break;
		}
		previousNode = currNode;
		currNode = currNode->next;
	}
	return previousNode;
}

/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name)
{
	Node* previousNode;
	Node* currNode = head;
	while (currNode != NULL)
	{

		//La raison pour laquel la fonction s'executer avec le Node.data sans preciser que nous voulions le Person.Nom et non Person.Age
		//c'est que le parametre de fonction qui sert a la vérification est un String (char*) et donc quand nous le comparons avec l'adresse de la Person
		// cela le compare avec tout les composantes de celui-ci (l'age et le nom) et considerant que l'age n'est pas un string la comparaison na pas lieu 
		//puisqu'il ne son pas du meme type et il compare uniquement avec le Person.Nom.

		//Donc dans ce cas precis (currNode->data == name) == (Person.nom == name)

		if (currNode->data == name)
		{
			previousNode->next = currNode->next;
			memset(currNode, 0, sizeof(Node));
			break;
		}
		previousNode = currNode;
		currNode = currNode->next;
	}
	return previousNode;
}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head)
{
	int modifVerif = 0;
	int i = 0;
	Node* previousNode = head;
	Node tempoNode = {0};
	Node* currNode = head;

	while (currNode != NULL)
	{
		Person* p = currNode->data;
		Person* p2 = previousNode->data;
		if (p->age < p2->age)
		{
			modifVerif = 1;

			tempoNode.next = currNode->next;
			currNode->next = previousNode;
			previousNode->next = tempoNode.next;
			if (i == 1)
			{
				head = currNode;
			}
		}
		previousNode = currNode;
		currNode = currNode->next;
		i++;
		if (modifVerif == 1)
		{
			i = 0;
			modifVerif =0;
			previousNode = head;
			currNode = head;
		}
	}
}