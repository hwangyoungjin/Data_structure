#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

/*Curcular는 data개수 MAX-1개 */

typedef struct Q {
	int element[MAX];
	/*front, rear init 초기값 0 */
	int front; // ++후 삭제, 현재 data 위치(빈공간) 지정
	int rear; //++하고 삽입, **1부터 시작** : 마지막 data 위치(데이터 공간) 지정
}Q;


/*Operate*/
Q* createQ(); //Q 생성
int IsFullQ(Q* queue); // 가득차면 TRUE반환
int IsEmptyQ(Q* queue); // 비었으면 TRUE반환
void addQ(Q* queue, int data); // 값추가
int deleteQ(Q* queue); // 값 뺴오기


int main() {
	int i;
	Q* queue = NULL;
	queue = createQ();
	addQ(queue, 1);
	addQ(queue, 2);
	addQ(queue, 3);
	addQ(queue, 4);
	printf("\nDeQueue data : %d\n", deleteQ(queue)); //deQ data '1'
	printf("\nDeQueue data : %d\n", deleteQ(queue)); //deQ data '2'
	printf("\nDeQueue data : %d\n", deleteQ(queue)); //deQ data '3'
	addQ(queue, 5);
	addQ(queue, 6);
	addQ(queue, 7);
	printf("\nQueue(front : %d, rear : %d)", queue->front, queue->rear);
	if (!IsEmptyQ(queue)) {
		int i = queue->front;
		do {
			i = (i + 1) % MAX; //front는 빈공간이므로 +1
			printf("\n\n%d\t", queue->element[i]);
			if (i == queue->rear) { // 모든값 출력 완료
				break;
			}
		} while (1);
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
	if (((queue->rear) + 1)%MAX == queue->front) { 
		printf("Queue Full!!!");
		return TRUE;
	}
	else {
		return FALSE;
	}
}
int IsEmptyQ(Q* queue) {
	if (queue->front == queue->rear) {
		printf("\nQueue Empty!!\n");
		return TRUE;
	}
	else
		return FALSE;
}
void addQ(Q* queue, int data) {
	if (IsFullQ(queue)) {
		return ;
	}
	else if (queue->front == -1 && queue->rear == -1) {
		queue->front = 0;
		queue->rear = 1;
	}
	else if (queue->rear == MAX - 1) {
		queue->rear = 0;
	}
	else {
		queue->rear++;
	}

	queue->element[(queue->rear) % MAX] = data;
}

int deleteQ(Q* queue) { 
	int temp;
	if (IsEmptyQ(queue)) {
		return NULL;
	}
	else {
		temp = queue->element[(++queue->front)%MAX];
		return temp;
	}

}
