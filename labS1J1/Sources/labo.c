#include "labo.h"

char* sousTexte(char* texte, int from, int to) {
	static char sub[100] = { 0 };
	char* start = &texte[from];
	int length = abs(to - from);

	for (int i = 0; i < length; i++)
	{
		sub[i] = start[i];
	}
	
	sub[length] = 0;
	return sub;
} 

/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {
	s->characters = text;
	s->length = strlen(text);
}


/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {
	int longueur = strlen(s->characters);
	char inverse[10] = { 0 };



}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {

}