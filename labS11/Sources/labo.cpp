#include "labo.h"
#include <math.h>
#include <stdlib.h>
#define MAX 100

AdjMatrix* create_graph(size_t max_nodes) {
	AdjMatrix* graph = (AdjMatrix*)allocate(sizeof(AdjMatrix));
	graph->len = 0;
	graph->max_size = max_nodes;
	graph->nodes = (Node*)allocate(sizeof(Node) * max_nodes);
	for (int i = 0; i < max_nodes; ++i) {
		Node* n = &graph->nodes[i];
		n->cost = UINT8_MAX;
		n->graph_group = UINT8_MAX;
		n->visited = 0;
		n->data = "NONE";
		n->path_from = UINT8_MAX;
	}
	graph->adjGraph = (int**)allocate(sizeof(int*) * max_nodes);
	for (int i = 0; i < max_nodes; ++i) {
		graph->adjGraph[i] = (int*)allocate(sizeof(int) * max_nodes);
		for (int y = 0; y < max_nodes; ++y) {
			graph->adjGraph[i][y] = 0;
		}
	}
	return graph;
}

void add_node(AdjMatrix* graph, void* data, Vector2 pos) {
	Node* n = &graph->nodes[graph->len++];
	n->data = data;
	n->position = pos;
}

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost)
{
	graph->adjGraph[fromNode][toNode] = cost;
}


long long fibonacci(int n)
{
	if (n == 0) return 0; //condition de fin
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

long long fibonacci_memoization(int n)
{
	static long long tab[MAX] = { 0 };
	if (n == 0) return 0; //condition de fin
	if (n == 1) return 1;
	if (tab[n] != 0) // Regarde si le calcul de fibonacci(n) a deja ete fait
	{
		return tab[n]; // S'il est fait retourne le calcule
	}
	tab[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return tab[n];
}

long long fibonacci_memoization_malloc(int n)
{
	static long long* tab = NULL;
	tab = (long long*)allocate(sizeof(long long*) * MAX);
	if (tab == NULL)
	{

	}
	if (tab[n] != NULL)
	{
		tab[n] = (long long)malloc(sizeof(long long*));
	}
	tab[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return tab[n];
	
}
