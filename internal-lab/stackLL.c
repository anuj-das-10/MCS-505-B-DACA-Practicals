#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *TOP = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->link = TOP;
    TOP = newNode;
    printf("%d pushed to the Stack!\n", x);
}

void pop() {
    if(TOP == NULL) {
        printf("Stack Underflow\n");
        return ;
    }
    printf("%d popped from the Stack!\n", TOP->data);
    TOP = TOP->link;
}

void displayStack() {
    struct Node* ptr;
    if(TOP == NULL) {
        printf("Stack is Empty\n");
        return ;
    }
        ptr = TOP;
        printf("The elements in the Stack are : ");
        while(ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
}

void main() {
    push(12);
    push(34);
    displayStack();
    push(50);
    push(38);
    push(98);
    displayStack();
    pop();
    displayStack();
    pop();
    displayStack();
}