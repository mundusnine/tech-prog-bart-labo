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



}

/*
* Enlever l'élément de la stack et retourner l'information. Si jamais il n'y a pas d'élément, retourner NULL.
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
* Retourner l'élément du top sans l'enlever de la stack. Si jamais il n'y a pas d'élément, retourner NULL.
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
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilisé la variable temp qui est une autre Stack.
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
Triez la stack.La personne sur le haut/top est la plus jeune. 
Vous ne pouvez pas modifier la propriété data directement. 
Vous devez utiliser push,pop et/ou peek
*/


void sortStack(Stack* s)
{
	Person** temp = allocate(sizeof(Person) * s->top);
	int dessus = s->top;


	for (int i = 0; i < dessus; i++)
	{
		temp[i] = s->data[i];
	}
	bubbleSort(temp, dessus);


	for (int i = 0; i < dessus; i++)
	{
		pop(s);
	}
	for (int i = 0; i < dessus; i++)
	{
		push(s, temp[dessus-i -1]);
		printf("Age = %d\n", temp[dessus-1-i]->age);
	}

	memset(temp, NULL, sizeof(Person) * s->top);
}

void bubbleSort(Person** elements, int n)
{
	int switched = 0;

	for (int i = 0; i < (n - 1); i++)
	{
		if (elements[i]->age > elements[i + 1]->age)
		{
			Person* temp = elements[i]; 
			elements[i] = elements[i + 1]; 
			elements[i + 1] = temp; 
			switched = 1;
		}
		if (switched == 1)
		{
			switched = 0;
			i = -1;
		}
	}
}