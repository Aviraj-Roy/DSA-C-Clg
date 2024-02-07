#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int data;
    struct stack *next;
}stack;

int n;
stack *push(stack*);
stack *pop(stack*);
void display(stack*);

int main()
{
    stack *top = NULL;
    int ch, n;
    while(1)
    {
        printf("\n0.Exit \n1.PUSH An Element \n2.POP An Element \n3. Display Whole Stack");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: exit(0);
            case 1: top = push(top);
                    break;
            case 2: top = pop(top);
                    break;
            case 3: display(top);
                    break;
            default: printf("Wrong Choice");
        }
    }
}

stack *push(stack *top)
{
    stack *ptr;
    int x;
    printf("Enter element:- ");
    scanf("%d",&x);
    printf("Insertion Successful");
    ptr = (stack*)malloc(sizeof(stack));
    ptr->data = x;
    ptr->next = top;
    top = ptr;
    return top; 
}

stack *pop(stack *top)
{
    stack *ptr;
    if(top == NULL)
    {
        printf("Empty Stack");
        return top;
    }
    ptr = top;
    top = top->next;
    printf("Element Popped is %d\n",ptr->data);
    free(ptr);
    return top;
}

void display(stack *top)
{
    stack *temp;
    temp = top;
    while(temp !=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}