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
* D�clarer une structure de donn�e appeler Queue qui est un noeud comme le Node de la liste doublement cha�n�e. D�clar� aussi un noeud qui va avoir le nom Node.
*/

typedef struct person_t {
	char name[256];
	size_t age;
} Person;

/*
* Ajouter l'�l�ment sur la queue/file.
*/
void push(Queue* q, Node* n);

/*
* Enlever l'�l�ment de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q);



/*
* Retourner l'�l�ment de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
Node* peek(Queue* q);

/*
* Ajouter l'�l�ment sur la queue/file comme si elle serait une priority queue. Utiliser l'�ge afin de "tri�" � chaque push.La personne au premier pop() est la plus jeune.
* On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n);


/*
* Tri�e la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le m�me algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q);