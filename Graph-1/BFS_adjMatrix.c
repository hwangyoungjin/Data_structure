#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct Graph {
	int n; // vertex 개수
	int adjMatrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

int visited[MAX_VERTICES]; 

typedef struct Queue {
	element queue[MAX_QUEUE_SIZE];
	int rear, front;
}Queue;

/*큐 생성 후 초기화*/
Queue* create_queue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

/*큐 비어있으면 TRUE 반환*/
int is_empty(Queue* queue) {
	if (queue->front == queue->rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*큐 FULL이면 TRUE반환*/
int is_full(Queue* queue) {
	if ((((queue->rear) + 1) % MAX_QUEUE_SIZE )== queue->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*insert element*/
void en_queue(Queue* queue, element item){
	
	if (is_full(queue)) {
		printf("\nQueue is Full!!\n");
		return;
	}
	else if ((queue->rear == -1) && (queue->front == -1)) {
		queue->rear = 1;
		queue->front = 0;
	}
	else if (queue->rear == MAX_QUEUE_SIZE -1) {
		queue->rear = 0;
	}
	else {
		queue->rear++;
	}
	queue->queue[(queue->rear)%MAX_QUEUE_SIZE] = item;

}

element de_queue(Queue* queue) {
	if (is_empty(queue)) {
		printf("\nQueue is Empty!\n");
		return;
	}
	return queue->queue[(++(queue->front))%MAX_QUEUE_SIZE];
}

/*================================graph================================*/

/*init */
void graph_init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->adjMatrix[i][j] = 0;
		}
	}
}


void insert_vertex(Graph* g) {
	if (((g->n) + 1) >= MAX_QUEUE_SIZE) {
		printf("\nvertex 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge(Graph* g, int start, int end) {
	if (start >= g->n || end >= g->n) { 
		//n은 vertex개수 vertex 번호는 n-1까지 존재
		printf("\nvertex 번호 오류\n");
		return;
	}
	g->adjMatrix[start][end] = 1;
	g->adjMatrix[end][start] = 1;
}

void bfs_matrix(Graph* g, int v) {
	int w; // 다음 vertex
	Queue *q = create_queue(); // queue 생성
	

	visited[v] = TRUE;
	printf("%d visited -> ",v);
	en_queue(q,v); // 시작지점 queue에 저장
	
	while (!is_empty(q)) { //queue에 element 있을때까지 반복
		
		v = de_queue(q); // 1.dequeue
		for (w = 0; w < g->n; w++) { //2.v 인접 vertex 0부터 check
			
			//3.b방문하지않았고 주변 vertex 존재의 경우 - 1.enqueue 2.visited
			if (g->adjMatrix[v][w] && !visited[w]) { 		
				visited[w] = TRUE; // 3-1. 방문 표시
				printf("%d visited -> ", w);
				en_queue(q, w); // 3-2. queue 넣기
				
			}
		}
	}
}

int main() {

	Graph* g = (Graph*)malloc(sizeof(Graph));
	graph_init(g);
	for (int i = 0; i < 6; i++) {
		insert_vertex(g);
	}
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);


	printf("\n\nBFS 시작\n");
	bfs_matrix(g, 0);
	printf("\nBFS 끝\n");
	free(g);

	return 0;
}