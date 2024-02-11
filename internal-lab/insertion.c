#include<stdio.h>

void display(int arr[], int size) {
    printf("Elements in array:  ");
    for(int i=0; i<size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void main() {
    int n;
    printf("Enter the size of the array:  ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0 ; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    display(arr, n);

    // Insertion Sort

    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

display(arr, n);

}