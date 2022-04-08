#include "labo.h"
#include <math.h>

AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* graph = allocate(sizeof(AdjMatrix));
	graph->len = 0;
	graph->max_size = max_nodes;
	graph->nodes = allocate(sizeof(Node) * graph->max_size);

	for (int i = 0; i < graph->max_size; i++)
	{
		graph->nodes[i].cost = graph->nodes[i].path_from = graph->nodes[i].graph_group = UINT8_MAX;
		graph->nodes[i].visited = 0;
		graph->nodes[i].data = NULL;
		graph->nodes[i].position.x = 0;
		graph->nodes[i].position.y = 0;
	}

	graph->adjGraph = allocate(sizeof(int*) * graph->max_size);

	for (int i = 0; i < graph->max_size; i++)
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

void add_node(AdjMatrix* graph, void* data, Vector2 pos)
{
	graph->nodes[graph->len].data = data;
	graph->nodes[graph->len++].position = pos;
}

void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost)
{
	graph->adjGraph[fromNode][toNode] = cost;
}

void build_groups(AdjMatrix* graph)
{
	if (graph->len == 0 && graph->nodes[0].data == NULL) //si le graph n'a pa sde nodes.
	{
		return;
	}

	ResetNodes(graph);

	Queue q;
	queue_init(&q);

	Node* curr = &graph->nodes[0];
	int visitedNodesCnt = 0; //nb de node visitées.
	int groupId = 0; //numero du groupe.
	curr->graph_group = groupId;

	while (curr != NULL)
	{
		curr->visited = 1;
		visitedNodesCnt++;

		int currNodeIdx = NodeIdx(graph, curr); //retourne l'index de la node curr dans graph->nodes.

		for (int i = 0; i < graph->len; i++)
		{
			if (graph->adjGraph[currNodeIdx][i] != 0)
			{
				if (graph->nodes[i].graph_group == UINT8_MAX)
				{
					graph->nodes[i].graph_group = graph->nodes[currNodeIdx].graph_group;
				}
				else
				{
					int oldGroup = graph->nodes[i].graph_group;
					int newGroup = graph->nodes[currNodeIdx].graph_group;
					graph->nodes[i].graph_group = graph->nodes[currNodeIdx].graph_group;
					ChangeIdx(graph, oldGroup, newGroup); //change le graph_group de tout les nodes qui ont le oldGroup.
				}

				if (graph->nodes[i].visited == 0)
				{
					graph->nodes[i].visited = 1;
					queue_push(&q, &graph->nodes[i]);
				}
			}
		}
		curr = queue_pop(&q);

		if (curr == NULL && visitedNodesCnt < graph->len)
		{
			int idx = GetSmallerIdxNotVisitedNode(graph); //retourne l'index le plus petit d'une node non visité dans graph->nodes.
			curr = &graph->nodes[idx];
			groupId++;
			curr->graph_group = groupId;
		}
	}
}

int NodeIdx(AdjMatrix* graph, Node* node)
{
	if (node != NULL)
	{
		for (int i = 0; i < graph->len; i++)
		{
			if (node == &graph->nodes[i])
			{
				return i;
			}
		}
	}
	return -1;
}

void ChangeIdx(AdjMatrix* graph, int oldIndex, int newIndex)
{
	for (int i = 0; i < graph->len; i++)
	{
		if (graph->nodes[i].graph_group == oldIndex)
		{
			graph->nodes[i].graph_group = newIndex;
		}
	}
}

int GetSmallerIdxNotVisitedNode(AdjMatrix* graph)
{
	for (int i = 0; i < graph->len; i++)
	{
		if (graph->nodes[i].visited == 0)
		{
			return i;
		}
	}
}


void astar(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	if (solvedPath->top != -1) //clear stack si data
	{
		while (solvedPath->top > -1)
		{
			stack_pop(solvedPath);
		}
	}

	ResetNodes(graph);
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
				if (curr->cost + graph->adjGraph[nodeIdx][i] + GetDistance(graph, i, endNodeIndex ) < graph->nodes[i].cost)
				{
					graph->nodes[i].cost = curr->cost + graph->adjGraph[nodeIdx][i] + GetDistance(graph, i, endNodeIndex);

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

void ResetNodes(AdjMatrix* graph)
{
	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].visited = 0;
		graph->nodes[i].path_from = graph->nodes->cost = UINT8_MAX;
	}
}

int GetDistance(AdjMatrix* graph, int fromIndex, int endIndex)
{
	Vector2 v;
	v.x = abs(graph->nodes[endIndex].position.x - graph->nodes[fromIndex].position.x);
	v.y = abs(graph->nodes[endIndex].position.y - graph->nodes[fromIndex].position.y);
	int distance = sqrt(pow(v.x, 2) + pow(v.y, 2));

	return distance;
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

