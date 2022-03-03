#include"labo.h"

Stack* new_stack(size_t max_size)
{
	Stack* newStack = allocate(sizeof(Stack));
	newStack->data = allocate(max_size * sizeof(void*));
	newStack->max_size = max_size;
	newStack->top = 0;
	return newStack;
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
	void* temp = s->data[s->top - 1];
	s->data[s->top + 1] = NULL;
	s->top--;
	return temp;
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
	void** temp = allocate(sizeof(void**) * s->top);
	for (int i = 0; i < s->top; i++)
	{
		temp[i] = s->data[s->top - i - 1];
	}
	for (int i = 0; i < s->top; i++)
	{
		s->data[i] = temp[i];
	}
	memset(temp, 0, sizeof(void**) * s->top);
}

void sortStack(Stack* s)
{
	Person** p = allocate(sizeof(s->data) * s->top);
	int top = s->top;
	for (int i = 0; i < s->top; i++)
	{
		p[i] = s->data[i];
	}

	for (int i = 0; i < s->top; i++)
	{
		for (int a = 0; a < s->top - i - 1; a++)
		{
			if (p[a]->age > p[a + 1]->age)
			{
				Person* temp1 = p[a];
				Person* temp2 = p[a + 1];

				p[a] = temp2;
				p[a + 1] = temp1;
			}
		}
	}

	for (int i = 0; i < top; i++)
	{
		pop(s);
	}

	for (int i = 0; i < top; i++)
	{
		push(s, p[top - i - 1]);
	}

	memset(p, 0, sizeof(s->data) * s->top);
}