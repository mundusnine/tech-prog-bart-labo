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
	TreeNode* nodeOuAjouter = CheckFirstNodeRightOrLeftNull(root);

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

}

int bfs(TreeNode* root, void* key)
{

}

//pseudo code prof
//1 : verifier su ma stack est vide, sinon on pop l'élément du top
//2 : dans un algorithme de recherche on aurait une comparaison, comme exemple, si le character est F on a trouver le noeud puis on retournerais le noeud
//3 : apres la comparaison, on considere ce noeud comme le noeud courant et on push le right puis le left, on push le ledt en dernier puisque l'on veut aller en profondeur avant d'aller lateralement. On recommence

//1 : verifier si ma queue est vide, sinon on pop l'element de fin
//2 : dans un algorithme de recherche on aurait une comparaison, comme exemple, si le character est F on a trouver le noeud puis on retournais le noeud
//3 : apres la comparaison, on considere ce noeud comme le noeud courant et on push le left puis le right, On recommence

TreeNode* CheckFirstNodeRightOrLeftNull(TreeNode* node)
{
	static TreeNode* nodeOuAjouter = NULL;
	static int etape = 0;

	if (node->left == NULL || node->right == NULL)
	{
		nodeOuAjouter = node;
		return;
	}
	


}