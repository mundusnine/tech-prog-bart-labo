#include "labo.h"

/*
* Creer une matrice d'adjacence. Mettre len a 0. Mettre max_size a max_nodes.
* Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
* Pour chaque noeud de graph->nodes mettre le cost et path_from a UINT8_MAX et visited a 0.
* Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
* Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
* A chaque index de adjGraph mettez son cout a 0.
* Retourner le graph creer.
*/
AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* AM = allocate(sizeof(AdjMatrix));
	AM->len = 0;
	AM->max_size = max_nodes;
	AM->nodes = allocate(sizeof(Node) * AM->max_size);
	for (int i = 0; i < AM->max_size; i++)
	{
		AM->nodes[i].cost = UINT8_MAX;
		AM->nodes[i].path_from = UINT8_MAX;
		AM->nodes[i].visited = 0;
		AM->nodes[i].data = 0;
	}
	AM->adjGraph = allocate(sizeof(int*) * AM->max_size);
	for (int j = 0; j < AM->max_size; j++)
	{
		AM->adjGraph[j] = allocate(sizeof(int) * AM->max_size);
		for (int k = 0; k < AM->max_size; k++)
		{
			AM->adjGraph[j][k] = 0;
		}
	}
	return AM;
}

/*
* Creer un node, lui attribuer le data et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data)
{
	graph->nodes[graph->len++].data = data;
	graph->nodes[graph->len - 1].index = graph->len - 1;
}

/*
* Ajouter un lien dans la matrice d'adjacence, d'un noeud a l'autre noeud, en specifiant le cout y etant relier.
*/
void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost)
{
	graph->adjGraph[fromNode][toNode] = cost;
}

/*
* Implementer l'algorithme de dijkstra.
*/
void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	queue_push(q, &graph->nodes[startNodeIndex]);
	Node* n = &graph->nodes[startNodeIndex];

	int good = 0;

	while (n!=NULL)
	{
		n = queue_pop(q);
		if (n == NULL)
		{
			break;
		}
		n->visited = 1;
		if (n == &graph->nodes[endNodeIndex])
		{
			good = 1;
			continue;
		}
		for (int i = 0; i < graph->len; i++)
		{
			
		}

	}
}