#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100 //circular�̹Ƿ� �ִ� element�� : MAX_SIZE-1

/* Queue�� �̿��� Binary Tree Level Ž�� */

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;

/*Circular Queue �̿�*/
typedef struct Queue { 
	element data[MAX_SIZE];
	int front; // ù���� element �� (�����)
	int rear; //������ element 
}Queue;

Queue* newQueue();
int isEmpty(Queue* queue); //������� TRUE
int isFull(Queue* queue); // ��ȭ�����̸� TRUE
void enQ(Queue *queue, element data);
element deQ(Queue* queue); // ��ȯ �� ����
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

	printf("\n\nlevel ��ȸ ���� \n");
	levelOrder(root);
	printf("\nlevel ��ȸ ��\n");

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
		// ù element �� ���
		if (queue->rear == -1 && queue->front == -1) { 
			queue->rear = 1;
			queue->front = 0;
		}
		// rear�� ����Ű�� index�� maxsize-1�� ��� �ٽ� ó������
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
	enQ(queue, root); // ��ó�� root enQ

	/*ť�� element ���������� �ݺ�*/
	while (!isEmpty(queue)) { 
		root = deQ(queue); // 1.queue�� �ִ� node ������
		printf("%d  ", root->data); // 2. data ���

		/*level down*/
		if (root->left != NULL) { // 3.������ �ڽ��� �ִٸ� �ڽ� enQ
			enQ(queue, root->left);
		}
		if (root->right != NULL) { // 4.�������� �ڽ��� �ִٸ� �ڽ� enQ
			enQ(queue, root->right);
		}
	}
}