#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node* ptr;
}node;
node * front, * rear, * temp, * front1; 
// temp is used in enq, front is used in deq

int count; //node count

int frontelement(); //only return queue front // self codind
void enq(int data); 
void deq(); 

void display();//self codind
void create();

// void queuesize();
// void empty();
int main() {
	create();
	int choice=0;
	int data = 0;
	while (1) {
		choice = 0;
		printf("\n\n 1 - Enque");
		printf("\n 2 - Deque");
		printf("\n 3 - Front elemnet");
		printf("\n 4 - Exit");
		printf("\n 5 - Display");
		printf("\n 6 - Queue size");
		printf("\n Enter choice : ");
		scanf_s("%d", &choice);
		switch (choice) {
			case 1: 
				printf("\n Enter data : ");
				scanf_s("%d", &data);
				enq(data);
				break;
			case 2:
				deq();
				break;
			case 3:
				printf("\nFront element : %d",frontelement());
				break;
			case 4:
				exit(0);
			case 5:
				display();
				break;
			case 6:
				printf("\nQueue size : %d ", count);
				break;
		}
	}
	return 0;
}

void create() {
	front = NULL;
	rear = NULL;
}

void enq(int data) {
	if (rear == NULL) {
		rear = (node*)malloc(1*sizeof(node));
		rear->ptr =  NULL;
		rear->info = data;
		front = rear; // The same node as the first
	}
	else {
		temp = (node*)malloc(1 * sizeof(node));
		rear->ptr = temp; // NewNode link
		temp->info = data; // Newnode added data
		temp->ptr = NULL; // NewNode's ptr = null

		rear = temp; // rear relocate
	}
	count++;
}

void deq() {
	front1 = front;
	
	if (front1 == NULL) { 
		printf("\n Error : Trying ro display element from empty queue");
		return;
	}
	else {
		if (front1->ptr != NULL) { //node is two or more 
			front1 = front1->ptr; 
			printf("\n Dequed value : %d", front->info);
			free(front);
			front = front1;
		}
		else { // Only one node
			printf("\n Dequed value : %d", front1->info);
			free(front);
			front = NULL;
			rear = NULL;
		}
		count--;
	}
}

void display() { //self codind
	node *temp1 = front;
	while (temp1 != NULL) { // null
		printf("%d  ", temp1->info);
		temp1 = temp1->ptr;
	}
}
int frontelement() {
	return front->info;
}