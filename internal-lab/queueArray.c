#include<stdio.h>
#define MAX 6

// FIFO --> Delete from first and Insert from end
void enqueue(int *queue, int *front, int *rear, int *size, int data) {
    if((*size) == MAX) {
        printf("Queue is full. Can't enqueue %d\n", data);
        return;
    } else if((*front) == (*rear) && (*size) != 0) {
        (*front) = 0, (*rear) = 0,  (*size) = 0;
    }
    else {
        queue[(*rear)++] = data;
        (*size)++;
        printf("%d enqueued!\n", data);
    }
}    

void dequeue(int *queue, int *front, int *rear, int *size) {
    if(front == 0 || front == rear) {
        printf("Queue is empty.\n");
        return;
    }
    else {
        int data = queue[*front];
        (*front)++;
        (*size)--;
        printf("Deleted %d\n", data);
    }
}

void display(int queue[], int front, int rear) {
    if(rear == 0 || front == rear) {
        printf("Queue is empty.\n");
        return;
    }
    else {
        printf("Elements in the queue:  ");
        for(int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main() {
    int queue[] = {};
    int front=0, rear=0, size = 0;
    enqueue(queue, &front, &rear, &size, 12);
    enqueue(queue, &front, &rear, &size, 24);
    enqueue(queue, &front, &rear, &size, 33);

    display(queue, front, rear);
    enqueue(queue, &front, &rear, &size, 12);
    enqueue(queue, &front, &rear, &size, 24);
    enqueue(queue, &front, &rear, &size, 33);
    display(queue, front, rear);
    enqueue(queue, &front, &rear, &size, 300);
    dequeue(queue, &front, &rear, &size);
    display(queue, front, rear);
    dequeue(queue, &front, &rear, &size);
    display(queue, front, rear);
    enqueue(queue, &front, &rear, &size, 300);
    display(queue, front, rear);
    
}