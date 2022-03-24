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
	
}

void reverseStack(Stack* s)
{

}

void sortStack(Stack* s)
{

}
