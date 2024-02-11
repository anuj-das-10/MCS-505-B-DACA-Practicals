#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;       //Global Variables

void enQueue(int val);
void deQueue();

void displayQueue() {
    struct Node *temp = front;
	printf("Elements in the Queue: ");
    while(temp) {
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
	enQueue(12);
	enQueue(34);
	enQueue(40);
}

void enQueue(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d enQueued!\n", newNode->data);
    displayQueue();
}



void deQueue() {
    struct Node *temp;

    if(front == NULL){
	    printf("\nQueue is already empty!\n");
	}
	else {
        temp = front;
		front = front->next;

    	if(front == NULL){
			rear = NULL;
		}
		printf("\n%d deQueued from the Queue!\n",temp->data);
        free(temp);
        displayQueue();
    }

}
