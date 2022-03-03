#include "labo.h"

/*
* Cr�er la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size)
{
	Stack* stack = allocate(sizeof(Stack));
	stack->data = allocate(sizeof(void*) * max_size);
	stack->top = 0;
	stack->max_size = max_size;
}

/*
* Ajouter l'�l�ment sur la stack. Pr�vener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData)
{
	//done
	if (s->top >= 0 && s->top < s->max_size )
	{
		s->data[s->top] = newData;
		s->top++;
	}
}

/*
* Enlever l'�l�ment de la stack et retourner l'information. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
void* pop(Stack* s)
{
	if (s->data[s->top - 1] != NULL)
	{
		void* tempoData = s->data[s->top - 1];
		s->top--;
		return tempoData;
	}
	else
	{
		return NULL;
	}
}

/*
* Retourner l'�l�ment du top sans l'enlever de la stack. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
void* peek(Stack* s)
{
	if (s->top == 0)
	{
		return NULL;
	}
	else
	{
		return s->data[s->top - 1];
	}
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilis� la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s)
{
	if (s->data != NULL)
	{
		int temp = pop(s);
		reverseStack(s);
		putBottom(s, temp);
	}
}

/*
* Tri�e la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propri�t� data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s)
{
	
}

void putBottom(Stack* s, int tempo)
{
	if (tempo != NULL)
	{
		int temp = pop(s);
		putBottom(s, temp);

		push(s, temp);
	}
}
