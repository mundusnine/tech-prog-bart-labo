#include "labo.h"


static long long tab[100] = { 0 };

long long fibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (tab[n] != 0)
	{
		return tab[n];
	}
	return tab[n] = (fibonacci(n - 1) + fibonacci(n - 2));
}

TreeNode* tree_create_node(void* data)
{
	TreeNode* noeud = allocate(sizeof(TreeNode));
	noeud->data = data;
	noeud->left = NULL;
	noeud->right = NULL;
	return noeud;

}

void tree_add_node(TreeNode* root, TreeNode* node)
{
	if (root != NULL)
	{
		if (root->left == NULL)
		{
			node = root->left;
			return node;
		}
		if (root->right == NULL)
		{
			node = root->right;
			return node;
		}
	}
}

int dfs(TreeNode* root, void* key)
{
	Stack s = stack_init(100);
	stack_push(&s, root);
	int count = 0;
	while (&s != NULL)
	{
		TreeNode* n = stack_pop(&s);
		if (n->data == key)
		{
			return count;
		}
		stack_push(&s, n->right);
		stack_push(&s, n->left);
		count++;
	}
}

int bfs(TreeNode* root, void* key)
{
	Queue* q;
	queue_init(q);
	queue_push(q, root);
	int count = 0;
	while (q->prev != NULL)
	{
		TreeNode* n = queue_pop(q);
		if (n->data == key)
		{
			return count;
		}
		queue_push(q, n->left);
		queue_push(q, n->right);
		count++;
	}
}