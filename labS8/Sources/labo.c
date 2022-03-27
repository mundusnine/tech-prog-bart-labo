#include "labo.h"

long long int tabl[100] = {0};

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
	if (tabl[n] != 0)
	{
		return tabl[n];
	}
	return tabl[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

TreeNode* tree_create_node(void* data)
{
	TreeNode* newNode = allocate(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void tree_add_node(TreeNode* root, TreeNode* node)
{
	//TreeNode* nodeOuAjouter = CheckFirstNodeNull(root, 0, 0, 1);
	TreeNode* nodeOuAjouter = CheckFirstNodeNullOpti(root, 0, 1);

	if (nodeOuAjouter->left == NULL)
	{
		nodeOuAjouter->left = node;
	}
	else if(nodeOuAjouter->right == NULL)
	{
		nodeOuAjouter->right = node;
	}
}

int dfs(TreeNode* root, void* key)
{
	static int stop = 0;
	static int nbNode = 0;

	if (root == NULL)
	{
		return;
	}

	if (root->data == key)
	{
		stop = 1;
	}

	if (stop == 0)
	{
		dfs(root->left, key);
		dfs(root->right, key);
	}

	nbNode++;
	return nbNode;
}

int bfs(TreeNode* root, void* key)
{
	int nbNode = 0;

	TreeNode* nodeAvecDate = FindKey(root, 0, 1, &nbNode, key);

	return nbNode;
}

//pseudo code prof
//1 : verifier su ma stack est vide, sinon on pop l'élément du top
//2 : dans un algorithme de recherche on aurait une comparaison, comme exemple, si le character est F on a trouver le noeud puis on retournerais le noeud
//3 : apres la comparaison, on considere ce noeud comme le noeud courant et on push le right puis le left, on push le ledt en dernier puisque l'on veut aller en profondeur avant d'aller lateralement. On recommence

//1 : verifier si ma queue est vide, sinon on pop l'element de fin
//2 : dans un algorithme de recherche on aurait une comparaison, comme exemple, si le character est F on a trouver le noeud puis on retournais le noeud
//3 : apres la comparaison, on considere ce noeud comme le noeud courant et on push le left puis le right, On recommence

TreeNode* CheckFirstNodeNull(TreeNode* node, int etape, int etage, int first)
{
	TreeNode* CheckNode = NULL;

	if (etape == 0 && etage - 1 < 1)
	{
		CheckNode = CheckFirstNodeNull(node->left, 1, 0, 0);
		if (CheckNode == NULL)
		{
			return node;
		}
		CheckNode = CheckFirstNodeNull(node->right, 1, 0, 0);
		if (CheckNode == NULL)
		{
			return node;
		}
	}
	else if (etape == 1 && etage - 1 < 1)
	{
		return node;
	}
	
	if (first)
	{
		while (1)
		{
			etage++;
			CheckNode = CheckFirstNodeNull(node->left, 0, etage, 0);
			if (CheckNode != NULL)
			{
				return CheckNode;
			}
			CheckNode = CheckFirstNodeNull(node->right, 0, etage, 0);
			if (CheckNode != NULL)
			{
				return CheckNode;
			}
		}
	}
	else if(etage - 1 != 0)
	{
		CheckNode = CheckFirstNodeNull(node->left, 0, etage - 1, 0);
		if (CheckNode != NULL)
		{
			return CheckNode;
		}
		CheckNode = CheckFirstNodeNull(node->right, 0, etage - 1, 0);
		if (CheckNode != NULL)
		{
			return CheckNode;
		}
	}
	return NULL;
}

TreeNode* CheckFirstNodeNullOpti(TreeNode* node, int etage, int first)
{
	TreeNode* checkNode = NULL;

	if (etage - 1 < 1)
	{
		if (node->left == NULL || node->right == NULL)
		{
			return node;
		}
	}

	if (first)
	{
		while (1)
		{
			etage++;
			checkNode = CheckFirstNodeNullOpti(node->left, etage, 0);
			if (checkNode != NULL)
			{
				return checkNode;
			}
			checkNode = CheckFirstNodeNullOpti(node->right, etage, 0);
			if (checkNode != NULL)
			{
				return checkNode;
			}
		}
	}
	else if (etage - 1 != 0)
	{
		checkNode = CheckFirstNodeNullOpti(node->left, etage - 1, 0);
		if (checkNode != NULL)
		{
			return checkNode;
		}
		checkNode = CheckFirstNodeNullOpti(node->right, etage - 1, 0);
		if (checkNode != NULL)
		{
			return checkNode;
		}
	}
	return NULL;
}

TreeNode* FindKey(TreeNode* node, int etage, int first, int* nbNode, void* key)
{
	TreeNode* checkNode = NULL;

	if (etage - 1 < 1)
	{
		*nbNode += 1;
		if (node->data == key)
		{
			return node;
		}
	}

	if (first)
	{
		while (1)
		{
			etage++;
			checkNode = FindKey(node->left, etage, 0, nbNode, key);
			if (checkNode != NULL)
			{
				return checkNode;
			}
			checkNode = FindKey(node->right, etage, 0, nbNode, key);
			if (checkNode != NULL)
			{
				return checkNode;
			}
		}
	}
	else if (etage - 1 != 0)
	{
		checkNode = FindKey(node->left, etage - 1, 0, nbNode, key);
		if (checkNode != NULL)
		{
			return checkNode;
		}
		checkNode = FindKey(node->right, etage - 1, 0, nbNode, key);
		if (checkNode != NULL)
		{
			return checkNode;
		}
	}
	return NULL;
}