// Implementation of Stack in static memory representation
// I have used linked list to implement this but the size of the linked list is static and it is allocated
//prior to perform any operation
// two primitive functions push() and pop() has been described here

#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push();
void pop();
void display();

void userDriver(int programRunIteration);
//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';

int main()
{   
    //specifying the top of the stack and initializing the size of the stack
    top=-1;
    printf("Enter the size of STACK[MAX=100]: ");
    scanf("%d",&n);
    
    //Repeatative program iteration for user driven approach of the stack functions
    int programRunIteration = 1;
    while (userDefaultChoice == 'Y')
    {
        userDriver(programRunIteration);
        programRunIteration++;
        
    }
    return 0;
}

void push()
{
    if(top>=n-1)
    {
        printf("STACK is over flow\n");
        
    }
    else
    {
        printf("Enter a value to be pushed: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top<=-1)
    {
        printf("Stack is under flow\n");
    }
    else
    {
        printf("The popped elements is %d\n",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("The elements in STACK is : \n");
        for(i=top; i>=0; i--)
            printf("%d ",stack[i]);
    }
    else
    {
        printf("The STACK is empty\n");
    }
   
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
        push();
        display();
        break;
    case 2:
        printf("Popping one element from stack.......\n");
        pop();
        display();
        break;
    case 3:
        printf("Displaying the stack.......\n");
        display();
        break;
    
    default:
        printf("You have not chosen proper value please retry again.......\n");
        break;
    }

}