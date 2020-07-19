#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct myqueue {
	int front;
	int rear;
	int data[MAX];
}pqueue;

void Insert(pqueue* queue);
void Delete(pqueue* queue); /*queue[0]부터 priority가 높은 순서대로 Delete*/
void Display(pqueue* queue, pqueue* queue1, pqueue* queue2);
int IsEmpty(pqueue* queue);
int IsFull(pqueue* queue);

int main() {
	pqueue queue[3];
	int ch, i, n;
	for (i = 0; i < 3; i++) {
		queue[i].front = -1;
		queue[i].rear = -1;
	}

	while (1) {
		printf("\n--------MENU-------\n");
		printf("1,Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice : ");
		scanf_s("%d", &ch);
		switch (ch) {
			case 1:
				printf("\nEnter priority : ");
				scanf_s("%d", &n);
				Insert(&queue[n - 1]);
				break;
			case 2: /*queue[0]부터 priority가 높은 순서대로 Delete*/
				if (IsEmpty(&queue[0])) {
					if (IsEmpty(&queue[1])) {
						if (IsEmpty(&queue[2])) {
							printf("\n All Queue are Empty..");
							break;
						}
						else
							n = 2;
					}
					else
						n = 1;
				}
				else
					n = 0;
				Delete(&queue[n]);
				break;
			case 3:
				Display(&queue[0], &queue[1], &queue[2]);
				break;
			case 4:
				exit(0);
			default :
				printf("\nInvalid choice..");
		}
	}
	return 0;
}

int IsEmpty(pqueue* queue) {
	if (queue->front == queue->rear) {
		return 1;
	}
	else {
		return 0;
	}
}
int IsFull(pqueue* queue) {
	if (queue->rear == MAX - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void Insert(pqueue* queue) {
	int x;
	if (IsFull(queue)) {
		printf("\nQueue overflow, another Queue choice\n");
		
	}
	else {
		printf("\nEnter the element to be Inserted : ");
		scanf_s("%d", &x);
		queue->data[++(queue->rear)] = x;
	}
}
void Delete(pqueue* queue) {
	int n;
	n = queue->data[++(queue->front)];
	printf("The delate data is = %d", n);
}
void Display(pqueue* queue1, pqueue* queue2, pqueue* queue3) {
	int i=0;
	if (IsEmpty(queue1)) {
		printf("\nQueue1 is Empty");
	}
	else {
		printf("\nThe contents queue1 ara [Queue1 (front : %d, rear : %d)]: ",queue1->front,queue1->rear);
		if (queue1->front > -1) {
			for (i = queue1->front + 1; i <= queue1->rear; i++) {
				printf("%d\t", queue1->data[i]);
			}
		}
		else {
			for (i = 0; i <= queue3->rear; i++) {
				printf("%d\t", queue1->data[i]);
			}
		}
	}
	if (IsEmpty(queue2)) {
		printf("\nQueue2 is Empty");
	}
	else {
		printf("\nThe contents queue2 ara [Queue2 (front : %d, rear : %d)]: ", queue2->front, queue2->rear);
		if (queue2->front > -1) {
			for (i = queue2->front + 1; i <= queue2->rear; i++) {
				printf("%d\t", queue2->data[i]);
			}
		}
		else {
			for (i = 0; i <= queue2->rear; i++) {
				printf("%d\t", queue2->data[i]);
			}
		}
	}
	if (IsEmpty(queue3)) {
		printf("\nQueue3 is Empty");
	}
	else {
		printf("\nThe contents queue3 ara [Queue3 (front : %d, rear : %d)]: ", queue3->front, queue3->rear);
		if (queue3->front > -1) {
			for (i = queue3->front + 1; i <= queue3->rear; i++) {
				printf("%d\t", queue3->data[i]);
			}
		}
		else {
			for (i=0; i <= queue3->rear; i++) {
				printf("%d\t", queue3->data[i]);
			}
		}
	}
}
