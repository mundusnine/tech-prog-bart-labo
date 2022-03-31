#include"labo.h"

Node* create_node(void* data)
{
	Node* newNode = allocate(sizeof(Node));
	memset(newNode->adj, 0, sizeof(newNode->adj));
	newNode->data = data;
	newNode->visited = 0;
	newNode->len = 0;
	newNode->revPath = allocate(sizeof(QNode));
	newNode->revPath->next = NULL;
	newNode->revPath->prev = NULL;
	newNode->revPath->data = NULL;
	newNode->revPath->count = 0;
	return newNode;
}

void add_adjacent_node(Node* root, Node* node)
{
	root->adj[root->len++] = node;
}

int dfs(Node* root[], int len, Node* curr, void* key, Stack* s)
{
	if (curr == NULL)
	{
		for (int i = 0; i < len; i++)
		{
			int a = dfs(root, len, root[i], key, s);
			if (a == 1)
			{
				break;
			}
		}
		
		return s->top;

	}
	else
	{
		stack_push(s, curr);
		curr->visited = 1;
		if (curr->data == key)
		{
			return 1;
		}
		for (int i = 0; i < curr->len; i++)
		{
			if (curr->adj[i]->visited == 0)
			{
				int a = dfs(root, len, curr->adj[i], key, s);
				if (a == 1)
				{
					return 1;
				}
			}
			if (i == curr->len - 1 && curr->adj[i]->visited == 1)
			{
				stack_pop(s);
			}
		}
		return 0;
	}
}

int bfs(Node* root[], void* key, Stack* s)
{
	while (s->top != -1)
	{
		stack_pop(s);
	}
	int nbChemin = 0;
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	queue_push(q, root[0]);
	Node* n = root[0];
	while (n != NULL)
	{
		n = queue_pop(q);
		n->visited = 1;
		if (n->data == key)
		{
			break;
		}
		for (int i = 0; i < n->len; i++)
		{
			if (n->adj[i]->visited != 1)
			{
				queue_push(q, n->adj[i]);
				n->adj[i]->revPath->data = n;
			}
		}
		
	}
	if (n == NULL)
	{
		return 0;
	}
	else
	{
		while (n != NULL)
		{
			stack_push(s, n);
			n = n->revPath->data;
			nbChemin++;
		}
	}
	return nbChemin;
}

