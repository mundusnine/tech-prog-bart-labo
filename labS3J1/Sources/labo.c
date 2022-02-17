#include <assert.h>
#include <stdint.h>
#include "labo.h"

/*
* Declarer une structure de donnée appeler Node qui est un noeud d'une liste simplement chaînée.
*/


/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	currNode->next = n;
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	Node* n = allocate(sizeof(Node));
	if (head->data == NULL) 
	{
		head->data = newData;
	}
	else if (head->data != NULL)
	{
		head->next = n;
	}
}

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
Si param rmData = current->data  Effacer current node et return previous node
*/
Node* removeByData(Node* head, void* rmData) {
	Node* n = head;
	Node* previous;
	int i = 0;

while()
{
	if (rmData == n)
	{

	}

	
}

/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name) {

}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {
	//utiliser la struct person
	//ne pas faire
}