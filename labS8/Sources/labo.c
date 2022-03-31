#include "labo.h"
static 	long long tab[100];

long long fibonacci(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (tab[n] != 0)
	{
		return tab[n];
	}


	tab[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return tab[n];
}


/*
* Creer un Noeud, assigner lui la valeur de data, metter c'est reference a NULL et retourner le noeud.
*/
TreeNode* tree_create_node(void* data)
{
	TreeNode* NewNode = allocate(sizeof(TreeNode));
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
}
/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de gauche a droite. Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
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
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/
int dfs(TreeNode* root, void* key)
{
	static int qte = 0;

	// si data null return
	if (root == NULL)
	{
		return;
	}

	// si data = key return
	if (root->data == key)
	{
		goto end;
	}
	

	// cond pour aller gauche then right
	dfs(root->left, key);
	dfs(root->right, key);

	end:
	qte++;
	return qte;
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/
int bfs(TreeNode* root, void* key)
{
	Queue* q = allocate(sizeof(Queue));
	queue_init(q);
	int count = 1;
	queue_push(q, root);

	while (q->next != NULL)
	{
		TreeNode* cur = queue_pop(q);
		if (cur->data == key)
		{
			return count;
		}

		if (cur->left != NULL)
		{
			queue_push(q, cur->left);
			count++;
		}

		if (cur->right != NULL)
		{
			queue_push(q, cur->right);
			count++;
		}
	}


	return 1;
}