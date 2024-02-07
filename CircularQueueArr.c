#include <stdio.h>
#include <stdlib.h>

int qarr[100], n, front, rear, ele;

void c_enqueue(void);
int c_dequeue(void);
void c_traverse(void);

void main()
{
    front = rear = -1;
    int ch;
    printf("Enter the size of the Circular Queue");
    scanf("%d", &n);
    while(1)
    {
        printf("\n0.Exit \n1.Insert \n2.Delete \n3.Display \n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("\nExiting Program\n");
                    exit(0);
            case 1: c_enqueue();
                    break;
            case 2: printf("Deleted Element:- %d",c_dequeue());
                    break;
            case 3: c_traverse();
                    break;
            default: printf("Wrong Choice");    
        }
    }
}

void c_enqueue()
{
    if((front==0 && rear==n-1) || (front==rear+1))
    {
        printf("Overflow Queue");
        exit(0);
    }
    if(front==-1 && rear ==-1)
        front = rear = 0;
    else if(front>0 && rear == n-1)
        rear=0;
    else    
        rear = rear+1;
    printf("Enter element:- ");
    scanf("%d",&ele);
    qarr[rear]=ele;
}

int c_dequeue()
{
    if(front==-1)
    {
        printf("Underflow Queue");
        exit(0);
    }
    ele=qarr[front];
    if(rear == front)
        front = rear = -1;
    else if(front==n-1 && rear >-1)
        front=0;
    else    
        front=front+1;
    return ele;
}

void c_traverse()
{
    if(front==-1)
    {
        printf("Underflow Condition");
        exit(0);
    }
    if(rear>=front)
    {
        for(int i=front; i<=rear;i++)
            printf("%2d",qarr[i]);
    }
    else
    {
        for(int i=0;i<=rear;i++)
            printf("%2d", qarr[i]);
        for(int i=front;i<=n-1;i++)
            printf("%2d", qarr[i]);
    }
    
}