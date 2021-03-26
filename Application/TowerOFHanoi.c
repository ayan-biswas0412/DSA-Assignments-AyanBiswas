// Write a program for the Tower of Hanoi problem. Experiment with a varying number of discs. 
// Show the intermediate moves in form of messages like the following:
// Move disk ... from rod ... to rod ...

#include<stdio.h>

//All functions
void towerOfHanoiFunction(int disk, char from_tower, char to_tower, char extra_tower);
void userDriver(int programRunIteration);

//Global variable to re-run the entire flow
char userDefaultChoice = 'Y';
//Function to control user driven approach
void userDriver(int programRunIteration);

int main(){
    int programRunIteration = 1;

    while (userDefaultChoice == 'Y')
    {
        userDriver(programRunIteration);
        programRunIteration++;
        
    }
    return 0;
}

void towerOfHanoiFunction(int disk, char from_tower, char to_tower, char extra_tower){
    if(disk==1){
        //when no of disk in a tower is 1
        printf("Move disk 1 from rod %c to rod %c\n",from_tower,to_tower);
        return;
    }
    towerOfHanoiFunction(disk-1,from_tower,extra_tower,to_tower);
    printf("Move disk %d from rod %c to rod %c\n",disk,from_tower,to_tower);
    towerOfHanoiFunction(disk-1,extra_tower,to_tower,from_tower);

}

void userDriver(int programRunIteration){
    
   
    int userChoice;
    printf("\n");
    printf("--------------------------------------------------------\n");
    printf("program is runnning for %d times\n",programRunIteration);
    printf("------Program for determination of steps for solving Tower of Hanoi Problem---\n");
    printf("Total number of tower is fixed at 3 and they are A,B and C\n");
    printf("Enter the number of tiles you want to shift from tower A to C : ");
    scanf("%d",&userChoice);
    if(userChoice>0)
    {
        printf("The steps are as follows :- \n");
        towerOfHanoiFunction(userChoice, 'A', 'C', 'B');
    }
    else{
        printf("Entered input is not valid for this operation please try again");
    }
    
    
}