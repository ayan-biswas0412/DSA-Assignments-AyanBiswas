#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left ;
    struct node *right ;
};
 
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// Driver Code
int main()
{
    int arr[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int rootNode = 13;

    struct node* root = NULL;
    root = insert(root, rootNode);

    int i=0;
    int size = sizeof(arr)/sizeof(arr[0]);

    for(i=0;i<size;i++){
        if(arr[i]!=rootNode){
            insert(root, arr[i]);
        }
    }
 
    // print inoder traversal of the BST
    inorder(root);
 
    return 0;
}