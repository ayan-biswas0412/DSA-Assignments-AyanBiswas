// Evaluate postfix expressions using a Stack. You can use &#39;,&#39; as a delimiter between two
// tokens in an expression. You can use &#39;$&#39; as the end of input. Always show the
// intermediate steps including the content of the stack. Take some example postfix
// expressions. Here is one example:
// 6, 2, 3, +, -, 3, 8, 2, /, +, *, 2, ^, 3, +, $
// (Use &#39;^&#39; for exponentiation)

// C program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
  
// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
  
//All functions
struct Stack* createStack( unsigned capacity );
int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char op);
int evaluatePostfix(char* exp);
char filterString(char exp[],char filterparam);

//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';
//Function to control user driven approach
void userDriver(int programRunIteration);


// Driver program to test above functions
int main()
{
   int programRunIteration = 1;

    while (userDefaultChoice == 'Y')
    {
        userDriver(programRunIteration);
        programRunIteration++;
        
    }
    return 0;
}

// Stack Operations
struct Stack* createStack( unsigned capacity ){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  
    if (!stack) return NULL;
  
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
  
    if (!stack->array) return NULL;
  
    return stack;
}
  
int isEmpty(struct Stack* stack){
    return stack->top == -1 ;
}
  
char peek(struct Stack* stack){
    return stack->array[stack->top];
}
  
char pop(struct Stack* stack){
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
  
void push(struct Stack* stack, char op){
    stack->array[++stack->top] = op;
}
  
  
// The main function that returns value of a given postfix expression
int evaluatePostfix(char* exp){
    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    int i;
  
    // See if stack was created successfully
    if (!stack) return -1;
  
    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (isdigit(exp[i])){
            push(stack, exp[i] - '0');
            printf("[TASK] One integer pushed to stack : %d\n",exp[i] - '0');
        }
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+': 
                push(stack, val2 + val1);
                printf("[TASK] + operator encountered and Two values popped from stack : %d and %d \n",val1,val2);
                printf("[ Sub TASK] Addition performed and result %d pushed to stack\n",val2 + val1);  
                break;
            case '-': 
                push(stack, val2 - val1); 
                printf("[TASK] - operator encountered and Two values popped from stack : %d and %d \n",val1,val2);
                printf("[ Sub TASK] Substraction performed and result %d pushed to stack\n",val2 - val1); 
                break;
            case '*': 
                push(stack, val2 * val1); 
                printf("[TASK] * operator encountered and Two values popped from stack : %d and %d \n",val1,val2);
                printf("[ Sub TASK] Multipication performed and result %d pushed to stack\n",val2 * val1); 
                break;
            case '/': 
                push(stack, val2/val1); 
                printf("[TASK] / operator encountered and Two values popped from stack : %d and %d \n",val1,val2);
                printf("[ Sub TASK] Division performed and result %d pushed to stack\n",val2/val1); 
                break;
            case '^': 
                push(stack, pow(val2,val1));
                printf("[TASK] ^ operator encountered and Two values popped from stack : %d and %d \n",val1,val2);
                printf("[ Sub TASK] Exponentiation performed and result %d pushed to stack\n",pow(val2,val1));  
                break;
            }
        }
    }
    return pop(stack);
}

//program to filter out the entire string and eliminate ',' and '$' to get and clearer expression
char filterString(char exp[],char filterparam){
    int len = strlen(exp);
    int i,j;
	   	
  	for(i = 0; i < len; i++)
	{
		if(exp[i] == filterparam)
		{
			for(j = i; j < len; j++)
			{
				exp[j] = exp[j + 1];
			}
			len--;
			i--;	
		} 
	}	
}

void userDriver(int programRunIteration){
    
   
    char exp[100];
    
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("program is runnning for %d times\n",programRunIteration);
    printf("------Program for determination of the evaluated value of a postfix expression---\n");
    printf("Enter the string and every character should be in ',' separated form and last character should be '$' : ");
    gets(exp);
    int len =  strlen(exp);

    if(len>0)
    {
        filterString(exp,',');
        filterString(exp,'$');
        printf ("Final Result postfix evaluation: %d\n", evaluatePostfix(exp));
    }
    else{
        printf("Entered string is empty please provide a valid string");
    }
    printf("\nPress Ctrl+C to Abort the Program\n");
    
    
}