Selecton Sort
#include<stdio.h>
#include<stdlib.h>

void ss(int [], int);

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
	ss(arr,n);
	printf("The sorted array is:- ");
	for(int i=0;i<n;i++)
	{
		printf("%3d",arr[i]);
	}
}

/*void ss(int A[], int n)
{
	int i,j,k;
	int temp;
	for(i=0;i<n-1;i++)
	{

		printf("Pass: %d\n",i+1);
		for(j=i;j<n;j++)
		{
			if(A[i] > A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				
			}
			for(k=0;k<n;k++)
				printf("%5d",A[k]);
			printf("\n");
		}
	}
	
}*/

void ss(int A[], int n)
{
	int i,j,k;
	int temp,min;
	for(i=0;i<n-1;i++)
	{
	
		min = i;
		
		for(j=i;j<n;j++)
		{
			if(A[j] < A[min])
				min = j;
		}
		if(i != min)
		{
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
		/*printf("Pass: %d\n",i+1);
		for(k=0;k<n;k++)
			printf("%5d",A[k]);
		printf("\n");*/
	}
}