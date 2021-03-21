// Implementation of Stack in dynamic memory representation
// I have used linked list to implement this
// two primitive functions push() and pop() has been described here

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


//All functions
void push(struct Node* *head_ref,int data);
void pop(struct Node* *head_ref);
void display(struct Node* node);

//Programs to make the entire flow user driven
void userDriver(int programRunIteration);

//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';
//Global variable to store the data of the head or top (terminology for stack)
struct Node* head = NULL;

int main(){
    int programRunIteration = 1;

    while (userDefaultChoice == 'Y')
    {
        userDriver(programRunIteration);
        programRunIteration++;
        
    }
    return 0;
}

void push(struct Node* *head_ref,int data){
    //create the node and insert the data
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("one element pushed to stack with value %d \n",new_node->data);

}

void pop(struct Node* *head_ref){
    //no parameters needed because it just delete first element of the stack
    if(*head_ref==NULL){
        printf("Stack is empty"); //checking for underflow condition
        return;
    }
    struct Node* temp = *head_ref;
    //temp is the node to be deleted
    int data_to_be_deleted = temp->data;
    *head_ref = temp->next;
    free(temp);
    printf("one element popped to stack with value %d \n",data_to_be_deleted);

}

void display(struct Node* node){
    //prints all the elements of a given node
    printf("\ncurrent complete stack is:- \n"); //adding one single line for just visual aspects only
    while (node!= NULL)
    {
        //till not it reaches to last node it prints node data
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void userDriver(int programRunIteration){
    
    int userChoice;
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("program is runnning for %d times\n",programRunIteration);
    printf("--------------------------------------------------------\n");
    printf("Enter 1 to push any element in Stack\n");
    printf("Enter 2 to pop any element in Stack\n");
    printf("Enter 3 to display all the elements of the Stack\n");
    printf("--------------------------------------------------------\n");
    printf("Enter your desired Choice to Perform Operation on Stack\n");
    printf("Press Ctrl+C to Abort the Program\n");
    scanf("%d",&userChoice);

    int pushValue;

    switch (userChoice)
    {
    case 1:
        printf("Enter the value to be pushed (must be an integer) : ");
        scanf("%d",&pushValue);
        push(&head,pushValue);
        display(head);
        break;
    case 2:
        printf("Popping one element from stack.......\n");
        pop(&head);
        display(head);
        break;
    case 3:
        printf("Displaying the stack.......\n");
        display(head);
        break;
    
    default:
        printf("You have not chosen proper value please retry again.......\n");
        break;
    }

}