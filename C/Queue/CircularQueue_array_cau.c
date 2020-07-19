#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Q {
	int element[MAX];
	int front;
	int rear;
}Q;

void enQ(Q* qptr);
void display(Q* qptr);


int main() {
	int n, i;
	Q* qptr = (Q*)malloc(sizeof(Q));
	qptr->front = -1;
	qptr->rear = -1;
	printf("enter the number of element : ");
	scanf_s("%d", &n);
	for (i = 1; i < n; i++) {
		enQ(qptr);
		display(qptr);
	}

	return 0;
}

void enQ(Q* qptr) {
	int val;
	/*Q empty*/
	if ((qptr->front == 0 && qptr->rear == MAX - 1) || (qptr->front == qptr->rear + 1)) {//priority && > ||
		printf("Queue full");
		return;
	}
	/*Q init*/
	else if (qptr->front == -1 && qptr->rear == -1) {
		qptr->front = 0;
		qptr->rear = 0;
	}
	/**/
	else if (qptr->rear == MAX - 1) {
		qptr->rear = 0;
	}
	else {
		qptr->rear++;
	}

	printf("enter the data to be entered\n");
	scanf_s("%d", &val);
	qptr->element[qptr->rear] = val;
}
void display(Q* qptr) {
	int i;
	for (i = qptr->front; i <= qptr->rear; i++) {
		printf("%d\t", qptr->element[i]);
	}
}
