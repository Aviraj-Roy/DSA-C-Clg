#include<stdio.h>
#include<stdlib.h>

typedef struct cirll{
	int data; 
	struct cirll* next; 
}cirll;

int n;

cirll* create(cirll* head);

cirll* insert1st(cirll* head);
cirll* insertLast(cirll* head);

cirll* delete1st(cirll *head);
cirll* deleteLast(cirll *tail);

void display(cirll*);


int main()
{
	cirll *head = NULL;	
	int ch;
	
	while(1)
	{
		printf("\n0.Exit\n1.Create\n2.Insert 1st\n3.Insert Last\n4.Delete 1st\n5.Delete Last\n6.Traverse\nEnter your choice:- ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0: printf("Exiting Program..");
				exit(0);
				
			case 1: printf("\nEnter the no. of nodes");
				scanf("%d",&n);
				head = create(head);
				break;
				
			case 2: head = insert1st(head);
				break;
			
			case 3: head = insertLast(head);
				break;
			
			case 4: head = delete1st(head);
				break;
			
			case 5: head = deleteLast(head);
				break;
							
			case 6: display(head);
				break;
				
			default: printf("Wrong Choice.");
		}
	}
	return 0;
}

cirll* create(cirll* head)
{
	cirll *ptr,*tail;
	int ele;
	
	if(head != NULL)
	{
		printf("List exists");
		return head;
	}
	
	for(int i=1;i<=n;i++)
	{
		ptr = (cirll*)malloc(sizeof(cirll));
		
		if(ptr == NULL)
		{
			printf("Memory Overflow");
			exit(0);
		}
		
		printf("Enter the element");
		scanf("%d",&ele);
		
		ptr->data = ele;
		
		if(head == NULL)
		{
			head = ptr;
			tail = ptr;
		}
		else
		{
			tail->next = ptr;
			tail = ptr;			
		}
		
		
	}
	tail->next = head;
	return head;
}

void display(cirll* head)
{
	cirll* temp;
	
	if(head == NULL)
	{
		printf("Empty List");
		exit(0);
	}
	
	temp = head;
	
	do
	{
		printf("%5d",temp->data);
		temp = temp->next;
	}while(temp!=head);
}

cirll* insert1st(cirll *head)
{
	cirll *ptr,*temp;
	int x;
	
	printf("Enter the element to be inserted");
	scanf("%d",&x);
	ptr = (cirll*)malloc(sizeof(cirll));
	ptr->data = x;
	
	if(head == NULL)
	{
		head=ptr;
		ptr->next = head;
		
	}
	else
	{
		temp = head;
		while(temp->next != head)
			temp = temp->next;
		ptr->next = head;
		head=ptr;
		temp->next = head;
	}
	printf("Insertion Successful\n");
	return head;
}

cirll* insertLast(cirll *head)
{
	cirll *ptr,*temp;
	int x;
	
	printf("Enter the element to be inserted");
	scanf("%d",&x);
	
	
	ptr = (cirll*)malloc(sizeof(cirll));
	ptr->data = x;
	
	if(head == NULL)
	{
		ptr->next = ptr;
		head = ptr;		
	}
	else
	{
		temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next = ptr;
		ptr->next = head;
	}
	printf("Insertion Successful\n");
	
	return head;
}

cirll* delete1st(cirll *head)
{
	cirll *ptr;
	cirll *temp;
	
	if(head == NULL)
	{
		printf("List is Empty");
		return head;
	}	
	temp = ptr = head;
	while(temp->next != head)
		temp = temp->next;
		
	printf("\nDeletion Successful\nElement %d \n",ptr->data);
	//ptr->next = head;
	head = ptr->next;
	free (ptr);
	temp->next = head;
	return head;
}

cirll* deleteLast(cirll *head)
{
	cirll *ptr, *prev;
	ptr = head;
	
	if(head == NULL)
	{
		printf("List is Empty");
		return head;
	}
	
	while(ptr->next != head)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next=head;	
	printf("\nDeletion Successful\nElement %d\n",ptr->data);
	free (ptr);
	return head;
			
}