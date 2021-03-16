// Implement a singly connected circular linked list in C. Your program should typically implement insert and delete at all possible locations with proper check(s) as applicable. 
// Include a display function as well and use it to show the content of your list after every operation. 
// Include calls to insert and delete from the main.

#include<stdio.h>
#include<stdlib.h>

struct Node{ 
    int data;
    struct Node* next;
};



void insert_at_beginning(struct Node* *head_ref,int data);
void display(struct Node* head_ref);
void deleteNode(struct Node* head, int key);

int main(){
    struct Node* head  = NULL;
    insert_at_beginning(&head,5);
    insert_at_beginning(&head,10);
    insert_at_beginning(&head,15);
    insert_at_beginning(&head,20);
    display(head);
    deleteNode(head,100);
    display(head);
    return 0;

}

void insert_at_beginning(struct Node* *head_ref,int data){
    //the fucntion to insert a data at the first of the circular linekd list
    // *head_ref is the first head reference to the starting node
    
    struct Node* temp = *head_ref; // preserving the address head_ref
    //Step:1 :: Allocate a new node
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    // Step:2 :: Put the data to the new node
    new_node->data  = data;
    //Step:3 :: link this to the head_ref 
    new_node->next = (*head_ref);
   
    //Step:5 :: Traverse the List to chnange last node's next to this new_node
    //Checking the list is not null
    if(*head_ref!=NULL){
        //traverse the list
        while (temp->next!= *head_ref)
        {
            temp= temp->next;

        }
        //After reaching to head_ref =>change the link part of the last node
        temp->next = new_node;

    }else{
        //just point the new_node's next part to itself
        new_node->next = new_node;
    }
   
    // Step:6 :: shift the head_ref to the new_node
    *head_ref = new_node;

    // Step:7 :: Print Success Message
    printf("Node added with value %d and address %p\n",new_node->data,new_node->next);
}

void deleteNode(struct Node* head, int key)
{
    if (head == NULL)
        return;
 
    // Find the required node
    struct Node *curr = head, *prev;
    while (curr->data != key) 
    {
        if (curr->next == head)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }
 
        prev = curr;
        curr = curr->next;
    }
 
    // Check if node is only node
    if (curr->next == head) 
    {
        head = NULL;
        free(curr);
        return;
    }
 
    // If more than one node, check if
    // it is first node
    if (curr == head) 
    {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }
 
    // check if node is last node
    else if (curr->next == head && curr == head) 
    {
        prev->next = head;
        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
}


void display(struct Node* head_ref){

    struct Node* temp = head_ref; // preserving the address head_ref
    if(head_ref!= NULL){
        //If the list is not empty thn traverse the list until head_ref reappears
        // The operation is simply application of a do while loop
        printf("\ncurrent complete node is:- \n"); //adding one single line for just visual aspects only
        do{
            printf(" %d",temp->data);
            temp=temp->next;
        }
        while (temp!=head_ref); // The condition till priting of list work
        printf("\n");
        
    }else{
        printf("The list is empty. \n");
    }

}