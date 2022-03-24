#include "labo.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>


char* sousTexte(char* texte, int from, int to) {
	int length = abs(to - from);
	char* debut = &texte[from];
	char copie[500] = { 0 };
	for (int i = 0; i < length; i++)
	{
		copie[i] = debut[i];
	}
	return copie; // char* sous = sousTexte(params)
}


// Fonction qui copie le param(tableau de txt) et en copie le contenu dans la struct string
void set_String(char* text, String* s) {
	s->characters = text;
	s->length = strlen(text);

}


int String_is_palindrome(String* s) {
	printf("%s %d\n", s->characters, s->length);

	int count = 0;
	int center = (int)ceil(s->length * 0.5);
	for (int i = 0; i < center; i++)
	{
		if (s->characters[i] == s->characters[s->length - i - 1])
		{
			count++;
		}
	}
	if (count == center)
	{
		return 1;
	}
	else
	{
		return 0;
	}
};

/*
* Implémenter la fonction bubble sort et trier le tableau
*/

// Bubblesort = Brute force
void bubbleSort(int elements[], int n) {
	int echange = 0;
	
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", elements[i]);
	}
	printf("%d\n\n", n);

	for (int i = 0; i <= n - 1; i++)
	{
		if (elements[i] > elements[i + 1] && elements[i+1] != NULL)
		{
			echange = 1;
			int temp = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = temp;
		}
		if (i >= n - 1 && echange == 1)
		{
			echange = 0;
			i = -1;
		}


	}

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", elements[i]);
	}
}