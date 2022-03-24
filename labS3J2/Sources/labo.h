#include <stdint.h>
#include <assert.h>

#define HEAP_SIZE 1024 * 1024
static uint8_t* heap = NULL;
static size_t heap_top = 0;

static void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

/*
* Déclarer une structure de donnée appeler Node qui est un noeud d'une liste doublement chaînée.
*/

typedef struct person_t {
	char name[256];
	size_t age;
} Person;

typedef struct Node_t {
	void* data;
	Node* prev;
	Node* next;
}Node;


/*
* Créer un noeud et l'ajouter après le noeud currNode. Considérer la propriété next et prev.
*/
void insert(Node* currNode, void* newData);

/*
* Créer un noeud et l'ajouter après le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData);

/*
* Créer un noeud et l'ajouter après le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData);

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune référence(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode);

/*
* Ajouter dans le tableau le nom de chacun en ordre alphabétic. Par simplicité, considérer seulement les deux première lettre.
*/
void alphabetise(Node* head, char* names[]);