#include "labo.h"

/*
* Creer une matrice d'adjacence.
* Mettre len a 0. Mettre max_size a max_nodes.
* Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
* Pour chaque noeud de graph->nodes mettre le cost et path_from a UINT8_MAX et visited a 0.
* Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
* Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
* A chaque index de adjGraph mettez son cout a 0.
* Retourner le graph creer.
*/
AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* adjMatrix = allocate(sizeof(AdjMatrix));
	adjMatrix->len = 0;
	adjMatrix->max_size = max_nodes;

	adjMatrix->nodes = allocate(sizeof(Node) * adjMatrix->max_size);
	for (int i = 0; i < adjMatrix->max_size; i++)
	{
		adjMatrix->nodes[i].cost = 0;
		adjMatrix->nodes[i].path_from = 0;
		adjMatrix->nodes[i].visited = 0;
		adjMatrix->nodes[i].data = NULL;
	}

	adjMatrix->adjGraph = allocate(sizeof(int*) * adjMatrix->max_size);
	for (int i = 0; i < adjMatrix->max_size; i++)
	{
		adjMatrix->adjGraph[i] = allocate(sizeof(int) * adjMatrix->max_size);
	}
	for (int i = 0; i < adjMatrix->max_size; i++)
	{
		for (int i2 = 0; i2 < adjMatrix->max_size; i2++)
		{
			adjMatrix->adjGraph[i][i2] = 0;
		}
	}

	return adjMatrix;
}

/*
* Creer un node, lui attribuer le data et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data)
{
	graph->nodes[graph->len].data = data;
	graph->len++;
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
	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].visited = 0;
		graph->nodes[i].path_from = NULL;
		graph->nodes[i].cost = 0;
	}
	while (solvedPath->top > -1)
	{
		stack_pop(solvedPath);
	}

	Queue* pathQ = allocate(sizeof(Queue));
	queue_init(pathQ);
	Node* n = &graph->nodes[startNodeIndex];
	queue_push(pathQ,n);

	int currentIndex = startNodeIndex;
	int tempoIndex;
	int cost = 100;
	int prevCost =0;
	while (n != NULL)
	{
		n = queue_pop(pathQ);
		n->visited = 1;
		cost = 100;
		if (n == &graph->nodes[endNodeIndex])
		{
			break;
		}
		for (int i = 0; i < graph->len; i++)
		{
			if (cost > graph->adjGraph[currentIndex][i] && graph->nodes[i].visited!=1 && graph->adjGraph[currentIndex][i] !=0)
			{
				cost = graph->adjGraph[currentIndex][i];
				tempoIndex = i;
			}
		}
		graph->nodes[tempoIndex].path_from = currentIndex;
		prevCost = graph->nodes[currentIndex].cost;
		currentIndex = tempoIndex;
		graph->nodes[currentIndex].cost = cost + prevCost;
		queue_push(pathQ, &graph->nodes[currentIndex]);
	} 

	while (n->path_from != NULL)
	{
		stack_push(solvedPath, n);
		int indexPosition = n->path_from;
		n = &graph->nodes[indexPosition];
	}
	stack_push(solvedPath, n);
}