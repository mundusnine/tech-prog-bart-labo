#include "labo.h"
#include <string.h>
#include <stdlib.h>

char* sousTexte(char* texte, int from, int to)
{
	//soustexte marche
	static char max[512] = { 0 };
	char* start = &texte[from];
	int lenght = abs(to - from);
	for (int i = 0; i < lenght; ++i)
	{
		max[i] = start[i];
	}
	max[lenght] = 0;
	return max;
}

void set_String(char* text, String* s)
{
	//il marche
	//string.charachters = data
	int lenght = strlen(text);
	s->characters = (char*)malloc(sizeof(char) * lenght);
	s->characters[lenght] = 0;
	for (int i = 0; i < lenght; i++)
	{
		s->characters[i] = text[i];
	}
	s->lenght = strlen(s->characters);
}

int String_is_palindrome(String* s)
{
	//il marche
	int temp = s->lenght -1;
	for (int i = 0; i < s->lenght; i++)
	{
		if (s->characters[i] != s->characters[temp])
		{
			return 0;
		}
		temp--;
	}

	return 1;
}

void bubbleSort(int elements[], int n)
{
	//il marhce
	int condition = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if(elements[i] > elements[i+1])
		{
			int temp = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = temp;
			condition = 1;
		}
		if (i == n - 2 && condition)
		{
			i = -1;
			condition = 0;
		}
	}
	
}