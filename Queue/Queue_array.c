#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define TRUE 1
#define FALSE 0


typedef struct Q {
	int element[MAX];
	/*front, rear init 초기값 -1 */
	int front; //++하고 삭제, 현재 맨 앞 data의 바로 앞 위치(빈공간) 지정 
	int rear; //++하고 삽입, 마지막 data 위치(데이터 공간) 지정
}Q;


/*Operate*/
Q* createQ(); //Q 생성
int IsFullQ(Q* queue); // 가득차면 TRUE반환
int IsEmptyQ(Q* queue); // 비었으면 TRUE반환
void addQ(Q* queue, int data); // 값추가
int deleteQ(Q* queue); // 값 뺴오기


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
