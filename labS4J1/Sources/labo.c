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
* Créer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size)
{
	Stack* s = allocate(sizeof(Stack));
	s->data = allocate(sizeof(void*) * max_size);
	
	s->max_size = max_size;
	s->top = 0;
}

/*
* Ajouter l'élément sur la stack. Prévener "l'overflow" de la stack.
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
		return;
	}


}

/*
* Enlever l'élément de la stack et retourner l'information. Si jamais il n'y a pas d'élément, retourner NULL.
*/
void* pop(Stack* s)
{

	if (s->data[s->top-1] != NULL) // Si elem[top] != NULL y retourner l'info et la supprimer (mettre a null)
	{
		void* data = s->data[s->top - 1]; // copie


		s->data[s->top - 1] = NULL; // Mettre a null
		s->top--; // Decrementation du top

		return data; // retour de l'info
	}
	else // Si vide a elem[top-1] 
	{
		s->top--; // Decrementation du top ?
		return NULL;
	}
	


}

/*
* Retourner l'élément du top sans l'enlever de la stack. Si jamais il n'y a pas d'élément, retourner NULL.
*/
void* peek(Stack* s)
{

}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilisé la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s)
{

}

/*
* Triée la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriété data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s)
{

}