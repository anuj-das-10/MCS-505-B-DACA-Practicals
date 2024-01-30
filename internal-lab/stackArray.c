#include<stdio.h>
#define MAX 6


void push(int *stack, int *size, int x);
void pop(int *stack, int *size);

void displayStack(int stack[], int size) {
    printf("The elements in the Stack are : ");
    for(int i = 0; i < size; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void main() {
    int stack[] = {};
    int size = 0;
    printf("Pushing elements to the stack\n");
    push(stack, &size, 15);
    push(stack, &size, 23);
    push(stack, &size, 47);
    push(stack, &size, 65);
    push(stack, &size, 20);
    push(stack, &size, 80);

    push(stack, &size, 100);

    displayStack(stack, size);

    pop(stack, &size);
    displayStack(stack, size);
    pop(stack, &size);
    pop(stack, &size);
    displayStack(stack, size);
}

void push(int *stack, int *size, int x) {
    if(*size == MAX) {
        printf("\nStack is full! Can't push %d.\n", x);
        return;
    }
    else { 
        stack[*size] = x; // Add item at top of stack
        *size += 1;
        printf("%d pushed to stack\n", x);
    }
}

void pop(int *stack, int *size) {
    if(*size == 0) {
        printf("Stack is empty!\n");
        return;
    }
    else {
        int x = stack[*size - 1]; // Get topmost element
        *size -= 1;
        printf("Popped element: %d\n", x);
    }
}