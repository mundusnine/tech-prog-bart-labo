#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"

char* sousTexte(char* texte, int from, int to) {
	char sous[500] = { 0 };
	char* start = &texte[from];
	int lenght = abs(to - from);
	for (int i = 0; i < lenght; i++) {
		sous[i] = start[i];
	}
	printf("%s", sous);
	return sous;
}

void set_String(char* text, String* s) {
	s->characters = text;
	s->lenght = strlen(text);
}

int String_is_palindrome(String* s) {
	char text[100] = { 0 };
	char text2[100] = { 0 };
	int lenght = s->lenght;

	for (int i = 0; i < lenght;i++)
	{
		text[i] = s->characters[i];
		text2[i] = s->characters[lenght - i - 1];
	}
	if (strcmp(text, text2) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bubbleSort(int elements[], int n) {
	int switched = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (elements[i] > elements[i + 1])
		{
			int temp = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = temp;
			switched = 1;
		}
		if (i < n - 1 && switched == 1)
		{
			switched = 0;
			i = -1;
		}
	}
}