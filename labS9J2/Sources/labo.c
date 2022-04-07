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
	AdjMatrix* graph = allocate(sizeof(AdjMatrix));
	graph->len = 0;
	graph->max_size = max_nodes;
	graph->nodes = allocate(sizeof(Node) * max_nodes);

	for (int i = 0; i < graph->max_size; i++)
	{
		graph->nodes[i].cost = graph->nodes[i].path_from = UINT8_MAX;
		graph->nodes[i].visited = 0;
	}

	graph->adjGraph = allocate(sizeof(int*) * max_nodes);

	for (int i = 0; i < max_nodes; i++)
	{
		graph->adjGraph[i] = allocate(sizeof(int) * max_nodes);
	}

	for (int i = 0; i < max_nodes; i++)
	{
		for (int j = 0; j < max_nodes; j++)
		{
			graph->adjGraph[i][j] = 0;
		}
	}
	return graph;
}

/*
* Creer un node, lui attribuer le data et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data)
{
	graph->nodes[graph->len++].data = data;
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
	//Vider la stack si elle n'est pas vide
	while (solvedPath->top != -1)
	{
		stack_pop(solvedPath);
	}

	graph->nodes[startNodeIndex].cost = 0;

	Node* currNode = &(graph->nodes[startNodeIndex]);
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);

	while (currNode != NULL)
	{
		currNode->visited = 1;

		for (int i = 0; i < graph->len; i++)
		{
			for (int j = 0; j < graph->len; j++)
			{
				if (graph->adjGraph[i][j] != 0 && currNode == &(graph->nodes[i]))
				{
					if ((graph->nodes[j].visited != 1 && graph->nodes[j].cost == UINT8_MAX) || (graph->nodes[j].cost > graph->nodes[i].cost + graph->adjGraph[i][j]))
					{
						queue_push(q, &(graph->nodes[j]));
						graph->nodes[j].cost = currNode->cost + graph->adjGraph[i][j];
						graph->nodes[j].path_from = i;
					}
				}
			}
		}
		currNode = queue_pop(q);
	}
	currNode = &(graph->nodes[endNodeIndex]);
	stack_push(solvedPath, currNode);
	while (currNode != &(graph->nodes[startNodeIndex]))
	{
		currNode = &(graph->nodes[currNode->path_from]);
		stack_push(solvedPath, currNode);
	}
}