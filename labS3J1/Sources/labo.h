#include <assert.h>
#include <stdint.h>

#define HEAP_SIZE 1024 * 1024
extern uint8_t* heap;
extern size_t heap_top;

static void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}




/*
* Déclarer une structure de donnée appeler Node qui est un noeud d'une liste simplement chaînée.
*/
typedef struct Node_t Node;

typedef struct person_t {
	char name[256];
	size_t age;
} Person;

typedef struct Node_t Node;
struct Node_t {
	void* data;
	Node* next;
};


/*
* Creer un noeud et l'ajouter apr�s le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData);

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData);

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData);


/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name);

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head);