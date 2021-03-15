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
void delete(struct Node* *reference,struct Node* *head_ref);

int main(){
    struct Node* head  = NULL;
    insert_at_beginning(&head,5);
    insert_at_beginning(&head,10);
    insert_at_beginning(&head,15);
    insert_at_beginning(&head,20);
    delete(&head,&head);
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

void delete(struct Node* *reference,struct Node* *head_ref){
    //deleting a value based on given reference
    // Three case may be arrived -> The node is First node , May be last node and may be other nodes

    // If it is first node then to maintain circular strcuture we have to link the last node to the next head_ref.
    // If it is last node then to maintain circular structure we have to link the *head_ref with prev of deleted node.
    // If any other case happens then it will be similar to the linear structure

    if(head_ref != NULL){
        //Checking the list is not empty

        struct Node* temp = *head_ref; // Preserving the head_ref
        struct Node* given_node = *reference;

        if(*head_ref == given_node){
            //First case
            *head_ref = given_node->next;
            printf("head node deleted with data %d \n",given_node->data);
            free(given_node);
            return;

        }else if(given_node->next = *head_ref){
            //Second Case

            //Step 1 :: Traverse the list from head_ref to get last nodes' just prev node
            struct Node* prev; // To preserve the value of prev
            while (temp!= given_node)
            {   
                prev = temp;
                temp = temp->next;
            }
            // Step 2 :: After reaching to prev_node just link it to the head_ref and delete the given_node
            prev->next = *head_ref;
            printf("last node deleted with data %d \n",given_node->data);
            free(given_node);
            return;

        }else{
            //Any other case
            struct Node* node = *reference;
            node = node->next;
            printf("node deleted with data %d \n",node->data);
            free(node);
            return;
        }

    }else{
        printf("The list is empty. \n");
        return;
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
        
    }else{
        printf("The list is empty. \n");
    }

}