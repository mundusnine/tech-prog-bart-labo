#include "labo.h"

long long fibTab[100] = { 0 };

long long fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

TreeNode* tree_create_node(void* data)
{
	TreeNode* node = allocate(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void tree_add_node(TreeNode* root, TreeNode* node)
{
	if (root->left == NULL)
	{
		root->left = node;
	}
	else if (root->right == NULL && root->left != NULL)
	{
		root->right = node;
	}
}

int dfs(TreeNode* root, void* key)
{
	int visitedNodesCnt = 0;
	Stack s  = stack_init(20);
	stack_push(&s, root);
	
	while (s.top > -1)
	{
		TreeNode* currNode = stack_pop(&s);
		visitedNodesCnt++;
		if (currNode->data == key)
		{
			return visitedNodesCnt;
		}
		if (currNode->right != NULL)
		{
			stack_push(&s, currNode->right);
		}
		if (currNode->left != NULL)
		{
			stack_push(&s, currNode->left);
		}
	}
}

int bfs(TreeNode* root, void* key)
{
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);

	queue_push(q, root);

	while (q->prev != NULL && q->next != NULL)
	{
		TreeNode* currNode = queue_pop(q);

		if (currNode->data == key)
		{
			return q->count;
		}
		if (currNode->left != NULL)
		{
			queue_push(q, currNode->left);
		}
		if (currNode->right != NULL)
		{
			queue_push(q, currNode->right);
		}
	}
}
