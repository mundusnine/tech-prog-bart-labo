#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "labo.h"

#define HEAP_SIZE 2048 * 2048 * 4
static uint8_t* heap = NULL;
static size_t heap_top = 0;
void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

int main(int argc, char** argv) {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);

	HashTable* t = create_hashtable(100);
	assert(hash("yolo",100) == hash("yolo",100));//validate the hash function works
	printf("-----FIRST-----\n");
	int i = add_kv(t, "yolo", "You only live once.");
	i += add_kv(t, "yolo", "Once Only, You live .");
	if (i == 2) {
		printf("Il y a potentiellement un problème avec ta fonction add_kv\n");
	}
	//Blame the interwebs:https://www.youtube.com/watch?v=KaqC5FnvAEc
	if (!add_kv(t, "Trololo", "Sarouman.") || add_kv(t, "Trololo", "Gandalf, ohohohooooh ahhahhahaaaaah")) {
		printf("Il y a potentiellement un problème avec ta fonction add_kv\n");
	}

	void* dat = get_value(t, "yolo");
	if (dat != "You only live once.") {//Un string absolue va avoir un pointeur constant.
		printf("Il y a potentiellement un problème avec ta fonction add_kv\n");
	}

	dat = del_kv(t, "yolo");
	void* dat2 = get_value(t, "yolo");
	if (dat == NULL || dat2 != NULL) {
		printf("Il y a potentiellement un problème avec ta fonction del_kv\n");
	}

	printf("-----SECOND-----\n");

	for (int i = 0; i < 100; ++i) {
		char key[256] = { 0 };
		char value[256] = { 0 };
		snprintf(key, 256, "Jayz%i", i);
		snprintf(value, 256, "I've got %i problems, but a hash function ain't one.", i);
		add_kv(t, key, value);
	}
	char* tad = get_value(t, "Jayz99");
	if (strcmp(tad, "I've got 99 problems, but a hash function ain't one.") != 0) {
		printf("Il y a potentiellement un problème avec ta fonction add_kv ou get_value\n Le texte etait: %s",tad);
	}

	return 0;
}
