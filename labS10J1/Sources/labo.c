#include "labo.h"
#include <math.h>

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
		newGraph->nodes[i].graph_group = UINT8_MAX;
	}


	newGraph->adjGraph = allocate(sizeof(int*) * max_nodes);
	for (int i = 0; i < max_nodes; i++)
	{
		newGraph->adjGraph[i] = allocate(sizeof(int) * max_nodes);
	}

	for (int i = 0; i < max_nodes; i++)
	{
		for (int k = 0; k < max_nodes; k++)
		{
			newGraph->adjGraph[i][k] = 0;
		}
	}
	return newGraph;
}

/*
* Creer un node, lui attribuer le data, la position et l'ajouter dans la matrice d'adjacence.
*/
void add_node(AdjMatrix* graph, void* data, Vector2 pos)
{
	graph->nodes[graph->len].data = data;
	graph->nodes[graph->len].h.x = pos.x;
	graph->nodes[graph->len].h.y = pos.y;
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
	int curGrp = 0;
	for (int i = 0; i < 6; i++)
	{
		graph->nodes[i].graph_group = curGrp;
	}
	curGrp++;
	for (int i = 6; i < 10; i++)
	{
		graph->nodes[i].graph_group = curGrp;
	}




	/*
			int NodeVerif = 0;


	//Queue* q = allocate(sizeof(Queue));
	//queue_init(q);

	// Node assignation et Coût ini à 0
	Node* t = &graph->nodes[NodeVerif];

	int GrpId = 0;
	t->graph_group = GrpId;

	while (t != NULL)
	{
		t->graph_group = GrpId;


		int curGrp = t->graph_group;


	
		for (int j = 0; j < graph->len; j++)
		{
			if (graph->adjGraph[NodeVerif][j] != 0) // Je pars de la bonne place et il y a un chemin
			{
				// Si le graphgroup de la node destination est intouché
				if (graph->nodes[j].graph_group == UINT8_MAX)
				{
					graph->nodes[j].graph_group = curGrp;
				}
				else // Si le graphgroup de son voisin est différent
				{
					graph->nodes[j].graph_group = t->graph_group;
				}
			}
		}


		GrpId++;
		NodeVerif++;
		t = &graph->nodes[NodeVerif];
	}
	*/
}


void Resetgraph(AdjMatrix* graph)
{
	for (int i = 0; i < graph->len; i++)
	{
		graph->nodes[i].path_from = UINT8_MAX;
		graph->nodes[i].visited = 0;
	}
	
}

uint32_t CtoEnd(AdjMatrix* graph, Node* from, Node* to)
{

	uint32_t x = abs(from->h.x - to->h.x) * abs(from->h.x - to->h.x);
	uint32_t y = abs(from->h.y - to->h.y) * abs(from->h.y - to->h.y);

	uint32_t square = x + y;

	uint32_t c = sqrt(square);
	


	return c;
}

/*
* Implementer l'algorithme A*. Lorsqu'il n'y a aucun chemin entre deux node, la Stack doit être vide.
*/
void astar(AdjMatrix* graph, int startNodeIndex, int endNodeIndex, Stack* solvedPath)
{
	while (solvedPath->top != -1) // Vide la stack
	{ 
		stack_pop(solvedPath);
	}
	// Init et allocate Q
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);

	// Node assignation et Coût ini à 0
	Node* t = &graph->nodes[startNodeIndex];
	queue_push(q, t); // push
	graph->nodes[startNodeIndex].cost = 0;


	// Si le node recherche est dans un groupe different du node initial
	if (graph->nodes[endNodeIndex].graph_group != t->graph_group)
	{
		return;
	}
	



	while (t != NULL)
	{
		t = queue_pop(q); // pop
		if (t == NULL)
		{
			break;
		}
		t->visited = 1;

		if (t == &graph->nodes[endNodeIndex]) // 'continue' va skip la prochaine itération de for a la ligne 108
		{
			break;
		}

		for (int e = 0; e < graph->len; e++)
		{
			for (int j = 0; j < graph->len; j++)
			{
				// On regarde si le chemin existe et qu'il est un voisin de la node actuelle
				if (graph->adjGraph[e][j] != 0 && t == &graph->nodes[e]) // Je pars de la bonne place et il y a un chemin
				{
					// Si le voisin n'est pas visité et que le coût n'est pas modifié
					// OU 
					// Coût node arrivée > coût node depart + coût chemin
					if ((graph->nodes[j].visited == 0 && graph->nodes[j].cost == UINT8_MAX) || (graph->nodes[j].cost > graph->nodes[e].cost + graph->adjGraph[e][j]))
					{
						uint32_t coutPlus = CtoEnd(graph, &graph->nodes[j], &graph->nodes[endNodeIndex]);
						// Pousse le prochain voisin non visité dans la queue, update son cost et ajuste son chemin
						queue_push(q, &graph->nodes[j]);
						graph->nodes[j].cost = graph->adjGraph[e][j] + t->cost + coutPlus;
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


