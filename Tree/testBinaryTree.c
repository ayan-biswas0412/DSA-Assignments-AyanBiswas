// C program to check whether a given Binary Tree is full or not
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Tree node structure */
struct Node
{
	int key;
	struct Node *left, *right;
};

/* Helper function that allocates a new node with the
given key and NULL left and right pointer. */
struct Node *newNode(char k)
{
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

/* This function tests if a binary tree is a full binary tree. */
bool isFullTree (struct Node* root)
{
	// If empty tree
	if (root == NULL)
		return true;

	// If leaf node
	if (root->left == NULL && root->right == NULL)
		return true;

	// If both left and right are not NULL, and left & right subtrees
	// are full
	if ((root->left) && (root->right))
		return (isFullTree(root->left) && isFullTree(root->right));

	// We reach here when none of the above if conditions work
	return false;
}

/* This function counts the number of nodes in a binary tree */
unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}

/* This function checks if the binary tree is complete or not */
bool isComplete (struct Node* root, unsigned int index,
                 unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (true);
  
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);
  
    // Recur for left and right subtrees
    return (isComplete(root->left, 2*index + 1, number_nodes) &&
            isComplete(root->right, 2*index + 2, number_nodes));
}

// Driver Program
int main()
{
	struct Node* root = NULL;
	root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);

	root->left->right = newNode(40);
	root->left->left = newNode(50);
	root->right->left = newNode(60);
	root->right->right = newNode(70);

	root->left->left->left = newNode(80);
	root->left->left->right = newNode(90);
	root->left->right->left = newNode(80);
	root->left->right->right = newNode(90);
	root->right->left->left = newNode(80);
	root->right->left->right = newNode(90);
	root->right->right->left = newNode(80);
	root->right->right->right = newNode(90);

    unsigned int node_count = countNodes(root);
    unsigned int index = 0;

	if (isFullTree(root))
		printf("The Binary Tree is Strictly Binary\n");
	else
		printf("The Binary Tree is not Strictly Binary\n");
    
    if (isComplete(root, index, node_count))
		printf("The Binary Tree is Complete\n");
	else
		printf("The Binary Tree is not Complete\n");

	return(0);
}

