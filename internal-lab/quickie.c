#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int size) {
    printf("Elements in the array:  ");
    for(int i=0; i<size; i++) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

int Partition(int *arr, int p, int r) {
    int pivot = arr[r];
    int i = p-1;
    for(int j = p; j < r; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

void quickie(int *arr, int p, int r) {
    if (p < r) {
        int q = Partition(arr, p, r);
        quickie(arr, p, q-1);
        quickie(arr, q+1, r);
    }
}


void main() {
    int size;
    printf("Enter the size of the array:  ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements: ", size);
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    display(arr, size);
    quickie(arr, 0, size);
    display(arr,size);

}