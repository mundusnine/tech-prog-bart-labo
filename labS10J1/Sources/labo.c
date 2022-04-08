#include "labo.h"

/*
* Creer une matrice d'adjacence.
* Mettre len a 0. Mettre max_size a max_nodes.
* Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
* Pour chaque noeud de graph->nodes mettre le cost, graph_group et path_from a UINT8_MAX et visited a 0.
* Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
* Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
* A chaque index de adjGraph mettez son cout a 0. 0 indique qu'il n'y a pas d'adjacence.
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
		adjMatrix->nodes[i].graphGroup = UINT8_MAX;
		adjMatrix->nodes[i].path_from = UINT8_MAX;
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
* Creer un node, lui attribuer le data, la position et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data, Vector2 pos)
{
	graph->nodes[graph->len].data = data;
	graph->nodes[graph->len].position = pos;
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
* Construire les groupes de nodes. Faire l'algorithme qui determine l'association entre noeud.
*/
void build_groups(AdjMatrix* graph)
{
	Queue* pathQ = allocate(sizeof(Queue));
	Queue* pathQNum = allocate(sizeof(Queue));
	queue_init(pathQ);
	queue_init(pathQNum);
	Node* n;
	int currentIndex = -1;

	int graphGroups = 0;
	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].visited = 0;
	}
	for (int i = 0; i < graph->len; i++)
	{
		if (graph->nodes[i].visited == 0)
		{
			n = &graph->nodes[i];
			n->graphGroup = graphGroups;
			queue_push(pathQ, n);
			queue_push(pathQNum, i);
			while (n != NULL)
			{
				n = queue_pop(pathQ);
				currentIndex = queue_pop(pathQNum);
				if (n != NULL)
				{
					n->visited = 1;
					for (int i2 = 0; i2 < graph->len; i2++)
					{
						if (graph->nodes[i2].visited == 0 && graph->adjGraph[currentIndex][i2] > 0)
						{
							graph->nodes[i2].graphGroup = graphGroups;
							queue_push(pathQ, &graph->nodes[i2]);
							queue_push(pathQNum, i2);
						}
					}
				}
			}
			graphGroups++;
		}
	}
}

/*
* Implementer l'algorithme A*. Lorsqu'il n'y a aucun chemin entre deux node, la Stack doit être vide.
*/
void astar(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].visited = 0;
		graph->nodes[i].path_from = UINT8_MAX;
		graph->nodes[i].cost = UINT8_MAX;
	}
	while (solvedPath->top > -1)
	{
		stack_pop(solvedPath);
	}

	Queue* pathQ = allocate(sizeof(Queue));
	Queue* pathQNum = allocate(sizeof(Queue));
	queue_init(pathQ);
	queue_init(pathQNum);
	Node* n = &graph->nodes[startNodeIndex];
	queue_push(pathQ, n);
	queue_push(pathQNum, startNodeIndex);
	n->cost = 0;
	int currentIndex = -1;
	int cost = -1;
	if (graph->nodes[startNodeIndex].graphGroup == graph->nodes[endNodeIndex].graphGroup)
	{
		while (n != NULL)
		{
			n = queue_pop(pathQ);
			currentIndex = queue_pop(pathQNum);
			n->visited = 1;
			if (n == &graph->nodes[endNodeIndex])
			{
				break;
			}
			for (int i = 0; i < graph->len; i++)
			{
				if (!graph->nodes[i].visited && graph->adjGraph[currentIndex][i] > 0)
				{
					double x2 = pow((graph->nodes[i].position.x - graph->nodes[endNodeIndex].position.x), 2);
					double y2 = pow((graph->nodes[i].position.y - graph->nodes[endNodeIndex].position.y), 2);
					cost = graph->nodes[currentIndex].cost + sqrt(x2 + y2) + graph->adjGraph[currentIndex][i];
					if (graph->nodes[i].cost > cost)
					{
						queue_push(pathQ, &graph->nodes[i]);
						queue_push(pathQNum, i);
						graph->nodes[i].cost = cost;
						graph->nodes[i].path_from = currentIndex;
					}
				}
			}
		}
		while (n->path_from != UINT8_MAX)
		{
			stack_push(solvedPath, n);
			int indexPosition = n->path_from;
			n = &graph->nodes[indexPosition];
		}
		stack_push(solvedPath, n);
	}
}