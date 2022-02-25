#include "labo.h"


/*
* Créer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
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
* Ajouter l'élément sur la stack. Prévener "l'overflow" de la stack.
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
* Enlever l'élément de la stack et retourner l'information. Si jamais il n'y a pas d'élément, retourner NULL.
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
* Retourner l'élément du top sans l'enlever de la stack. Si jamais il n'y a pas d'élément, retourner NULL.
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
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilisé la variable temp qui est une autre Stack.
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
* Triée la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriété data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s)
{
	//Utilisation de Brute force afin de sort la Stack O(n2)
	void* Tempo[64] = { 0 };
	for (int i = 0; i < s->max_size-1; i++)
	{
		Person* p2 = pop(s);
		for (int i2 = 0; i2 < s->max_size-1; i2++)
		{
			Person* p = pop(s);
			if (p->age > p2->age)
			{
				Tempo[i2] = p;
			}
			else
			{
				Tempo[i2] = p2;
				p2 = p;
			}
			if (i2 == s->max_size - 2)
			{
				if (p->age != Tempo[i2])
				{
					Tempo[i2+1] = p;
				}
				if (p2->age != Tempo[i2])
				{
					Tempo[i2+1] = p2;
				}
				i2 = 0;
				break;
			}
		}
		if (i == s->max_size - 2)
		{
			//envoie de la stack sorted
			for (int i3 = 0; i3 < s->max_size; i3++)
			{
				push(s, Tempo[i3]);
			}
		}
		else
		{
			//revoie inverser dans la stack
			for (int i3 = 0; i3 < s->max_size; i3++)
			{
				push(s, Tempo[s->max_size - 1 - i3]);
			}
		}
	}

}