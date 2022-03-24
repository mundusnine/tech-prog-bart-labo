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
* D�clarer une structure de donn�e appeler Node qui est un noeud d'une liste doublement cha�n�e.
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
* Cr�er un noeud et l'ajouter apr�s le noeud currNode. Consid�rer la propri�t� next et prev.
*/
void insert(Node* currNode, void* newData);

/*
* Cr�er un noeud et l'ajouter apr�s le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData);

/*
* Cr�er un noeud et l'ajouter apr�s le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData);

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune r�f�rence(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode);

/*
* Ajouter dans le tableau le nom de chacun en ordre alphab�tic. Par simplicit�, consid�rer seulement les deux premi�re lettre.
*/
void alphabetise(Node* head, char* names[]);