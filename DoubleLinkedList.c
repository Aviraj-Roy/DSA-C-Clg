Double Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node*pre;
	struct node*next;
}node;
	
node* create(node*);
void traverse(node*);

node* insert(node*, int);
node* delete(node*, int);

void main()
{
	int ch,ele,l;
	
	node*head = NULL;
	
	while(1)
	{

		printf("\n0.Exit\n1.Create\n2.Traverse\n3.Insert\n4.Delete");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0: printf("Exiting Program...");
				exit(0);
			case 1: head = create(head);
				break;
			case 2: traverse(head);
				break;
			case 3: printf("Enter the location -> ");
				scanf("%d",&l);
				head = insert(head,l);
				break;
			case 4: printf("Enter the element you want to delete -> ");
				scanf("%d",&ele);
				head = delete(head,ele);
				break;
			default: printf("Wrong Choice");
		}
	}
}

node* create(node* head)
{
	int n,d,i;
	node *ptr,*tail=NULL;
	
	printf("Enter the no. of nodes you want to create ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		printf("Enter the data :- ");
		scanf("%d",&d);
		ptr->data = d;
		ptr->next = NULL;
		ptr->pre = NULL;
		
		if(head == NULL)
		{
			head = ptr;
		}
		else
		{
			tail->next = ptr;
			ptr->pre = tail;
		}
		tail = ptr;
	}
	
	return head;
}

void traverse(node* head)
{
	node *temp,*p;
	if(head == NULL)
		printf("\nEmpty\n");
	else
	{
		temp = head;
		printf("Forward Traverse: ");
		while(temp!=NULL)
		{
			printf("%3d",temp->data);
			p = temp;
			temp = temp->next;
		}
		printf("\nBackward Traverse: ");		
		while(p!=NULL)
		{
			printf("%3d",p->data);
			p = p->pre;
		}
	}
}

node* insert(node*head, int l)
{
	int d,i=1;
	node *ptr,*temp;
	ptr = (node*)malloc(sizeof(node*));
	printf("Enter the data");
	scanf("%d",&d);
	ptr->data = d;
	
	if(l == 1)
	{
		ptr->next = head;
		ptr->pre = NULL;
		head->pre = ptr;
		head = ptr;
	}
	
	else
	{
		temp = head;
		while(i<l-1)
		{
			temp = temp->next;
			i++;
		}
		
		if(temp->next!=NULL)
		{
			temp->next->pre = ptr;
			ptr->next = temp->next;
			ptr->pre = temp;
			temp->next = ptr;
		}
	}
	printf("\nInsertion Successful\n");
	return head;
}

node* delete(node* head, int ele)
{
	node *temp,*prev;
	temp = head;
	while(temp->data!=ele)
	{
		prev=temp;
		temp=temp->next;
	}
	
	if(temp == head && temp->next==NULL)
		head=head->next;
	else if(temp==head)
	{
		head = head->next;
		head->pre = NULL;
	}
	else if(temp->next == NULL)
		prev->next = temp->next;
	else
	{
		temp->next->pre = prev;
		prev->next = temp->next;
	}
	
	free(temp);
	return head;
}