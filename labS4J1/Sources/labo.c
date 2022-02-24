#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"

Stack* new_stack(size_t max_size)
{
	Stack* s = allocate(sizeof(void*) * max_size);
	s->data = allocate(sizeof(void**) * max_size);
	s->max_size = max_size;
	s->top = 0;
	return s;
}


void push(Stack* s, void* newData)
{
	if (s->top >= 0 && s->top < s->max_size)
	{
		s->data[s->top] = newData;
		s->top++;
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
		void* info = s->data[s->top - 1];
		s->data[s->top] = NULL;
		s->top--;
		return info;
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
	void** t = allocate(sizeof(s->data));
	for (int i = 0; i < s->top; i++)
	{
		t[i] = s->data[s->top - i - 1];
	}
	for (int i = 0; i < s->top; i++)
	{
		s->data[i] = t[i];
	}
	memset(t, 0, sizeof(void**));
}


void sortStack(Stack* s)
{

	for (int i = 0; i < s->top; i++)
	{

	}
}