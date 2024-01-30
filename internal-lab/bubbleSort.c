#include<stdio.h>

void displayArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void boobieSort(int *arr, int size) {
    int temp;
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main() {
    int arr[] = {12, 34, 23, 56, 10, 40};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Original Array:  ");
    displayArray(arr,size);
    boobieSort(arr, size);
    printf("Sorted Array:   ");
    displayArray(arr, size);
}