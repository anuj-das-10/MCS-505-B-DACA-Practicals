#include<stdio.h>

//  Auxiliary Function (Helper Function)
void Merge(int *arr, int LB, int mid, int UB) {
    int L_size = mid - LB + 1;     // Size of left subarray
    int R_size = UB - mid;         // Size of right subarray

    //  Creating two temporary arrays to hold the left and right subarrays 
    int left[L_size], right[R_size];
    
    //  Copy data to temporary sub-arrays from original array
    for(int i = 0; i < L_size; i++) {
        left[i] = arr[LB + i];
    }
    for(int j = 0; j < R_size; j++) {
        right[j] = arr[mid + 1 + j];
    }

    //  Merge the left and right subarrays back into the original array
    int i = 0, j = 0, k = LB;

    while(i < L_size && j < R_size) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    //  Copy the remaining elements of the left subarrays, if any
    while(i < L_size) {
        arr[k++] = left[i++];
    }

    //  Copy the remaining elements of the right subarrays, if any
    while(j < R_size) {
        arr[k++] = right[j++];
    }
}

                

//  Implementation of Merge Sort Algorithm.
void MergeSort(int *arr, int LB, int UB) {
    if(LB < UB) {
        // Find the middle point to divide array into two halves.
        int mid = (int)(LB + UB)/2;

        // Recursively sort the two halves.
        MergeSort(arr, LB, mid);
        MergeSort(arr, mid + 1, UB);
        
        // Now we merge the sorted halves.
        Merge(arr, LB, mid, UB);
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

//  Performing Merge Sort Algorithm by invoking this function. [Initially passing 'size' as Upper Bound(UB)]
    MergeSort(arr, LB, size);

//  Printing array after sorting  
    printf("After  Sorting: ");
    displayArray(arr, size);
    return 0;
}