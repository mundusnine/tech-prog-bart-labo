#include "labo.h"


/*
struct AdjMatrix {
	int** adjGraph;// Essentiellement: int[][]
	Node* nodes;
	size_t len;
	size_t max_size;
};
*/

/*
* Creer une matrice d'adjacence.
	Mettre len a 0.
	Mettre max_size a max_nodes.
	Allouer de la memoire pour le max de noeud specifier i.e. pour graph->nodes.
	Pour chaque noeud de graph->nodes mettre le cost et path_from a UINT8_MAX et visited a 0.

	Pour adjGraph, allouer une quantiter de int* relatif a la valeur de max_nodes.
	Dans chaque int* allouer un tableau de int relatif a la valeur max_nodes.
*	 A chaque index de adjGraph mettez son cout a 0.
* Retourner le graph crée. 
*/

AdjMatrix* create_graph(size_t max_nodes)
{
	AdjMatrix* newGraph = allocate(sizeof(AdjMatrix));
	newGraph->len = 0;
	newGraph->max_size = max_nodes;

	newGraph->nodes = allocate(sizeof(Node) * max_nodes);

	for (int i = 0; i < max_nodes; i++) 
	{
		newGraph->nodes[i].cost = UINT8_MAX;
		newGraph->nodes[i].path_from = UINT8_MAX;
		newGraph->nodes[i].visited = 0;
		newGraph->nodes[i].data = NULL;
	}

	
	newGraph->adjGraph = allocate(sizeof(int*) * max_nodes);
	for (int i = 0; i < max_nodes; i++)
	{
		newGraph->adjGraph[i] = allocate(sizeof(int) * max_nodes);
	}
	

	for (int i = 0; i < max_nodes; i++)
	{
		for (int k = 0; i < max_nodes; i++)
		{
			newGraph->adjGraph[i][k] = 0;
		}
	}
	return newGraph;
}

/*
Node* n = allocate(sizeof(Node) * max_size) / tableau de Nodes *

Node** n = allocate(sizeof(Node*) * max_size) / tableau de pointeurs ** 


sizeof(Node) = grosse taille
sizeof(Node*) = sizeof(int) = Petite taille 

/*
* Creer un node, lui attribuer le data et l'ajouter dans la matrice d'adjacence.
*/

void add_node(AdjMatrix* graph, void* data)
{

	graph->nodes[graph->len].data = data;

	graph->len++;
}

/*
 Ajouter un lien dans la matrice d'adjacence, d'un noeud a l'autre noeud, en specifiant le cout y etant relier.
*/
void add_edge(AdjMatrix* graph, int fromNode, int toNode, uint8_t cost)
{
	graph->adjGraph[fromNode][toNode] = cost;
}

void dijkstra(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{

}