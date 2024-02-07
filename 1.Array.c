#include<stdio.h>
#include<stdlib.h>

int arr[100],n;
void make();
void insert(int,int);
void traverse();
void search(int);
void delele(int);
void delpos(int);
void reverse();

int main()
{
	int ch,x,p;
	
	
	traverse();
	while(1)  //1!=0
	{
		
		printf("\n0.Exit\n1.Enter the elements of list\n2.Insert Element\n3.Search an Element\n");
		printf("4.Delete Element\n5.Delete From Position\n6.Reverse the list\n");
		printf("7.Display\n\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
				
			case 1:
				make();
				break;
				
			case 2:
				printf("\nEnter the item: ");
				scanf("%d",&x);
				printf("\nEnter the position: ");
				scanf("%d",&p);
				if(p<=100)
					insert(x,p);
				else
					printf("\nError in position");
				break;
				
			case 3:
				printf("\nEnter the element to be searched");
				scanf("%d",&x);
				search(x);
				break;
				
			case 4:
				printf("\nEnter the element to be deleted");
				scanf("%d",&x);
				delele(x);
				break;
				
			case 5:
				printf("\nEnter the position whose element is to be deleted");
				scanf("%d",&p);				
				if(p<=100)
					delpos(p);
				else
					printf("\nError in position");
				break;
				
			case 6:
				reverse();
				break;
				
			case 7:
				traverse();
				break;
				
			default:
				printf("\nWrong choice.");
		}
	}

	return 0;	
}

//Enter elements in Array
void make()
{
	printf("\nEnter no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter data in the array: ");
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	printf("Elements entered successfully");
}
	
//Insert Elements in the Array
void insert(int x,int p)
{
	int i;
	for(i=n;i>=p;i--)
		arr[i+1] = arr[i];
	arr[p] = x;
	n = n+1;
}

//Search for an Element
void search(int e)
{
	int i,c=0;
	for(i=1;i<=n;i++)
	{
		if(e == arr[i])
		{
			printf("\nElement is found at pos %d",i);
			c=1;
			break;	
			}	
		
	}
	if(c==0)
		printf("Element not found");
}

//Delete 1 element from the array 
void delele(int e)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(e == arr[i])
		{	
			for(;i<=n;i++)
			{
				arr[i]=arr[i+1];
			}
			n--;
			printf("\nElement Removed Successfully\n");
			break;
		}
	}
}

//Delete from position
void delpos(int p)
{
	int i;
	
	arr[p]=arr[p+1];
	for(i=p;i<=n;i++)
	{
		arr[i]=arr[i+1];	
	} n--;
	
	printf("\nElement Removed Successfully\n");
}
	
//Reverse the elements of Array
void reverse()	
{
	int temp;
	for(int i=1;i<=n/2;i++){
		temp = arr[i];
		arr[i]=arr[n-i+1];
		arr[n-i+1] = temp;
	}
	printf("\nReverse Operation Successful");
}

//Display the Array
void traverse()
{
	int i;
	printf("\n%d elements in the array\n",n);
	for(i=1;i<=n;i++)
		printf("%5d",arr[i]);
}