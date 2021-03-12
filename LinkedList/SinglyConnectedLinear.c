// Implementation of a singly connected linear linked list in C. 
// This program contains implementation of insert and delete at all possible locations with proper check(s) as applicable. 
// There is a display function which shows the content of list after every operation. 
// Included calls to insert and delete from the main. 

#include<stdio.h>
#include<stdlib.h>

//creation of the struct node
struct Node{
    int data;
    struct Node* next;
};

void insert(char location[6],int data,struct Node* *head_ref);
void insertion_at_beginning(struct Node* *head_ref,int data);
void insertion_at_end(struct Node* *head_ref,int data);
void print_linkedlist(struct Node* node);


int main(){
    //the main driver code to test the programs;
    struct Node* new_node  = NULL;
    insert("start",5,&new_node);
    insert("end",15,&new_node);
    print_linkedlist(new_node);

}

void insert(char location[6],int data,struct Node* *head_ref){
    // The main function for the user to insert a node at the beginning or end based on given choices
    int option = 0;
    //set the options corresponding to the given char input
    if(location == "start"){
        option = 1;
    }else if(location = "end"){
        option = 2;
    }

    switch (option)
    {
    case 1:
        //insertion at the beginning
        insertion_at_beginning(head_ref,data);
        break;
    case 2:
        insertion_at_end(head_ref,data);
        break;
    
    default:
        printf("no argument was passed so nothing in the list was added\n");
    }

}

void insertion_at_beginning(struct Node* *head_ref,int data){
    //inserts a node at the beginning of a list
    //allocation of a new node
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    //assign the data
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
    printf("new node added at beginning with integer data %d\n",data);

}

void insertion_at_end(struct Node* *head_ref,int data){
    //inserts an node at the end of list
    //allocation of a new node
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    //assign the data
    new_node->data = data;
    //set the next part of the new_node null as it is the last node
    new_node->next = NULL;
    struct Node* temp = *head_ref;
        //check the linked list is null or not
        if(*head_ref!= NULL){
            //the list is not empty so we have to traverse the list and insert the node
            while(temp->next!= NULL){
                temp = temp->next;
            }
            //reach till the last node and point that to new_node
            temp->next = new_node;
        }else{
            //the list is empty and the new_node should be the first node
            *head_ref = new_node;
        }


}

void print_linkedlist(struct Node* node){
    //prints all the elements of a given node
    while (node!= NULL)
    {
        //till not it reaches to last node it prints node data
        printf("%d ",node->data);
        node = node->next;
    }
    
}