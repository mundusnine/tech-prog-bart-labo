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
	
	int test = 0;
	for (int i = 0; i < max_nodes; i++)
	{
		for (int k = 0; k < max_nodes; k++)
		{
			newGraph->adjGraph[i][k] = 0;
			test++;
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
 Creer un node, lui attribuer le data et l'ajouter dans la matrice d'adjacence.
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
	while (solvedPath->top != -1) // Vide la stack
	{
		stack_pop(solvedPath);
	}

	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	Node* t = &graph->nodes[startNodeIndex];
	queue_push(q, t);
	graph->nodes[startNodeIndex].cost = 0; // Coût ini va à 0


	while (t != NULL)
	{
		t = queue_pop(q);
		if (t == NULL)
		{
			continuer:
			break;
		}
		t->visited = 1;

		if (t == &graph->nodes[endNodeIndex]) // Continue va skip la prochaine itération de for a la ligne 117
		{
			goto continuer;
			//continue;
		}

		for (int e = 0; e < graph->len; e++)
		{
			for (int j = 0; j < graph->len; j++)
			{
				// On regarde si le chemin existe et qu'il est un voisin de la node actuelle
				if (graph->adjGraph[e][j] != 0 && t == &graph->nodes[e]) // Je pars de la bonne place et il y a un chemin
				{
					if ((graph->nodes[j].visited == 0 && graph->nodes[j].cost == UINT8_MAX) || (graph->nodes[j].cost > graph->nodes[e].cost + graph->adjGraph[e][j]))
					{
						// Pousse le prochain voisin non visité dans la queue, update son cost et ajuste son chemin
						queue_push(q, &graph->nodes[j]);
						graph->nodes[j].cost = graph->adjGraph[e][j] + t->cost;
						graph->nodes[j].path_from = e;
					}
				}
			}
		}
	}





	// Assigne t a valeur de fin pour remplir la stack dans le bon sens (À travers les rev paths)
	t = &graph->nodes[endNodeIndex];

	stack_push(solvedPath, t);
	while (t != &graph->nodes[startNodeIndex])
	{
		t = &graph->nodes[t->path_from];
		stack_push(solvedPath, t);
	}
}