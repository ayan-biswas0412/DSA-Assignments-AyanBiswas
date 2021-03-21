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

struct Node* main_node  = NULL;

//Al functions
void insert(char location[6],int data,struct Node* *head_ref);
void insertion_at_beginning(struct Node* *head_ref,int data);
void insertion_at_end(struct Node* *head_ref,int data);
void display(struct Node* node);
void deletebyvalue(struct Node* *head_ref,int data);
void deletebyreference(struct Node* *head_ref,int position);
int count_nodes(struct Node* head_ref);

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
        
    }
    return 0;

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
    printf("new node added to the last with value %d\n",data);


}

void display(struct Node* node){
    //prints all the elements of a given node
    printf("\ncurrent complete node is:- \n"); //adding one single line for just visual aspects only
    while (node!= NULL)
    {
        //till not it reaches to last node it prints node data
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
    
}

//Extra function
void deletebyvalue(struct Node* *head_ref,int data){
    //delete a node
    struct Node* temp = *head_ref;
    struct Node* prev_node;
    
    //checking that the given value is first node or not
    if (temp != NULL && temp->data == data) {
        *head_ref = temp->next; 
        printf("node deleted with data %d \n",temp->data);
        free(temp); 
        return;
    }
    //traversing the list for finding the node
    while (temp != NULL && temp->data != data) {
        prev_node = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL){
        printf("the node for deletion is not found in the list\n");
      return;
    } 

    prev_node->next = temp->next;
    printf("node deleted with data %d ",temp->data);
    free(temp); // Freeing the node
}

void deletebyreference(struct Node* *head_ref,int position){
    //checking the base condition
    if(*head_ref == NULL){
        printf("node is empty already so nothing to be deleted\n");
        return;
    }
    
    if(count_nodes(*head_ref)<position){
        printf("your given position is out of range so it can't be deleted");
        return;
    }

    struct Node* temp = *head_ref;
    struct Node* last;
    int temp_pos = 0;
    for(temp_pos=0;temp_pos<position-1;temp_pos++){
        if(temp->next == NULL){
            printf("Invalid node ! Deletion is not possible\n");
            return;
        }
        last = temp; // preserving the last node in each iteration
        temp = temp->next;
    }
    //reached till desired node
    int dataDeleted = temp->data;
    last->next = temp->next;
    free(temp);
    printf("The node deleted with data %d from position %d\n",dataDeleted,position);

}

int count_nodes(struct Node* head_ref){
    int count = 0;
    while (head_ref->next!=NULL)
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
        
        printf("Enter a number to add to the list");
        scanf("%d",&numberToadd);
        insert("start",numberToadd,&main_node);
        display(main_node);
        break;
    case 2:
        printf("Enter a number to add to the list");
        scanf("%d",&numberToaddLast);
        insert("end",numberToaddLast,&main_node);
        display(main_node);
        break;
    case 3:
        printf("Displaying the list.......\n");
        display(main_node);
        break;
    case 4:
        printf("Enter the position from where you want to delete an element.\n");
        scanf("%d",&position);
        deletebyreference(&main_node,position);
        display(main_node);
        break;
    
    default:
        printf("You have not chosen proper value please retry again.......\n");
        break;
    }

}