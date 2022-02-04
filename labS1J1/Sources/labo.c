#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"


char* sousTexte(char* texte, int from, int to)
{
	int x = 0;
	char SText[100] = {0};
	for (int i = from; i < to; i++)
	{
		SText[x] = texte[i];
		x++;
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
	int PalindromeVerif = 1;
	for (int i = 0; i < s->length; i++)
	{
		if (s->characters[i] != s->characters[s->length - 1 - i])
		{
			PalindromeVerif = 0;
		}
	}
	return PalindromeVerif;
}


void bubbleSort(int elements[], int n)
{
	int echanger = 0;
	int Temp = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int i2 = 0; i2 < n - 1 - i; i2++)
		{
			if (elements[i2] > elements[i2 + 1])
			{
				Temp = elements[i2 + 1];
				elements[i2 + 1] = elements[i2];
				elements[i2] = Temp;
			}
		}
	}
}
