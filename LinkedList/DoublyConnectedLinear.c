// Implement a doubly connected linear linked list in C. Your program should typically
// implement insert and delete at all possible locations with proper check(s) as applicable.
// Include a display function as well and use it to show the content of your list after every
// operation. Include calls to insert and delete from the main.

#include<stdio.h>
#include<stdlib.h>

//declaration for a struct which implements a doubly connected node
struct Node{
    //the data part
    int data;
    //two pointers which points to previous and the next node
    struct Node* prev;
    struct Node* next;
};

//declaration of the head pointer as global variable
struct Node* head = NULL;

//Al functions
void insert_at_beginning(struct Node* *head_ref, int data);
void insertion_at_end(struct Node* *head_ref,int data);
void insert_after_given(struct Node* reference_node, int data);
void display(struct Node* node);

//The main function
int main(){
    insert_at_beginning(&head,5);
    insert_at_beginning(&head,10);
    insert_after_given(head->next,26);
    insertion_at_end(&head,20);
    display(head);
    return 0;
}

void insert_at_beginning(struct Node* *head_ref, int data){
    //allocate a node and insert the data
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    //insert the data
    new_node->data = data;
    //change the next part to the newnode
    new_node->next = (*head_ref);
    //assign the prev part to null because it is the first node
    new_node->prev = NULL;

    if ((*head_ref) != NULL){
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
    printf("Node added to the beginning with data : %d\n",data);
}

void insertion_at_end(struct Node* *head_ref,int data){
    //allocate a new_node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    //insert the data
    new_node->data = data;
    new_node->next = NULL;
    //another node to keep the address of head_ref
    struct Node* temp = *head_ref;
    //in case the list is empty
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    //else : traverse the list to the last

    while (temp->next!=NULL)
    {
        //traverse the list until last node is reached
        temp = temp->next;
    }
    //link the next portion of the last node to the newly added node
    temp->next = new_node;
    //change the prev portion of the newly added node to the last node
    new_node->prev =  temp;
    

    printf("node added to the last with data : %d\n",new_node->data);
    
}

void insert_after_given(struct Node* reference_node, int data){

    //check if the list is empty
    if(reference_node == NULL){
        printf("The given reference node can't be null");
        return;
    }else{
        //allocate the node and insert the data
        struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;

        new_node->next = reference_node->next;
        reference_node->next = new_node;
        new_node->prev = reference_node;

        if (new_node->next != NULL)
        new_node->next->prev = new_node;
        printf("node added after the given node with data : %d\n",new_node->data);
    }

}

void display(struct Node* node){
    struct Node* last_node;

    printf("\n");
    printf("Current Linked list is (by traversing in forward direction): ");
    while (node!=NULL)
    {
        printf("%d ",node->data);
        last_node = node;
        node = node->next;
    }
    printf("\n");
    printf("Current Linked list is (by traversing in backward direction): ");
    while (last_node!=NULL)
    {
        printf("%d ",last_node->data);
        last_node = last_node->prev;
    }
    
}