#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"

Stack stack_init(size_t max_size) {
	Stack s;
	s.max = max_size;
	s.top = -1;
	s.elements = allocate(sizeof(void*) * s.max);
	return s;
}

void stack_push(Stack* s, void* element) {
	if (s->max != s->top + 1) {
		s->top++;
		s->elements[s->top] = element;
	}
}

void* stack_pop(Stack* s) {
	if (s->top > -1) {
		void* elem = s->elements[s->top];
		s->elements[s->top] = NULL;
		--s->top;
		return elem;
	}
	return NULL;
}
void queue_init(Queue* q) {
	q->next = q->prev = NULL;
	q->count = 0;
}
void queue_push(Queue* q, void* data) {
	QNode* n = allocate(sizeof(QNode));
	n->data = data;
	n->prev = n->next = NULL;
	if (q->prev == NULL) {
		q->prev = q->next = n;
	}
	else {
		QNode* temp = q->next;
		q->next = temp->prev = n;
		n->next = temp;
	}
}
void* queue_pop(Queue* q) {
	if (q->prev != NULL) {
		QNode* temp = q->prev;
		if(temp->prev != NULL)
			temp->prev->next = NULL;
		q->prev = temp->prev;
		q->count++;
		return temp->data;
	}
	return NULL;
}

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
	
	printf("-----FIRST-----\n");

	AdjMatrix* graph = create_graph(6);
	
	add_node(graph, "A");//0
	add_edge(graph, 0, 3, 10);
	add_edge(graph, 0, 2, 5);
	add_edge(graph, 0, 1, 2);

	add_node(graph, "B");//1
	add_edge(graph, 1, 3, 8);
	add_edge(graph, 1, 2, 2);

	add_node(graph, "C");//2
	add_edge(graph, 2, 3, 5);
	add_edge(graph, 2, 4, 3);

	add_node(graph, "D");//3
	add_edge(graph, 3, 4, 8);

	add_node(graph, "E");//4
	add_edge(graph, 4, 3, 8);
	add_edge(graph, 4, 5, 2);

	add_node(graph, "F");//5
	Stack s = stack_init(6);
	Queue tq;
	queue_init(&tq);

	dijkstra(graph, 0, 5, &s);
	Node* n = stack_pop(&s);
	queue_push(&tq, n);
	while (n != NULL) {
		printf("      %s", (char*)n->data,n->cost);
		n = stack_pop(&s);
		if (n != NULL) {
			queue_push(&tq, n);
			printf(" ->");
		}
	}
	printf("\n");
	n = queue_pop(&tq);
	while (n != NULL) {
		printf("cost: %i | ", n->cost);
		n = queue_pop(&tq);
	}
	printf("\n");

	printf("-----SECOND-----\n");
	AdjMatrix* graph2 = create_graph(6);

	add_node(graph2, "A");//0
	add_edge(graph2, 0, 3, 10);
	add_edge(graph2, 0, 2, 5);
	add_edge(graph2, 0, 1, 2);

	add_node(graph2, "B");//1
	add_edge(graph2, 1, 3, 3);
	add_edge(graph2, 1, 2, 2);

	add_node(graph2, "C");//2
	add_edge(graph2, 2, 3, 5);
	add_edge(graph2, 2, 4, 3);

	add_node(graph2, "D");//3
	add_edge(graph2, 3, 4, 1);

	add_node(graph2, "E");//4
	add_edge(graph2, 4, 3, 8);
	add_edge(graph2, 4, 5, 2);

	add_node(graph2, "F");//5
	add_edge(graph2, 5, 0, 2);

	dijkstra(graph2, 0, 5, &s);
	n = stack_pop(&s);
	queue_push(&tq, n);
	while (n != NULL) {
		printf("      %s", (char*)n->data, n->cost);
		n = stack_pop(&s);
		if (n != NULL) {
			n->path_from = UINT8_MAX;
			queue_push(&tq, n);
			printf(" ->");
		}
	}
	printf("\n");
	n = queue_pop(&tq);
	while (n != NULL) {
		printf("cost: %i | ", n->cost);
		n->cost = UINT8_MAX;
		n->visited = 0;
		n = queue_pop(&tq);
	}
	printf("\n");

	printf("-----THIRD-----\n");
	dijkstra(graph2, 3, 0, &s);
	n = stack_pop(&s);
	queue_push(&tq, n);
	while (n != NULL) {
		printf("      %s", (char*)n->data, n->cost);
		n = stack_pop(&s);
		if (n != NULL) {
			n->path_from = UINT8_MAX;
			queue_push(&tq, n);
			printf(" ->");
		}
	}
	printf("\n");
	n = queue_pop(&tq);
	while (n != NULL) {
		printf("cost: %i | ", n->cost);
		n->cost = UINT8_MAX;
		n->visited = 0;
		n = queue_pop(&tq);
	}
	printf("\n");

	printf("-----FOURTH-----\n");
	dijkstra(graph2, 1, 0, &s);
	n = stack_pop(&s);
	queue_push(&tq, n);
	while (n != NULL) {
		printf("      %s", (char*)n->data, n->cost);
		n = stack_pop(&s);
		if (n != NULL) {
			n->path_from = UINT8_MAX;
			queue_push(&tq, n);
			printf(" ->");
		}
	}
	printf("\n");
	n = queue_pop(&tq);
	while (n != NULL) {
		printf("cost: %i | ", n->cost);
		n->cost = UINT8_MAX;
		n->visited = 0;
		n = queue_pop(&tq);
	}
	printf("\n");

	return 0;
}
