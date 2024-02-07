#include <stdio.h>

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int si, int ei) {
    int pivot = arr[ei];
    int i = si - 1;

    for (int j = si; j < ei; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    i++;
    int temp = arr[ei];
    arr[ei] = arr[i];
    arr[i] = temp;

    return i;
}

void quickSort(int arr[], int si, int ei) {
    if (si < ei) {
        int pidx = partition(arr, si, ei);
        quickSort(arr, si, pidx - 1);
        quickSort(arr, pidx + 1, ei);
    }
}

int main() {
    int arr[] = {6, 3, 9, 8, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArr(arr, size);

    return 0;
}