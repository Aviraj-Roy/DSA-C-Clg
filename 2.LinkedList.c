#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node *createList(int, node*);
void traverse(node*);
node *insertFirst(node*);
node *insertLast(node*);
node *deleteFirst(node*);
node *deleteLast(node*);
node *reverse(node*);
int count(node*);

int main()
{
    node* head = NULL;
    int ch, n;
    while(1)
    {
        printf("\n0.Exit \n1.Create List \n2.Traverse List \n3.Insert First \n4.Insert Last \n5.Delete First \n6.Delete Last \n7.Reverse \n8.Count \nEnter Your Choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: exit(0);
            case 1: printf("Enter no. of nodes");
                    scanf("%d",&n);
                    head = createList(n,head);
                    break;
            case 2: traverse(head);
                    break;
            case 3: head = insertFirst(head);
                    break;
            case 4: head = insertLast(head);
                    break;
            case 5: head = deleteFirst(head);
                    break;
            case 6: deleteLast(head);
                    break;
            case 7: head = reverse(head);
                    break;
            case 8: printf("No. of nodes = %d\n", count(head));
                    break;
            default: printf("Wrong Choice");
        }
    }
}   
    node *createList(int n, node *head)
    {
        node *ptr, *temp=NULL;
        int x, i;
        if(head != NULL)
        {
            printf("\nList Exists");
            return head;
        }
        for(i=1;i<=n;i++)
        {
            ptr = (node*)malloc(sizeof(node));
            if(ptr==NULL)
            {
                printf("Memory Overflow");
                exit(0);
            }
            printf("\nEnter Data");
            scanf("%d", &x);
            ptr->data = x;
            ptr->next = NULL;
            if(head == NULL)
                head = ptr;
            else    
                temp->next = ptr;
            temp = ptr;
        }
        return head;
    }
    void traverse (node *head)
    {
        node *temp;
        if(head == NULL)
        {
                printf("Empty List");
                return;
        }temp = head;
        while(temp !=NULL)
        {
            printf("Data is -> %d\n",temp->data);
            temp = temp->next;
        }
    }

    node *insertFirst(node *head)
    {
        node *ptr;
        int x;
        if(head == NULL)
        {
            printf("Empty List");
            return head;
        }
        printf("Enter the elemnt to be inserted");
        scanf("%d", &x);
        printf("Insertion Successful\n");
        ptr=(node*)malloc(sizeof(node));
        ptr->data = x;
        ptr->next = head;
        head = ptr;
        return head;
    }

    node *insertLast(node *head)
    {
        node *newnode, *temp = NULL;
        int item;
        if(head == NULL)
        {
            printf("\nEmpty List");
            return head;
        }
        newnode=(node*)malloc(sizeof(node));
        printf("\nEnter item");
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        return head;
    }

    node *deleteFirst(node *head)
    {
        node *ptr;
        int temp;
        ptr=head;
        if(head == NULL)
        {
            printf("Empty List");
            return head;
        }
        temp = ptr->data;
        printf("\nDeletion Successful");
        head = ptr->next;
        free(ptr);
        return head;
    }

    node *deleteLast(node *head)
    {
        node *ptr, *prev;
        ptr = head;
        if(head == NULL)
        {
            printf("Empty List");
            return head;
        }
        while(ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        printf("\nDeletion Successful");
        prev->next=NULL;
        free(ptr);
    }

    node *reverse(node *head)
    {
        if(head == NULL)
        {
            printf("Empty List");
            return head;
        }
        else{
            node *ptr = NULL;
            node *temp = head;
            node *x = head;
            while(temp!=NULL)
            {
                temp=temp->next;
                x->next=ptr;
                ptr=x;
                x=temp;
            }
            head = ptr;
            traverse(head);
        }return head;
    }

    int count(node *head)
    {
        int c=0;
        if(head == NULL)
        {
            printf("Empty List");
            return 0;
        }
        else{
            node *temp = head;
            int count = 0;
            while(temp!=NULL)
            {
                temp = temp->next;
                c++;
            }
        }return c;
    }