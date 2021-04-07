// Implementation of Queue in static memory approach
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
//All functions
struct Queue* createQueue(unsigned capacity);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void insert(struct Queue* queue, int item);
int delete(struct Queue* queue);
int front(struct Queue* queue);
int rear(struct Queue* queue);
void display(struct Queue* queue);

//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';
//Function to control user driven approach
void userDriver(int programRunIteration,struct Queue* queue);


// Driver program to test above functions./
int main()
{   
    int queue_size;
    printf("Enter the length of the queue you want to create : ");
    scanf("%d",&queue_size);
    struct Queue* queue = createQueue(queue_size);
    printf("Queue created of size %d successfully now choose from the below optioins to perform operation on this queue :\n",queue_size);
    int programRunIteration = 1;
    while (userDefaultChoice == 'Y')
    {
        userDriver(programRunIteration,queue);
        programRunIteration++;
        
    } 
    return 0;
}

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void insert(struct Queue* queue, int item){
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d inserted to queue\n", item);
}
 
// Function to remove an item from queue.
// It changes front and size
int delete(struct Queue* queue){
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    printf("%d deleted from queue \n",item);
    return item;
}
 
// Function to get front of queue
int front(struct Queue* queue){
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue){
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

void display(struct Queue* queue){
    if (isEmpty(queue)){
        printf("The queue is empty please insert some values");
        return;

    }
    int last = queue->rear;
    int first = queue->front;
    int iter;
    printf("\n");
    printf("The entire queue is : \n");
    for(iter=first;iter<=last;iter++){
        printf("%d ",queue->array[iter]);
    }
    printf("\n");
    printf("Front item of the queue is %d\n", front(queue));
    printf("Rear item of the queue is %d\n", rear(queue));
}

void userDriver(int programRunIteration,struct Queue* queue){
    
    int userChoice;
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("program is runnning for %d times\n",programRunIteration);
    printf("------Perform Operations on Queue using Static Memory approach---\n");
    printf("Enter 1 to Insert an Element from the queue\n");
    printf("Enter 2 to Delete an Element from the queue\n");
    printf("Enter 3 to display all the elements of the Queue\n");
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
        display(queue);
        break;
    case 2:
        delete(queue);
        display(queue);
        break;
    case 3:
        display(queue);
        break;
    default:
        printf("You have not chosen proper value please retry again.......\n");
        break;
    }

}
 