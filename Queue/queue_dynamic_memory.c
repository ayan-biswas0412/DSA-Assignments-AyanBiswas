// Implementation of Queue in dynamic memory approach
#include <stdio.h>
#include <stdlib.h>
  
// A linked list (LL) node to store a queue entry
struct QNode {
    int key;
    struct QNode* next;
};
  
// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue {
    struct QNode *front, *rear;
};
  
//All functions
struct QNode* newNode(int k);
struct Queue* createQueue();
void insert(struct Queue* q, int k);
void delete(struct Queue* q);
void display(struct QNode* node);

//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';
//Function to control user driven approach
void userDriver(int programRunIteration,struct Queue* queue);

// Driver Program to test anove functions
int main()
{
    struct Queue* q = createQueue();
    int programRunIteration = 1;
    while (userDefaultChoice == 'Y')
    {
        userDriver(programRunIteration,q);
        programRunIteration++;
        
    } 
    
    return 0;
}

// A utility function to create a new linked list node.
struct QNode* newNode(int k){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
  
// A utility function to create an empty queue
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
  
// The function to add a key k to q
void insert(struct Queue* q, int k){
    // Create a new LL node
    struct QNode* temp = newNode(k);
  
    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
  
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
    printf("%d inserted to queue\n",k);
}
  
// Function to remove a key from given queue q
void delete(struct Queue* q){
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;
  
    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;
  
    q->front = q->front->next;
  
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
    
    int deletednumber = temp->key; 
    free(temp);
    printf("%d deleted from queue\n",deletednumber);
}

void display(struct QNode* node){
    //prints all the elements of a given node
    if(node==NULL){
        printf("\nThe queue is empty\n"); 
        return;
    }
    printf("\ncurrent complete queue is:- \n"); //adding one single line for just visual aspects only
    while (node!= NULL)
    {
        //till not it reaches to last node it prints node data
        printf("%d ",node->key);
        node = node->next;
    }
    printf("\n");
    
}

void userDriver(int programRunIteration,struct Queue* queue){
    
    int userChoice;
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("program is runnning for %d times\n",programRunIteration);
    printf("------Perform Operations on Queue using Dynamic Memory approach---\n");
    printf("Enter 1 to Insert an Element from the queue\n");
    printf("Enter 2 to Delete an Element from the queue\n");
    printf("Enter 3 to display all the elements of the queue\n");
    printf("--------------------------------------------------------\n");
    printf("Enter your desired Choice to Perform Operation on Queue\n");
    printf("Press Ctrl+C to Abort the Program\n");
    scanf("%d",&userChoice);
    int addtoqueue;

    switch (userChoice)
    {
    case 1:
        printf("Enter a number to add to the queue : ");
        scanf("%d",&addtoqueue);
        insert(queue, addtoqueue);
        display(queue->front);
        break;
    case 2:
        delete(queue);
        display(queue->front);
        break;
    case 3:
        display(queue->front);
        printf("Front item of the queue is : %d \n", queue->front->key);
        printf("Rear item of the queue is : %d", queue->rear->key);
        break;
    default:
        printf("You have not chosen proper value please retry again.......\n");
        break;
    }

}
 