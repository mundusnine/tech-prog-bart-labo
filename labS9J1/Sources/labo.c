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
	if (s->top > -1 && curr == NULL) //vider la stack si elle contient du data
	{
		int stackLength = s->top + 1;
		for (int i = 0; i < stackLength; i++)
		{
			stack_pop(s);
		}
	}

	if (curr == NULL)
	{
		int hasFoundKey = 0;
		for (int i = 0; i < len; i++) //boucle sur les nodes principales (sans compter leur edges)
		{
			hasFoundKey = dfs(root, len, root[i], key, s);
			if (hasFoundKey == 1)
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
			if (curr->len == 0)
			{
				stack_pop(s);
				return 0;
			}
			else
			{
				for (int j = 0; j < curr->len; j++)
				{
					if (curr->adj[j]->visited == 0)
					{
						int adjHasFoundKey = dfs(root, len, curr->adj[j], key, s);
						if (adjHasFoundKey == 1)
						{
							return 1;
						}
					}
					if (j == curr->len - 1)
					{
						stack_pop(s);
						return 0;
					}
				}
			}
			
			return 0;
		}
	}
}

int bfs(Node* root[], void* key, Stack* s)
{
	if (s->top > -1) //vider la stack si elle contient du data
	{
		int stackLength = s->top + 1;
		for (int i = 0; i < stackLength; i++)
		{
			stack_pop(s);
		}
	}

	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	
	queue_push(q, root[0]);
	Node* curr = root[0];

	while (curr != NULL)
	{
		curr = queue_pop(q);
		curr->visited = 1;

		if (curr->data == key)
		{
			break;
		}

		for (int i = 0; i < curr->len; i++)
		{
			if (curr->adj[i]->visited != 1)
			{
				queue_push(q, curr->adj[i]);
				curr->adj[i]->revPath->data = curr;
			}
		}
	}
	
	while (curr != NULL)
	{
		stack_push(s, curr);
		curr = curr->revPath->data;
	}
	
	return s->top; 
}