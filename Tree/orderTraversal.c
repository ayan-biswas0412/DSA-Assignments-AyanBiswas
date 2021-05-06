#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

};

struct Node* newNode(int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

void preOrder(struct Node* node){
     if (node == NULL){
         return;
     }

    printf("%d ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(struct Node* node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    
    printf("%d ",node->data);
}

void InOrder(struct Node* node){
    if(node == NULL){
        return;
    }
    InOrder(node->left);
    printf("%d ",node->data);
    InOrder(node->right);
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
  
    // Increase distance between levels
    space += COUNT;
  
    // Process right child first
    print2DUtil(root->right, space);
  
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
  
    // Process left child
    print2DUtil(root->left, space);
}
  
// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}


int main(){

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    
    do{
        int choice;
        printf("\nEnter a suitable choice to perform operations on the new tree \n");
        printf("Enter 0 to modify the tree \n");
        printf("Enter 1 to perform PreOrder Traversal of the Tree\n");
        printf("Enter 2 to perform PostOrder Traversal of the Tree\n");
        printf("Enter 3 to perform InOrder Traversal of the Tree\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 0:
            printf("Printing the Tree : \n");
            print2D(root);
            break;
        case 1:
            printf("\n PreOrder Print : ");
            preOrder(root);
            break;
        case 2:
            printf("\n PostOrder Print : ");
            postOrder(root);
            break;
        case 3:
            printf("\n Inorder Print : ");
            InOrder(root);
            break;

        default:
            printf("You Have Entered an Invalid Choice Please Try Again !!");
            break;
        }
        printf("\nPress Ctrl+C to Abort the Program"); 
    }while (1);
    
    return 0;
}