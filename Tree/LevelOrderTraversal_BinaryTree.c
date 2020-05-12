#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100 //circular이므로 최대 element수 : MAX_SIZE-1

/* Queue를 이용한 Binary Tree Level 탐색 */

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;

/*Circular Queue 이용*/
typedef struct Queue { 
	element data[MAX_SIZE];
	int front; // 첫번쨰 element 앞 (빈공간)
	int rear; //마지막 element 
}Queue;

Queue* newQueue();
int isEmpty(Queue* queue); //비었으면 TRUE
int isFull(Queue* queue); // 포화상태이면 TRUE
void enQ(Queue *queue, element data);
element deQ(Queue* queue); // 반환 후 삭제
void levelOrder(TreeNode * ptr);


/*
			15
		4		20
	   1	   16 25
*/

int main() {
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,&n1,NULL };
	TreeNode n3 = { 16,NULL,NULL };
	TreeNode n4 = { 25,NULL,NULL };
	TreeNode n5 = { 20,&n3,&n4 };
	TreeNode n6 = { 15,&n2,&n5 };
	TreeNode* root = &n6;

	printf("\n\nlevel 순회 시작 \n");
	levelOrder(root);
	printf("\nlevel 순회 끝\n");

}

Queue* newQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = -1;
	queue->rear = -1;
	return queue;
}

int isEmpty(Queue* queue) {
	if (queue->rear == queue->front) {
		return TRUE;
	}
	return FALSE;
}

int isFull(Queue* queue) {
	if (((queue->rear)+1)%(MAX_SIZE) == queue->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
void enQ(Queue* queue, element data) {
	if (isFull(queue)) {
		printf("\nQueue is Full\n");
		return;
	}
	else {
		// 첫 element 인 경우
		if (queue->rear == -1 && queue->front == -1) { 
			queue->rear = 1;
			queue->front = 0;
		}
		// rear가 가리키는 index가 maxsize-1인 경우 다시 처음부터
		else if ((queue->rear) == MAX_SIZE - 1) { 
			queue->rear = 0;
		}
		else {
			queue->rear++;
		}
		queue->data[(queue->rear)%MAX_SIZE] = data;
		return;
	}
}

element deQ(Queue* queue) {
	if (isEmpty(queue)) {
		printf("\n queue is empty!!\n");
	}
	else {
		queue->front++;
		return queue->data[(queue->front) % (MAX_SIZE)];
	}
}

void levelOrder(TreeNode* root) {
	Queue* queue = newQueue();
	if (root == NULL) {
		return;
	}
	enQ(queue, root); // 맨처음 root enQ

	/*큐의 element 있을때까지 반복*/
	while (!isEmpty(queue)) { 
		root = deQ(queue); // 1.queue에 있는 node 꺼내서
		printf("%d  ", root->data); // 2. data 출력

		/*level down*/
		if (root->left != NULL) { // 3.왼쪽의 자식이 있다면 자식 enQ
			enQ(queue, root->left);
		}
		if (root->right != NULL) { // 4.오른쪽의 자식이 있다면 자식 enQ
			enQ(queue, root->right);
		}
	}
}