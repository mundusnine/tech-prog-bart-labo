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
    Queue* q = allocate(sizeof(Queue));
    queue_init(q);
    Node* n = &graph->nodes[startNodeIndex];
    n->visited = 1;
    n->cost = 0;
    while (n != NULL)
    {
        for (int i = 0; i < graph->max_size; i++)
        {
            for (int c = 0; c < graph->max_size; c++)
            {
                if (graph->adjGraph[i][c] > 0 && &graph->nodes[i] == n)
                {

                    if (graph->nodes[c].cost != UINT8_MAX)
                    {
                        graph->nodes[c].visited = 1;
                        int cost = graph->nodes[i].cost + graph->adjGraph[i][c];
                        if (cost < graph->nodes[c].cost)
                        {
                            graph->nodes[c].cost = cost;
                            graph->nodes[c].path_from = i;
                        }
                    }
                    else
                    {
                        int cost = graph->nodes[i].cost + graph->adjGraph[i][c];
                        graph->nodes[c].cost = cost;
                        graph->nodes[c].path_from = i;
                        
                    }
                    if (graph->nodes[c].visited == 0)
                    {
                        queue_push(q, &graph->nodes[c]);
                    }
                }
                
                
            }
            n = queue_pop(q);
        }
    }

    n = &graph->nodes[endNodeIndex];
    while (n->path_from != UINT8_MAX)
    {
        stack_push(solvedPath, n);
        n = &graph->nodes[n->path_from];
        if (n == &graph->nodes[startNodeIndex])
        {
            stack_push(solvedPath, n);
            break;
        }
    }
}

