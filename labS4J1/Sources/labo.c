#include "labo.h"
#include <stdio.h>
#include <stdlib.h>

Stack* new_stack(size_t max_size)
{
	Stack* s = allocate(sizeof(Stack));
	s->max_size = max_size;
	s->data = allocate(sizeof(void*) * max_size);
	s->top = 0;

	return s;
}

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

void* pop(Stack* s)
{
	if (s->top == 0)
	{
		return NULL;
	}
	else
	{
		void* tempData = s->data[s->top - 1];
		s->data[s->top - 1] = NULL;
		s->top--;
		return tempData;
	}
}

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

void reverseStack(Stack* s)
{
	int it = 0;
	for (int i = s->top; i > 0; i--)
	{
		if (it < (s->top / 2))
		{
			void* tempData = s->data[(s->top - 1) - it];
			s->data[(s->top -1) - it] = s->data[it];
			s->data[it] = tempData;
			it++;
		}
	}
}

void sortStack(Stack* s)
{
	int count = s->top;
	int switched = 0;
	Person** personne = allocate(sizeof(Person) * count);
	
	for (int i = 0; i < count; i++)
	{
		personne[i] = pop(s);
	}

	for (int i = 0; i < (count - 1); i++)
	{
		if (personne[i]->age < personne[i + 1]->age)
		{
			Person* temp = personne[i];
			personne[i] = personne[i + 1];
			personne[i + 1] = temp;
			switched = 1;
		}
		if (switched == 1)
		{
			switched = 0;
			i = -1;
		}
	}

	for (int i = 0; i < count; i++)
	{
		push(s, personne[i]);
	}

	for (int i = 0; i < count; i++)
	{
		Person* p = s->data[i];
		printf("name: %s, age: %d\n", p->name, p->age);
	}
}
