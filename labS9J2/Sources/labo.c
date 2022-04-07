#include "labo.h"

AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* adjMatrix = allocate(sizeof(AdjMatrix));
	adjMatrix->len = 0;
	adjMatrix->max_size = max_nodes;

	adjMatrix->nodes = allocate(sizeof(Node) * max_nodes);
	
	for (int i = 0; i < max_nodes; i++)
	{
		adjMatrix->nodes[i].cost = UINT8_MAX;
		adjMatrix->nodes[i].visited = 0;
		adjMatrix->nodes[i].path_from = UINT8_MAX;
		adjMatrix->nodes[i].data = NULL;

	}

	adjMatrix->adjGraph = allocate(sizeof(int*) * max_nodes);
	for (int c = 0; c < max_nodes; c++)
	{
		adjMatrix->adjGraph[c] = allocate(sizeof(int) * max_nodes);
		for (int i = 0; i < max_nodes; i++)
		{
			adjMatrix->adjGraph[c][i] = 0;
		}
	}
	return adjMatrix;
}

void add_node(AdjMatrix* graph, void* data)
{
	graph->nodes[graph->len++].data = data;
}

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost)
{
	graph->adjGraph[fromNode][toNode] = cost;
}

void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	
}

