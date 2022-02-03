#include "labo.h"
#include <string.h>

char* sousTexte(char* texte, int from, int to)
{
	char* start = &texte[from]; // récupère l'adresse du premier char de texte.
	static char texteFinal[512] = { 0 };
	int length = abs(to - from); // stock la longueur de la string voulue.
	printf("%d\n", length);
	

	for (int i = 0; i < length; i++)
	{
		//texte[i] = start[i];
		texteFinal[i] = start[i];
	}

	texteFinal[length] = 0;
	printf("%s\n", texteFinal);

	return texteFinal;
}

void set_String(char* text, String* s)
{
	s->length = strlen(text);
	s->characters = text;
}

int String_is_palindrome(String* s)
{
	int length = strlen(s->characters);
	static char reverse[512] = { 0 };

	for (int i = 0; i < length; i++)
	{
		reverse[i] = s->characters[length - (i + 1)];
	}
	printf("%s\n", reverse);
	printf("%s\n", s->characters);
	if (strcmp(reverse, s->characters) == 0)
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
	int switched = 0;
	for (int i = 0; i < (n - 1); i++)
	{
		if (elements[i] > elements[i + 1])
		{
			int temp = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = temp;
			switched = 1;
		}
		if (switched == 1)
		{
			switched = 0;
			i = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", elements[i]);
	}
}