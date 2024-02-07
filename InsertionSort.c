Insertion Sort
#include<stdio.h>
#include<stdlib.h>

void is(int [], int);

int main()
{
	int n;
	system("clear");
	printf("Enter the total no. of elements");
	scanf("%d",&n);
	int arr[n];
	
	printf("Enter the elements in the array:- ");
	for(int i=0;i<n;i++)
	{
		printf("Element %d - ",i);
		scanf("%d",&arr[i]);
	}
	is(arr,n);
	printf("The sorted array is:- ");
	for(int i=0;i<n;i++)
	{
		printf("%5d",arr[i]);
	}
}

/*void is(int A[], int n)
{
	int i,j,k;
	int temp,flag=1;
	for(i=0;i<n && flag==1;i++)
	{
		flag = 0;
		printf("Pass: %d\n",i+1);
		temp = A[i];
		j=(i-1);
		while(A[j]>temp && j>0)
		{
			A[j+1] = A[j];
			j=j-1;
			flag = 1;
		}
		A[j+1] = temp;
		for(k=0;k<n;k++)
			printf("%5d",A[k]);
		printf("\n");
	}
}*/

void is(int A[], int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp = A[i];
		j = i-1;
		while(A[j]>temp && j>=0)
		{
			A[j+1] = A[j];
			j = j-1;
		}
		A[j+1] = temp;
	}
}