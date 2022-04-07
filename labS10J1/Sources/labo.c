#include "labo.h"

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
	
	Node* curr = &graph->nodes[0];
	int groupId = 0;
	curr->graph_group = groupId;

	for (int i = 0; i < graph->max_size; i++)
	{
		if (graph->nodes[i].visited == 0)
		{
			curr = &graph->nodes[i];
			curr->visited = 1;
		}

		if (CheckIfNodesHasAdj(graph, i))
		{
			for (int j = 0; j < graph->max_size; j++)
			{
				if (graph->adjGraph[i][j] != 0)
				{
					if (graph->nodes[j].graph_group != UINT8_MAX)
					{
						if (graph->nodes[i].graph_group != UINT8_MAX)
						{
							int oldGroupId = graph->nodes[j].graph_group;
							int newGroupId = graph->nodes[i].graph_group;
							graph->nodes[j].graph_group = graph->nodes[i].graph_group;
							AdjustGraphGroup(graph, oldGroupId, newGroupId);
						}
						else
						{
							graph->nodes[i].graph_group = graph->nodes[j].graph_group;
						}
					}
					else if (graph->nodes[i].graph_group == graph->nodes[j].graph_group == UINT8_MAX)
					{
						graph->nodes[i].graph_group = graph->nodes[j].graph_group = ++groupId;
					}
					else
					{
						graph->nodes[j].graph_group = graph->nodes[i].graph_group;
					}
				}
			}
		}
		else
		{
			if (curr->graph_group == UINT8_MAX)
			{
				groupId++;
				curr->graph_group = groupId;
			}
		}
	}
}

int CheckIfNodesHasAdj(AdjMatrix* graph, int nodeIdx)
{
	for (int i = 0; i < graph->max_size; i++)
	{
		if (graph->adjGraph[nodeIdx][i] != 0)
		{
			return 1;
		}
	}
	return 0;
}

void AdjustGraphGroup(AdjMatrix* graph, int oldGroupId, int newGroupId)
{
	for (int i = 0; i < graph->max_size; i++)
	{
		if (graph->nodes[i].graph_group == oldGroupId)
		{
			graph->nodes[i].graph_group = newGroupId;
		}
	}
}

void astar(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
}
