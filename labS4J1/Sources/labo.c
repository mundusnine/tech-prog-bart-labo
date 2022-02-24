#include "labo.h"


/*
* Cr�er la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size)
{
	Stack* stack = allocate(sizeof(Stack));
	stack->data = allocate(sizeof(void*) * max_size);
	stack->max_size = max_size;
	stack->top = 0;

	return stack;
}

/*
* Ajouter l'�l�ment sur la stack. Pr�vener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData)
{
	
	if (s->top < s->max_size && s->top >= 0)
	{
		s->top++;
		s->data[s->top - 1] = newData;
	}
}

/*
* Enlever l'�l�ment de la stack et retourner l'information. Si jamais il n'y a pas d'�l�ment, retourner NULL.
*/
void* pop(Stack* s)
{
	if (s->data[s->top - 1] != NULL)
	{
		s->top -= 1;
		void* element = s->data[s->top];
		s->data[s->top] = NULL;

		return element;
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
	if (s->data[s->top -1] != NULL &&s->top>0)
	{
		return s->data[s->top - 1];
	}
	else 
	{
		return NULL;
	}
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilis� la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s)
{
	void* Tempo[64] = {0};

	for (int i = 0; i < s->top; i++)
	{
		Tempo[i] = s->data[(s->top - 1)-i];
	}

	for (int i = 0; i < s->top; i++)
	{
		s->data[i] = Tempo[i];
	}
}

/*
* Tri�e la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propri�t� data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s)
{

}