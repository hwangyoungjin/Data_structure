#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define TRUE 1
#define FALSE 0


typedef struct Q {
	int element[MAX];
	/*front, rear init �ʱⰪ -1 */
	int front; //++�ϰ� ����, ���� �� �� data�� �ٷ� �� ��ġ(�����) ���� 
	int rear; //++�ϰ� ����, ������ data ��ġ(������ ����) ����
}Q;


/*Operate*/
Q* createQ(); //Q ����
int IsFullQ(Q* queue); // �������� TRUE��ȯ
int IsEmptyQ(Q* queue); // ������� TRUE��ȯ
void addQ(Q* queue, int data); // ���߰�
int deleteQ(Q* queue); // �� ������


int main() {
	int i;
	Q* queue=NULL;
	queue=createQ();
	addQ(queue, 1);
	addQ(queue, 2);
	addQ(queue, 3);
	addQ(queue, 4);
	addQ(queue, 5);
	addQ(queue, 6);

	for (i = 0; i <= queue->rear; i++) {
		printf("\nNumber %d : %d\n", i, deleteQ(queue));
	}

	free(queue);

	return 0;
}

Q* createQ() {
	Q* queue = (Q*)malloc(sizeof(Q));
	queue->front = -1;
	queue->rear = -1;
	return queue;
}
int IsFullQ(Q* queue) {
	if (((queue->rear) + 1) == MAX ) {
		printf("Queue Full!!!");
		return TRUE;
	}
	else {
		return FALSE;
	}
}
int IsEmptyQ(Q* queue) {
	if (queue->front == queue->rear) {
		printf("Queue Empty!!");
		return TRUE;
	}
	else
		return FALSE;
}
void addQ(Q* queue, int data) {
	if (IsFullQ(queue)) {
		return ;
	}
	else {
		queue->element[++queue->rear] = data;
	
	}
}
int deleteQ(Q* queue) {
	int temp;
	if (IsEmptyQ(queue)) {
		return NULL;
	}
	else { 
		temp = queue->element[++queue->front];
		return temp;
	}

}
