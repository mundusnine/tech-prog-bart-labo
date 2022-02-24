#include "labo.h"

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
			s->data[s->top - it] = tempData;
			s->data[it] = tempData;
			it++;
		}
	}
}

void sortStack(Stack* s)
{

}
