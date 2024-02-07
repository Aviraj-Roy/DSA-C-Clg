#include<stdio.h>
#include<stdlib.h>

void bs(int [], int);

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
	bs(arr,n);
	printf("The sorted array is:- ");
	for(int i=0;i<n;i++)
	{
		printf("%3d",arr[i]);
	}
}
	

void bs(int A[], int n)
{
	int i,j,k;
	int temp,flag=1;
	for(i=0;i<n && flag==1;i++)
	{
		flag = 0;
		printf("Pass: %d\n",i+1);
		for(j=0;j<(n-i-1);j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = 1;
			}
			for(k=0;k<n;k++)
				printf("%5d",A[k]);
			printf("\n");
		}
	}
	
}