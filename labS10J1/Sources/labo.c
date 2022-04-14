#include "labo.h"

/*
* Creer une matrice d'adjacence. Mettre len a 0. Mettre max_size a max_nodes.
* Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
* Pour chaque noeud de graph->nodes mettre le cost, graph_group et path_from a UINT8_MAX et visited a 0.
* Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
* Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
* A chaque index de adjGraph mettez son cout a 0. 0 indique qu'il n'y a pas d'adjacence.
* Retourner le graph creer.
*/
AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* graph = allocate(sizeof(AdjMatrix));
	graph->len = 0;
	graph->max_size = max_nodes;
	graph->nodes = allocate(sizeof(Node) * graph->max_size);
	for (int i = 0; i < graph->max_size; i++)
	{
		graph->nodes[i].cost = UINT8_MAX;
		graph->nodes[i].graph_group = UINT8_MAX;
		graph->nodes[i].path_from = UINT8_MAX;
		graph->nodes[i].visited = 0;
		graph->nodes[i].data = 0;
	}
	graph->adjGraph = allocate(sizeof(int*) * graph->max_size);
	for (int j = 0; j < graph->max_size; j++)
	{
		graph->adjGraph[j] = allocate(sizeof(int) * graph->max_size);
		for (int k = 0; k < graph->max_size; k++)
		{
			graph->adjGraph[j][k] = 0;
		}
	}
	return graph;
}

/*
* Creer un node, lui attribuer le data, la position et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data, Vector2 pos)
{
	graph->nodes[graph->len++].data = data;
	graph->nodes[graph->len - 1].index = graph->len - 1;
	graph->nodes[graph->len - 1].position = pos;
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
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	int group = 1;
	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].graph_group = 0;
	}
	for (int i = 0; i < graph->len; i++)
	{
		Node* n = &graph->nodes[i];
		if (n->graph_group != 0)
		{
			queue_push(q, n);
			while (n!=NULL)
			{
				n = queue_pop(q);
				if (n == NULL)
				{
					group++;
					break;
				}
				n->graph_group = group;

				for (int j = 0; j < graph->len; j++)
				{
					if (graph->adjGraph[n->index][j] != 0 && graph->nodes[j].graph_group != group)
					{
						if (graph->nodes[j].graph_group != 0)
						{
							for (int k = 0; k < graph->len; i++)
							{
								if (graph->nodes[k].graph_group == graph->nodes[k].graph_group)
								{
									graph->nodes[k].graph_group = group;
								}
							}
						}
						else
						{
							queue_push(q, &graph->nodes[j]);
						}
					}
				}
			}
		}
	}
}

/*
* Implementer l'algorithme A*. Lorsqu'il n'y a aucun chemin entre deux node, la Stack doit être vide.
*/
void astar(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	while (solvedPath->top!=-1)
	{
		stack_pop(solvedPath);
	}
	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].cost = 0;
		graph->nodes[i].path_from = 0;
		graph->nodes[i].visited = 0;
	}
	if (graph->nodes[startNodeIndex].graph_group != graph->nodes[endNodeIndex].graph_group)
	{
		return NULL;
	}
	int yes = 0;
	
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
			yes = 1;
			continue;
		}
		for (int i = 0; i < graph->len; i++)
		{
			if (graph->adjGraph[n->index][i] != 0)
			{
				if ((graph->nodes[i].cost == 0 && graph->nodes[i].visited != 1) || graph->nodes[i].cost > graph->adjGraph[n->index][i] + graph->nodes[n->index].cost + CheckDistance(&graph->nodes[endNodeIndex], &graph->nodes[i]))
				{
					graph->nodes[i].cost = graph->nodes[n->index].cost + graph->adjGraph[n->index][i] + CheckDistance(&graph->nodes[endNodeIndex], &graph->nodes[i]);
					graph->nodes[i].path_from = n->index;
					queue_push(q, &graph->nodes[i]);
				}
			}
		}
	}
	if (yes == 0)
	{
		return NULL;
	}
	n = &graph->nodes[endNodeIndex];
	stack_push(solvedPath, n);

	while (n!=&graph->nodes[startNodeIndex])
	{
		n = &graph->nodes[n->path_from];
		stack_push(solvedPath, n);
	}
}

uint8_t CheckDistance(Node* endNode, Node* currNode)
{
	Vector2 vect;
	vect.x = endNode->position.x - currNode->position.x;
	vect.y = endNode->position.y - currNode->position.y;

	if (vect.x < 0)
	{
		vect.x = -vect.x;
	}
	if (vect.y < 0)
	{
		vect.y = -vect.y;
	}
	uint8_t distance = (vect.x * vect.x) + (vect.y * vect.y);
	distance = sqrt(distance);
	return distance;
}