#include <stdio.h>
#include<stdlib.h>

int linearsearch(int arr[], int size, int element)
{
    int i = 0;
    for (i = 0; i <= size - 1; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int main()
{
    // # LINEAR SEARCH
    int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 54634, 56, 34};
    int size = sizeof(arr) / sizeof(int);
    int element = 56;
    int searchIndex = linearsearch(arr, size, element);
    if (searchIndex == -1)
    {
        printf("Element %d : was not found in the array\n", element);
    }
    else
    {
        printf("The element %d was found at index %d \n", element, (searchIndex+1));
    }
}