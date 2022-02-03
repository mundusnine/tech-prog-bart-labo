#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"


char* sousTexte(char* texte, int from, int to)
{
	char SText[256] = {0};
	for (int i = from; i < to; i++)
	{
		SText[i] = texte[i];
	}
	return SText;
}


void set_String(char* text, String* s)
{
	s->length = strlen(text);
	for (int i = 0; i < s->length; i++)
	{
		s->characters[i] = text[i];
	}
}


int String_is_palindrome(String* s)
{
	int x = 0;
	for (int i = 0; i < s->length; i++)
	{
		if (s->characters[i] == s->characters[s->length - i])
		{
			x++;
		}
	}
	if (x >= s->length / 2)
	{
		return 1;
	}
	return 0;
}


void bubbleSort(int elements[], int n)
{

}
