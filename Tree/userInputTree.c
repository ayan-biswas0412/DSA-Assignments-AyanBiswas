// C program to demonstrate insert
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
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
 
/* A utility function to insert
   a new node with given key in
 * BST */
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

/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// Delete leaf nodes from binary search tree.
struct node* leafDelete(struct node* root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
  
    // Else recursively delete in left and right
    // subtrees.
    root->left = leafDelete(root->left);
    root->right = leafDelete(root->right);
  
    return root;
}

/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
 
// Driver Code
int main()
{
    int numofNodes=0,i=0,num=0;

    struct node* root = NULL;
    printf("Enter the number of nodes you want to add : ");
    scanf("%d",&numofNodes);
    for(i=0;i<numofNodes;i++){
        printf("Enter the node %d : ",i+1);
        scanf("%d",&num);
        if(i==0){
            root = insert(root,num);
        }else{
             insert(root, num);
        }
    }
 
    // print inoder traversal of the BST
    inorder(root);
    leafDelete(root);
    deleteNode(root, 2);
    inorder(root);
 
    return 0;
}