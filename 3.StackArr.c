#include<stdio.h>
#include<stdlib.h>
int starr[100], n, top, ele;

void push(void);
int pop(void);
int peek(void);
void display(void);
void main()
{
    int ch;
    top=-1;
    printf("Enter size of stack");
    scanf("%d",&n);
    while(1)
    {
        printf("\n0.Exit \n1.PUSH an element \n2.POP an element \n3.Display First Element \n4. Display Whole Stack");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: printf("Exiting Program");
                    exit(0);
            case 1: push();
                    break;
            case 2: printf("Element popped out is = %d",pop());
                    break;
            case 3: printf("The TOP element is = %d",peek());
                    break;
            case 4: display();
                    break;
            default: printf("Wrong Choice");

        }
    }
}

void push()
{
    if(top==n-1)
    {
        printf("Stack is FULL");
        exit(0);
    }
    printf("Enter element:- ");
    scanf("%d",&ele);
    top=top+1;
    starr[top] = ele;
    printf("Insertion Successful");
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty");
        exit(0);
    }
    ele = starr[top];
    top=top-1;
    return ele;
}

int peek()
{
    if(top==-1)
    {
        printf("Empty Stack");
        exit(0);
    }
    return starr[top];
}

void display()
{
    if(top==-1)
    {
        printf("Empty Stack");
        exit(0);
    }
    printf("The elements are:- ");
    for(int i=0;i<=top;i++)
    {
        printf("%2d", starr[i]);
    }
}