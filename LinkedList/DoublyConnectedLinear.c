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

//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';
//Function to control user driven approach
void userDriver(int programRunIteration);

//Al functions
void insert_at_beginning(struct Node* *head_ref, int data);
void insertion_at_end(struct Node* *head_ref,int data);
int checklenghtofList(struct Node* *head_ref); 
void deletebyreference(struct Node* *head_ref,int deleteAfter);
void insert_after_given_number(struct Node* *head_ref,int insertAfter,int data);
void display(struct Node* node);

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

void insert_after_given_number(struct Node* *head_ref,int insertAfter,int data){
    if(*head_ref == NULL){
        printf("The given list is empty\n");
        return;
    }
    //check the lenghth of the list
    int lenghth = checklenghtofList(head_ref);
    if(lenghth>= insertAfter){
        //check if there is sufficient number of nodes available for deletion
        struct Node* temp = *head_ref;
        int index = 1;
        for(index=1;index<insertAfter;index++){
            temp = temp->next;
        }
        //reached to the desired node
        if(temp->next == NULL){
            //it is the last node
            printf("Last node reached so no node available further\n");
            return;
        }

        //perform the actual operation of insertion
        //Step 1 : Create a new_node
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        // Step 2 : insert the data
        new_node->data = data;
        //Step 3 : Assign new_node's next part
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
        new_node->next->prev = new_node;
        
        printf("new node added with data  %d \n",new_node->data);
    }else{
        printf("Insufficient number of nodes available for new node addition\n");
        return;
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
    printf("\n");
    
}

void deletebyreference(struct Node* *head_ref,int deleteAfter){
    //check the list is not empty
    if(*head_ref == NULL){
        printf("The given list is empty\n");
        return;
    }
    //check the lenghth of the list
    int lenghth = checklenghtofList(head_ref);
    if(lenghth>= deleteAfter){
        //check if there is sufficient number of nodes available for deletion
        struct Node* temp = *head_ref;
        int index = 0;
        for(index=0;index<deleteAfter;index++){
            temp = temp->next;
        }
        //reached to the desired node
        if(temp->next == NULL){
            //it is the last node
            printf("Last node reached so no node available further\n");
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        //success message
        printf("node deleted with data %d\n",temp->data);
    }else{
        printf("Insufficient number of nodes available\n");
        return;
    }


}

int checklenghtofList(struct Node* *head_ref){
    struct Node* temp = *head_ref;
    int length = 0;
    while (temp->next!=NULL)
    {
        /* code */
        temp=temp->next;
        length = length+1;
    }
    return length;
    
}

void userDriver(int programRunIteration){
    
   
    int userChoice;
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("program is runnning for %d times\n",programRunIteration);
    printf("------Perform Operations on Doubly Connected Linear Linked List---\n");
    printf("Enter 1 to Add a node into List in the beginning\n");
    printf("Enter 2 to Add a node at the end of list\n");
    printf("Enter 3 to Add a node into List after a given position\n");
    printf("Enter 4 to display all the elements of the List\n");
    printf("Enter 5 to delete an element from the list by it's position\n");
    printf("--------------------------------------------------------\n");
    printf("Enter your desired Choice to Perform Operation on Stack\n");
    printf("Press Ctrl+C to Abort the Program\n");
    scanf("%d",&userChoice);

    int pushValue;
    int numberToadd=0;
    int numberToaddLast=0;
    int numberToAddafterGiven = 0;
    int position = 0;
    int positionAfter = 0;

    switch (userChoice)
    {
    case 1:
        
        printf("Enter a number to add to the list : ");
        scanf("%d",&numberToadd);
        insert_at_beginning(&head,numberToadd);
        display(head);
        break;
    case 2:
        printf("Enter a number to add to the list : ");
        scanf("%d",&numberToaddLast);
        insertion_at_end(&head,numberToaddLast);
        display(head);
        break;
    case 3:
        printf("Enter the position after which you want to add an element : ");
        scanf("%d",&position);
        printf("Enter the number : ");
        scanf("%d",&numberToAddafterGiven);
        insert_after_given_number(&head,positionAfter,numberToAddafterGiven);
        display(head);
        break;
    case 4:
        printf("Displaying the list.......\n");
        display(head);
        break;
    case 5:
        printf("Enter the position from where you want to delete an element : ");
        scanf("%d",&position);
        deletebyreference(&head,position);
        display(head);
        break;
    
    default:
        printf("You have not chosen proper value please retry again.......\n");
        break;
    }

}