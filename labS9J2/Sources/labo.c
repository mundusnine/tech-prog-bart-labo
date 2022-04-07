#include"labo.h"

AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* newMatrix = allocate(sizeof(AdjMatrix));
	newMatrix->len = 0;
	newMatrix->max_size = max_nodes;
	newMatrix->nodes = allocate(sizeof(Node) * newMatrix->max_size);
	for (int i = 0; i < newMatrix->max_size; i++)
	{
		newMatrix->nodes[i].cost = 0;
		newMatrix->nodes[i].path_from = 0;
		newMatrix->nodes[i].visited = 0;
		newMatrix->nodes[i].data = NULL;
	}

	newMatrix->adjGraph = allocate(sizeof(int*) * newMatrix->max_size);
	for (int i = 0; i < newMatrix->max_size; i++)
	{
		newMatrix->adjGraph[i] = allocate(sizeof(int) * newMatrix->max_size);
	}
	
	for (int a = 0; a < newMatrix->max_size; a++)
	{
		for (int b = 0; b < newMatrix->max_size; b++)
		{
			newMatrix->adjGraph[a][b] = 0;
		}
	}

	return newMatrix;
}

void add_node(AdjMatrix* graph, void* data)
{
	graph->nodes[graph->len++].data = data;
	graph->nodes[graph->len - 1].index = graph->len - 1;
}

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost)
{
	graph->adjGraph[fromNode][toNode] = cost;
}

void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	while (solvedPath->top != -1)
	{
		stack_pop(solvedPath);
	}

	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].cost = 0;
		graph->nodes[i].path_from = 0;
		graph->nodes[i].visited = 0;
	}

	int good = 0;

	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	queue_push(q, &graph->nodes[startNodeIndex]);
	Node* n = &graph->nodes[startNodeIndex];


	while (n != NULL)
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
			if ((graph->adjGraph[n->index][i] != 0))
			{
				if ((graph->nodes[i].cost == 0 && graph->nodes[i].visited != 1) || graph->nodes[i].cost > graph->adjGraph[n->index][i] + graph->nodes[n->index].cost)
				{
					graph->nodes[i].cost = graph->nodes[n->index].cost + graph->adjGraph[n->index][i];
					graph->nodes[i].path_from = n->index;
					queue_push(q, &graph->nodes[i]);
				}
			}
		}
	}

	if (good == 0)
	{
		return NULL;
	}

	n = &graph->nodes[endNodeIndex];
	stack_push(solvedPath, n);
	while (n != &graph->nodes[startNodeIndex])
	{
		n = &graph->nodes[n->path_from];
		stack_push(solvedPath, n);
	}
}