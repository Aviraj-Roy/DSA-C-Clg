#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    // # BINARY SEARCH

    int arr[]={1,33,55,156,444,533,623};//*** sorted array for binary search
    int size =sizeof(arr)/sizeof(int);
    int element=55;
    int searchIndex=binarysearch(arr,size,element);
    if (searchIndex == -1)
    {
        printf("Element %d : was not found in the array\n", element);
    }
    else
    {
        printf("The element %d was found at index %d \n", element, (searchIndex+1));
    }

}