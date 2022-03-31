#include "labo.h"

Node* create_node(void* data)
{
	Node* newNode = allocate(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->data = data;
	memset(newNode->adj, 0, sizeof(newNode->adj));
	newNode->visited = newNode->len = 0;
	newNode->revPath = allocate(sizeof(QNode));
	newNode->revPath->prev = newNode->revPath->next = newNode->revPath->data = NULL;
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
		int valReturned = 0;
		for (int i = 0; i < len; i++)
		{
			valReturned = dfs(root, len, root[i], key, s);
			if (valReturned == 1)
			{
				return s->top;
			}
		}
	}
	else
	{
		stack_push(s, curr);
		curr->visited = 1;

		if (curr->data == key)
		{
			return 1;
		}
		else
		{
			for (int i = 0; i < curr->len; i++)
			{
				if (curr->adj[i]->visited == 0)
				{
					int adjValReturned = dfs(root, len, curr->adj[i], key, s);
					if (adjValReturned == 1)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
			return 0;
		}
	}
}