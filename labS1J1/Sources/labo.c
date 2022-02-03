#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"

char* sousTexte(char* texte, int from, int to)
{
	char test[512] = {0};
	char* a = &texte[from];
	int diff = abs(to - from);

	for (int i = 0; i < diff; i++)
	{
		test[i] = a[i];
	}
	printf("%s", test);
	return test;
}

void set_String(char* text, String* s)
{
	s->characters = text;
	s->length = strlen(text);
}

int String_is_palindrome(String* s)
{
	char check1[512] = { 0 };
	char check2[512] = { 0 };
	for (int i = 0; i < s->length; i++)
	{
		check1[i] = s->characters[i];
		check2[i] = s->characters[s->length - i - 1];
	}
	if (strcmp(check1, check2) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bubbleSort(int elements[], int n)
{
	int reset = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (elements[i] > elements[i + 1])
		{
			int nombre = elements[i + 1];
			elements[i + 1] = elements[i];
			elements[i] = nombre;
			reset = 1;
		}
		if (reset == 1)
		{
			i = -1;
			reset = 0;
		}
	}
}





