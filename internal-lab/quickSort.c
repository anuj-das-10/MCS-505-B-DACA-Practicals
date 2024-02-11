#include<stdio.h>

//  Auxiliary Function (Helper Function for Swapping Values)
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//  Auxiliary Function (Helper Function for Partitioning process)
int Partition(int *arr, int LB, int UB) {              
    int pivot = arr[UB];   
    int i = LB - 1;
    for(int j = LB; j < UB; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[UB]);
    return i+1;
}

//  Implementation of Quick Sort Algorithm.
void QuickSort(int *arr, int LB, int UB) {
    if(LB < UB) {
        int q = Partition(arr, LB, UB);
        QuickSort(arr, LB, q-1);
        QuickSort(arr, q+1, UB);
    }
}

//  This function is used to display an array passed as argument.
void displayArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }  
    printf("\n");
}

int main() {
    int size, LB = 0;

//  Getting the size of Array from the user as input.
    printf("Enter the size of the array:  ");
    scanf("%d", &size);

//  Initializing array with user given size.
    int arr[size];

//  Taking the number of inputs equivalent to the value of "size". 
    printf("Enter %d Integers: \n", size);
    for(int i = 0; i < size; i++) {
       scanf("%d", &arr[i]);
    }

//  Printing array before sorting
    printf("Before Sorting: ");
    displayArray(arr, size);

//  Performing Quick Sort Algorithm by invoking this function. 
    QuickSort(arr, LB, size);

//  Printing array after sorting  
    printf("After  Sorting: ");
    displayArray(arr, size);
    return 0;
}