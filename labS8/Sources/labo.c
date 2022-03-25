#include "labo.h"


long long tableauFibo[100] = { NULL };

long long fibonacci(int n) 
{
	if (n == 1) { return 1; }
	if (n == 0) { return 0; }

	if (tableauFibo[n] != 0)
	{
		return tableauFibo[n];
	}

	tableauFibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return tableauFibo[n];
}

TreeNode* tree_create_node(void* data)
{
	TreeNode* theRoot = allocate(sizeof(TreeNode));
	theRoot->data = data;
	theRoot->right = NULL;
	theRoot->left = NULL;

	return theRoot;
}

void tree_add_node(TreeNode* root, TreeNode* node)
{
	if (root->left == NULL)
	{
		root->left = node;
	}
	else if (root->right == NULL)
	{
		root->right = node;
	}
}
/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme,
vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key)
{
	Stack theStack = stack_init(6);
	stack_push(&theStack, root);

	int nombreElementVisiter = 0;

	while (theStack.top != -1)
	{
		nombreElementVisiter++;
		TreeNode* nodeToCompare = stack_pop(&theStack);
		if (nodeToCompare->data== key)
		{
			return nombreElementVisiter;
		}
		if (nodeToCompare->right != NULL)
		{
			stack_push(&theStack, nodeToCompare->right);
		}
		if (nodeToCompare->left != NULL)
		{
			stack_push(&theStack, nodeToCompare->left);
		}
	}
}

int bfs(TreeNode* root, void* key)
{
	Queue* theQueue = allocate(sizeof(Queue));
	queue_init(theQueue);
	queue_push(theQueue, root);

	int nombreElementVisiter = 0;

	while (theQueue->data != NULL)
	{
		nombreElementVisiter++;
		TreeNode* nodeToCompare = queue_pop(theQueue);
		if (nodeToCompare->data == key)
		{
			return nombreElementVisiter;
		}	
		if (nodeToCompare->left != NULL)
		{
			queue_push(theQueue, nodeToCompare->left);
		}
		if (nodeToCompare->right != NULL)
		{
			queue_push(theQueue, nodeToCompare->right);
		}
	}
}