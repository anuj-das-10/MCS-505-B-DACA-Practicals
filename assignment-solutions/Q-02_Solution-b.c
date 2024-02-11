// 2.(b) Program to implement all operations of Linear Queue using Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
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
    printf("\n\n");
}

void main() {
	int choice, x;
	do {
	printf("<------ QUEUE OPERATIONS ------>\n");
	printf("1. enQueue Elements\n2. deQueue Elements\n3. Display Elements\n4. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d", &choice);
	
	switch(choice) {
		case 1: printf("Enter the element to be inserted: ");
				scanf("%d",&x);
				enQueue(x);
				break;
		case 2: deQueue();
				break;
		case 3: system("cls");
				displayQueue();
				break;
		case 4: system("cls");
				printf("\nExited...\n\n");
				exit(0);

	       default: system("cls");
				printf("\nInvalid Choice!!\n\n");
		}
	}while(choice != 4);
}

void enQueue(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if(!newNode) {
    	system("cls");
    	printf("Queue Overflow!\n");
	}
    
    newNode->data = val;
    newNode->next = NULL;

    if(front == NULL && rear == NULL) {
		front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    
    system("cls");
    printf("%d enQueued to the Queue!\n", newNode->data);
    displayQueue();
}



void deQueue() {
    struct Node *temp;

    if(front == NULL){
		system("cls");
		printf("Queue Underflow!\n");
	}
	else {
        temp = front;
		front = front->next;

    	if(front == NULL){
			rear = NULL;
		}
		
		system("cls");
		printf("%d deQueued from the Queue!\n", temp->data);
        free(temp);
        displayQueue();
    }
}

