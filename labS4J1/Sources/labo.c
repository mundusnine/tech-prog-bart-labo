#include "labo.h"

Stack* new_stack(size_t max_size)
{
	Stack* stack = allocate(sizeof(Stack));
	stack->data = allocate(sizeof(void*) * max_size);
	stack->top = 0;
	stack->max_size = max_size;
}

void push(Stack* s, void* newData)
{
	if (s->top < s->max_size)
	{
		s->data[s->top] = newData;
		s->top++;
	}
}

void* pop(Stack* s)
{
	if (s->data < s->max_size)
	{
		if (s->top != NULL)
		{
			if (s->data == NULL)
			{
				return NULL;
			}
			return s->data;
			s->data = NULL;
			s->top--;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

void* peek(Stack* s)
{
	if (s->data != NULL)
	{

	}
}

void reverseStack(Stack* s)
{

}

void sortStack(Stack* s)
{

}