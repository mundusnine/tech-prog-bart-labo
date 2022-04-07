#include "labo.h"

AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* graph = allocate(sizeof(AdjMatrix));
	graph->len = 0;
	graph->max_size = max_nodes;
	graph->nodes = allocate(sizeof(Node) * max_nodes);

	for (size_t i = 0; i < graph->max_size; i++)
	{
		graph->nodes[i].cost = graph->nodes[i].path_from = UINT8_MAX;
		graph->nodes[i].visited = 0;
		graph->nodes[i].data = NULL;
	}

	graph->adjGraph = allocate(sizeof(int*) * graph->max_size);

	for (size_t i = 0; i < graph->max_size; i++)
	{
		graph->adjGraph[i] = allocate(sizeof(int) * graph->max_size);
	}

	for (int i = 0; i < graph->max_size; i++)
	{
		for (int j = 0; j < graph->max_size; j++)
		{
			graph->adjGraph[i][j] = 0;
		}
	}

	return graph;
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
	if (solvedPath->top != -1) //clear stack si data
	{
		while (solvedPath->top > -1)
		{
			stack_pop(solvedPath);
		}
	}

	Queue q;
	queue_init(&q);

	if (startNodeIndex == endNodeIndex) //si le départ = arrivé, terminer la func.
	{
		return;
	}

	graph->nodes[startNodeIndex].cost = 0; //mettre le cost de la node[startNodeIndex] à 0.

	Node* curr = &(graph->nodes[startNodeIndex]);
	curr->visited = 1;
	while (curr != NULL)
	{
		int nodeIdx = GetNodeIdx(graph, curr);

		for (int i = 0; i < graph->max_size; i++) //parcourir tout les idx pour savoir lesquels sont des adj et ensuite les push sur la queue.
		{
			if (graph->adjGraph[nodeIdx][i] != 0)
			{
				if (curr->cost + graph->adjGraph[nodeIdx][i] < graph->nodes[i].cost)
				{
					graph->nodes[i].cost = curr->cost + graph->adjGraph[nodeIdx][i];

					graph->nodes[i].path_from = nodeIdx;

					if (graph->nodes[i].visited == 0)
					{
						graph->nodes[i].visited = 1;
						queue_push(&q, &(graph->nodes[i]));
					}
				}
			}
		}
		curr = queue_pop(&q);
	}

	curr = &(graph->nodes[endNodeIndex]);

	if (curr->path_from == UINT8_MAX) //si la node de fin n'a pas de communication avec la node de départ.
	{
		return NULL;
	}

	while (1)
	{
		stack_push(solvedPath, curr);
		if (curr != &(graph->nodes[startNodeIndex]))
		{
			curr = &(graph->nodes[curr->path_from]);
		}
		else
		{
			break;
		}
	}
}

int GetNodeIdx(AdjMatrix* graph, Node* nPtr)
{
	if (nPtr != NULL)
	{
		for (int i = 0; i < graph->len; i++)
		{
			if (nPtr == &(graph->nodes[i]))
			{
				return i;
			}
		}
	}
	return -1;
}