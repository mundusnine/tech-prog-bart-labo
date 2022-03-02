#include "labo.h"

Stack* new_stack(size_t max_size)
{
	Stack* newStack = allocate(sizeof(Stack));
	newStack->data = allocate(max_size * sizeof(void*));
	newStack->top = 0;
	newStack->max_size = max_size;
	return newStack;
}

void push(Stack* s, void* newData)
{
	if (s->top < s->max_size)
	{
		s->top++;
		s->data[s->top - 1] = newData;
	}
	else
	{
		return;
	}
}

void* pop(Stack* s)
{ 
	if (s->data[s->top - 1] != NULL)
	{
		void* tempData = s->data[s->top - 1];
		s->data[s->top - 1] = NULL;
		s->top--;
		return tempData;
	}
	else
	{
		return NULL;
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
		void* PeekData = s->data[s->top - 1];
		return PeekData;
	}
}

void reverseStack(Stack* s)
{
	int NbrElem = s->top;
	int j = 0;
	void** datas = allocate(s->top * sizeof(void*));
	
	for(int i = 0; i < NbrElem; i++)
	{
		datas[i] = s->data[i];
		s->data[i] = NULL;
	}
	
	for(int i = (NbrElem - 1); i >= 0; i--)
	{
		s->data[j] = datas[i];
		j++;
	}
}

void sortStack(Stack* s)
{
	int swap = 0;
	int NbrElem = s->top;
	Person* person = s->data[s->top - 1];
	Person** personTablo = allocate(sizeof(Person) * NbrElem);
	
	for(int i = NbrElem - 1; i >= 0; i--)
	{
		personTablo[i] = person;
		pop(s);
		person = s->data[s->top - 1];
	}

	for (int i = 0; i < NbrElem - 1; i++)
	{
		if (personTablo[i]->age < personTablo[i + 1]->age)
		{
			Person* personCopy = personTablo[i];
			personTablo[i] = personTablo[i + 1];
			personTablo[i + 1] = personCopy;
			swap = 1;
		}
		if (swap == 1)
		{
			swap = 0;
			i = -1;
		}
	}

	for (int i = 0; i < NbrElem; i++)
	{
		push(s, personTablo[i]);
	}
}
