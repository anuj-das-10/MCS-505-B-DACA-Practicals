#include<stdio.h>

void displayArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int size) {
    int key, j;
    for(int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void main() {
    int arr[] = {12, 34, 23, 56, 10, 40};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Original Array:  ");
    displayArray(arr,size);
    insertionSort(arr, size);
    printf("Sorted Array:   ");
    displayArray(arr, size);
}