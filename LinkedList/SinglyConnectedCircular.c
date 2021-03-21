// Implement a singly connected circular linked list in C. Your program should typically implement insert and delete at all possible locations with proper check(s) as applicable. 
// Include a display function as well and use it to show the content of your list after every operation. 
// Include calls to insert and delete from the main.

#include<stdio.h>
#include<stdlib.h>

struct Node{ 
    int data;
    struct Node* next;
};

//Al functions
void insert_at_beginning(struct Node* *head_ref,int data);
void display(struct Node* head_ref);
void insert_at_last(struct Node* *head_ref,int data);
void deleteNodeByReference(struct Node* *head_ref,int position);
int count_nodes(struct Node* head_ref);

//Global head declearation 
struct Node* head  = NULL;

//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';
//Function to control user driven approach
void userDriver(int programRunIteration);

//The main function
int main(){

    int programRunIteration = 1;

    while (userDefaultChoice == 'Y')
    {
        userDriver(programRunIteration);
        programRunIteration++;
        
    };
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
        printf("The list is empty !!. \n");
    }

}

void insert_at_last(struct Node* *head_ref,int data){
    //create a node and enter the data
    struct Node* new_node  = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    
    struct Node* temp = *head_ref;
    struct Node* prev_node;

    if(*head_ref == NULL){
        //it is the first node
        //just point the new_node's next part to itself
        new_node->next = new_node;
        *head_ref = new_node;
    }

    do{
        prev_node = temp;
        temp=temp->next;
    }
    while (temp!=*head_ref);
    // prev node is the last node
    prev_node->next  = new_node;
    new_node->next = *head_ref;
}

void deleteNodeByReference(struct Node* *head_ref,int position){

    //if given position is out of range
    if(count_nodes(*head_ref)<position){
        printf("your given position is out of range so it can't be deleted");
        return;
    }
    //base case checking
    if(*head_ref== NULL){
        printf("list is empty , nothing to be deleted\n");
        return;
    }
    struct Node* temp = *head_ref; // preserving the head_ref
    struct Node* last;

    int iter =0;
    for(iter = 0;iter<position-1;iter++){
        if(temp->next == NULL){
            printf("Invalid node ! Deletion is not possible\n");
            return;
        }
        last = temp; // preserving the last node in each iteration
        temp = temp->next;
    }
    //temp -- reached till the desired node
    int dataDeleted = temp->data;
    if(temp->next== *head_ref){
        //means it is the last node
        last->next = (*head_ref)->next;
    }else{  
        last->next = temp->next;
    }
    free(temp);
    printf("The node deleted with data %d from position %d\n",dataDeleted,position);


}

int count_nodes(struct Node* head_ref){
    int count = 0;
    while (head_ref->next!=head_ref)
    {
        count++;
        head_ref = head_ref->next;
    }
    return count+1;
}

void userDriver(int programRunIteration){
    
   
    int userChoice;
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("program is runnning for %d times\n",programRunIteration);
    printf("------Perform Operations on Singly Connected Linear Linked List---\n");
    printf("Enter 1 to Add a node into List in the beginning\n");
    printf("Enter 2 to Add a node at the end of list\n");
    printf("Enter 3 to display all the elements of the List\n");
    printf("Enter 4 to delete an element from the list by it's position\n");
    printf("--------------------------------------------------------\n");
    printf("Enter your desired Choice to Perform Operation on Stack\n");
    printf("Press Ctrl+C to Abort the Program\n");
    scanf("%d",&userChoice);

    int pushValue;
    int numberToadd=0;
    int numberToaddLast=0;
    int position = 0;

    switch (userChoice)
    {
    case 1:
        
        printf("Enter a number to add to the list: ");
        scanf("%d",&numberToadd);
        insert_at_beginning(&head,numberToadd);
        display(head);
        break;
    case 2:
        printf("Enter a number to add to the list: ");
        scanf("%d",&numberToaddLast);
        insert_at_last(&head,numberToaddLast);
        display(head);
        break;
    case 3:
        printf("Displaying the list.......\n");
        display(head);
        break;
    case 4:
        printf("Enter the position from where you want to delete an element: ");
        scanf("%d",&position);
        deleteNodeByReference(&head,position);
        display(head);
        break;
    
    default:
        printf("You have not chosen proper value please retry again.......\n");
        break;
    }

}