#include <assert.h>
#include <stdint.h>
#include "labo.h"

/*
struct Stack
{
	void** data;
	size_t max_size;
	size_t top;
};
*/

/*
* Cr�er la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size)
{
	Stack* s = allocate(sizeof(Stack));
	s->data = allocate(sizeof(void*) * max_size);
	
	s->max_size = max_size;
	s->top = 0;
}

/*
* Ajouter l'�l�ment sur la stack. Pr�vener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData)
{
	if (s->top < s->max_size)
	{
		s->data[s->top] = newData;
		s->top++;
	}
	else
	{
		printf("Overflow\n");
	}


}

/*
* Enlever l'�l�ment de la stack et retourner l'information. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
void* pop(Stack* s)
{
	if (s->data[s->top-1] != NULL)
	{
		void* temp = s->data[s->top-1];
		s->data[s->top-1] = NULL;



		s->top--;
		return temp;
	}
	else if (s->data == NULL)
	{
		return NULL;
	}


}

/*
* Retourner l'�l�ment du top sans l'enlever de la stack. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
void* peek(Stack* s)
{
	if (s->data[s->top -1] != NULL)
	{
		return s->data[s->top-1];
	}
	else if (s->data[s->top-1] == NULL)
	{
	return NULL;
	}
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilis� la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s)
{
	void* data; // Ceci n'est pas une variable de type Stack 
	int up = s->top-1;
	int down = 0;
	for (int i = 0; i < s->top/2; i++)
	{
		data = s->data[up];
		s->data[up] = s->data[down];
		s->data[down] = data;
		up--;
		down++;
	}


}
/*
typedef struct person_t {
	char name[256];
	size_t age;
} Person;
*/


/*
Triez la stack.La personne sur le haut/top est la plus jeune. 
Vous ne pouvez pas modifier la propri�t� data directement. 
Vous devez utiliser push,pop et/ou peek
*/


void sortStack(Stack* s)
{



}