#include "labo.h"
#include <stdlib.h>
#include <string.h>


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


void set_String(char* text, String* s) {
	s->characters = text;
	s->length = strlen(text);

}
/*
Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
Si le mot est un palindrome retourner 1 sinon 0
*/
 // 122
int String_is_palindrome(String* s) {
	printf("%s %d\n", s->characters, s->length);

	/*
	for (int i = 0; i < s->length; i++)
	{

	}
	*/
};


void bubbleSort(int elements[], int n) {

}