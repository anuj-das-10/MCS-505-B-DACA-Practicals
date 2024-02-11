// 2.(a) Program to implement all operations of Linear Queue using Array
#include<stdio.h>
#define n 10

int queue[n], front = -1, rear = -1;

void displayQueue() {
	int i;
   	if(front == -1)
   		printf("Queue is empty!\n");
   	else {
      	printf("Queue elements are: ");
      	for(i = front; i <= rear; i++) {
      		printf("%d  ", queue[i]);		
	  	}
    printf("\n\n");
   }
}

void Enqueue() {
   int val;
   if(rear == n - 1)
   printf("Queue Overflow..!!\n");
   else{
      	if(front == -1) {
			front = 0;
		}
      	
      	printf("Enter the element to be inserted: ");
      	scanf("%d", &val);
      	rear++;
      	queue[rear] = val;
      	system("cls");
      	printf("%d enqueued successfully!\n",queue[rear]);
      	displayQueue();
   }
}

void Dequeue() {
   if(front == - 1 || front > rear) {
      	printf("Queue Underflow..!");
      	return;
   	} else{
   	  	system("cls");
     	printf("%d dequeued successfully!\n", queue[front]);
      	front++;
      	displayQueue();
   }
}


void main() {
   int ch;
  
   	do {
   		printf("<------ QUEUE OPERATIONS ------>\n");
    	printf("1. Enqueue elements\n");
    	printf("2. Dequeue elements\n");
    	printf("3. Display elements\n");
    	printf("4. Exit\n");

    	printf("Enter your choice:  ");
   		scanf("%d", &ch);

      switch (ch) {
         	case 1: Enqueue();
        		 	break;
         	case 2: Dequeue();
        		 	break;
         	case 3: system("cls");
		 		 	displayQueue();
        		 	break;
         	case 4: printf("Exited\n");
        		 	break;
        	default: printf("Invalid choice!\n");
      	}
   } while(ch != 4);
}
