// Implement a doubly connected circular linked list in C. Your program should typically
// implement insert and delete at all possible locations with proper check(s) as applicable.
// Include a display function as well and use it to show the content of your list after every
// operation. Include calls to insert and delete from the main.

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;	//Global declaration of node

struct Node* newNode(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = temp;
	temp->prev = temp;
	return temp;
}

void Print()
{
    struct Node* print_node = head;
    printf("\nThe list is: ");
    if(head!=NULL)
    {
        do
        {
            printf("%d ",print_node->data);
            print_node = print_node->next;
        }while(print_node!=head);
    }
}


int count()
{
    struct Node* curr = head;
    int c=0;
    if(head!=NULL)
    {
        do
        {
            c++;
            curr = curr->next;
        }while(curr!=head);
    }
    return c;
}

void InsertHead()
{
    int x;
    printf("Enter the value: ");
    scanf("%d",&x);
    struct Node* new_val = newNode(x);
    if(head == NULL)
    {
        head = new_val;
        new_val->next = head;
        Print();
        return;
    }
    else
    {
        struct Node* prev_node = head;
        while(prev_node->next!=head)
            prev_node = prev_node->next;
        new_val->next = head;
        prev_node->next = new_val;
        head = new_val;
        Print();
    }
}

void Insert()
{
    int x,n;
    printf("Enter the value: ");
    scanf("%d",&x);
    printf("Enter the position: ");
    scanf("%d",&n);
    int c = count();
	if(n<=0 || n>=c+2)
	{
		printf("\nError! Invalid position");
		return;
	}
	struct Node* new_node = newNode(x);
	if(n==1)
    {
        InsertHead(x);
        return;
    }
    struct Node* previ_node = head;
    for(int i=0;i<n-2;i++)
        previ_node = previ_node->next;
    new_node->next = previ_node->next;
    previ_node->next = new_node;
    new_node->prev = previ_node;
    Print();
    return;
}

void InsertTail()
{
    int x;
    printf("Enter the value: ");
    scanf("%d",&x);
    struct Node* new_node = newNode(x);
    if(head == NULL)
    {
        head = new_node;
        Print();
        return;
    }
    struct Node* previ_node = head;
    while(previ_node->next!=head)
        previ_node = previ_node->next;
    new_node->next = previ_node->next;
    previ_node->next = new_node;
    new_node->prev = previ_node;
    new_node->next->prev = new_node;
    Print();
    return;
}

void Delete()
{
    int n;
    printf("Enter the position: ");
    scanf("%d",&n);
    int c = count();
    if(c==0)
    {
        printf("---------UNDERFLOW DETECTED--------\n");
        return;
    }
    if(c==0)
    {
        printf("UNDERFLOW\n");
        return;
    }
	if(n<=0 || n>c)
	{
		printf("\nError! Invalid position");
		return;
	}
	struct Node* del_node = head;
	if(n==1)
    {
        while(del_node->next!=head)
            del_node = del_node->next;
        del_node->next = head->next;
        head->next->prev = del_node;
        free(head);
        if(c==1)
        {
            printf("LIST IS EMPTY!!\n");
            return;
        }
        head = del_node->next;
        Print();
        return;
    }
    for(int j=0;j<n-2;j++)
        del_node = del_node->next;
    struct Node* del_node1 = del_node->next;
    del_node->next = del_node1->next;
    del_node1->next->prev = del_node;
    free(del_node1);
    if(c==1)
    {
        printf("LIST IS EMPTY!!\n");
        return;
    }
    Print();
}

int main()
{
	head = NULL;
	int choose,c=1;
	while(c==1)
    {
        printf("Enter 1 for inserting an element at the beginning\nEnter 2 for inserting at any position\nEnter 3 for inserting at end\nEnter 4 for deleting an element");
        printf("\nEnter your choice: ");
        scanf("%d",&choose);
        if(choose == 1)
            InsertHead();
        else if(choose == 2)
            Insert();
        else if(choose == 3)
            InsertTail();
        else if(choose == 4)
            Delete();
        else
            printf("Enter valid choice\n");
        printf("\nEnter 1 to continue and 0 to exit");
        printf("\nDo you want to continue?: ");
        scanf("%d",&c);
    }
}
