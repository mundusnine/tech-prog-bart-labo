#include <assert.h>
#include <stdint.h>
#include "labo.h"


//Déclare struct appeler Node qui est un noeud simplement chaine

// Structure de noeud





// Creer un noeud et l'ajouter apr�s le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
// Param currNode = Noeud    Param newData = Data du noeud
void insert(Node* currNode, void* newData)
{
	Node* un = allocate(sizeof(Node));  // Pourquoi *
	un->data = newData;
	currNode->next = un;

	un->next = NULL;

}

/*
* Cr�er un noeud et l'ajouter apr�s le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData)
{
	Node* deux = allocate(sizeof(Node));
	head->next = deux;
	if (head->data == NULL)
	{
		head->data = newData; 
	}  // PROBLEME
	// ELSE ..
}

/*
Chercher param rmData, lorsque rmData = Node->Data, Supprimer la Node et retourner la précédente.
Pour supprimer = memset(node,0,sizeof(Node));
*/
Node* removeByData(Node* head, void* rmData)
{
	Node* previous;
	Node* cpy = head;
	int prev = 0;

	while (cpy != NULL)
	{

		// Si data == data head
		if (cpy->data == rmData && prev > 0)
		{
			printf("La data recherche est dans le head\n");
			memset(head, 0, sizeof(Node)); // Efface le head
			return 0;
		}
		// Si data != data-> head
		else if (cpy->data == rmData && prev > 0)
		{

			memset(cpy, 0, sizeof(Node));
			return previous;
		}

		if (prev > 0)
		{
			cpy = cpy->next;
			previous = cpy;

		}

		prev++;
	}
	

}

/*
Supprimer le noeud ayant le nom passer par name.
When name = Node->data, return previous node

		supprimer faite un memset(node,0,sizeof(Node));
*/
Node* removeByName(Node* head, char* name)
{
	Node* cpy = head;
	Node* previous;

	int prev = 0;
	while (cpy->next != NULL)
	{


		if (cpy->data == name)
		{
			return previous;
		}

		if (prev > 0)
		{
			cpy = cpy->next;

		}
		prev++;
	}

	

}


/*
* Trier par l'�ge. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {
}
