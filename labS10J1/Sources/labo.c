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
	graph->nodes = allocate(sizeof(Node) * max_nodes); 
	graph->adjGraph = allocate(sizeof(int*) * max_nodes);
	
	for (int i = 0; i < max_nodes; i++)
	{
		graph->nodes[i].cost = graph->nodes[i].graph_group = graph->nodes->path_from = UINT8_MAX;
		graph->nodes[i].visited = 0;
		graph->adjGraph[i] = allocate(sizeof(int) * max_nodes);

		for (int j = 0; j < max_nodes; j++)
		{
			graph->adjGraph[i][j] = 0;
		}
	}
	return graph;
}

/*
* Creer un node, lui attribuer le data, la position et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data, Vector2 pos)
{
	graph->nodes[graph->len].data = data;
	graph->nodes[graph->len++].position = pos;
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
	Node* currNode = &(graph->nodes[0]);
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	int groupNb = 0;


	while (currNode != NULL)
	{
		if (currNode->graph_group == UINT8_MAX)
		{
			currNode->graph_group = groupNb;
		}
		
		for (int i = 0; i < graph->len; i++)
		{
			for (int j = 0; i < graph->len; j++)
			{
				if (graph->adjGraph[i][j] != 0 && currNode == &graph->nodes[i])
				{

				}
			}
		}
	}
	
	for (int i = 0; i < graph->len; i++)
	{
		
	}
}

/*
* Implementer l'algorithme A*. Lorsqu'il n'y a aucun chemin entre deux node, la Stack doit être vide.
*/
void astar(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{

}