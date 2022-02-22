#include <assert.h>
#include <stdint.h>
#include "labo.h"


//Déclare struct appeler Node qui est un noeud simplement chaine

// Structure de noeud





// Creer un noeud et l'ajouter apr�s le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
// Param currNode = Noeud    Param newData = Data du noeud
void insert(Node* currNode, void* newData)
{
	Node* NewNode = allocate(sizeof(Node));  // Allocation d'espace mémoire de la taille d'un Node
	NewNode->data = newData;  // Enregistrement des données passées en parametre dans un.data
	currNode->next = NewNode;  // CurrentNode.next prend la valeur de l'adresse de la nouvelle node

	NewNode->next = NULL; // L'adresse next du node devient NULL, puisqu'elle pointe vers rien

}

/*
* Cr�er un noeud et l'ajouter apr�s le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) // Node* Head = Le premier Node dans la liste   
{
	Node* NewNode = allocate(sizeof(Node)); // Allocate espace
	NewNode->next = head->next;  // NewNode->next pointe ce que le header pointais
	head->next = NewNode; // Le header pointe maintenant vers NewNode
	if (head->data == NULL)
	{
		head->data = newData;
	}  
	else
	{
		NewNode->data = newData;
	}
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
		if (cpy->data == rmData && prev == 0)
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

		if (prev >= 0) // Tout le temps
		{
			previous = cpy;
			cpy = cpy->next;
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
	Node* previous;
	Node* cpy = head;
	Person* p;


	while (cpy != NULL)
	{
		p = cpy;

		if (p->name == name)
		{
			memset(cpy, 0, sizeof(cpy));
			return previous;  // Si header == node recherché, erreur puisque previous est vide Sinon OK
		}

		previous = cpy;
		cpy = cpy->next;


	}



}


/*
* Trier par l'�ge. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) 
{


}
