#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

/*-----------------Graph List-----------------*/

typedef struct GraphNode {
	int vertex;
	struct Node* link;
}GraphNode;

typedef struct Graph {
	int n; // vertex 개수
	struct GraphNode* adjList[MAX_VERTICES];
}Graph;

int visited[MAX_VERTICES];


/*-----------------Circular Queue-----------------*/

typedef int element;
typedef struct Quese {
	element data[MAX_QUEUE_SIZE];
	int rear, front;
}Queue;


/*create Queue*/
Queue* create_queue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

/*check queue empty*/
int is_empty(Queue* q) {
	if (q->rear == q->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/*check queue full*/
int is_full(Queue* q) {
	if (((q->rear) + 1) % MAX_QUEUE_SIZE == q->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void en_queue(Queue* q, element item) {
	if (is_full(q)) {
		printf("\nQueue is Full !!\n");
		return;
	}
	else if (q->rear == -1 && q->front == -1) {
		q->rear = 1;
		q->front = 0;
	}
	else if (q->rear == MAX_QUEUE_SIZE-1) {
		q->rear = 0;
	}
	else {
		q->rear++;
	}
	q->data[(q->rear)%MAX_QUEUE_SIZE] = item;
}

element de_queue(Queue* q) {
	if (is_empty(q)) {
		printf("\nQueue is Empty!!\n");
		return NULL;
	}
	else {
		return q->data[(++(q->front)) % MAX_QUEUE_SIZE];
	}
}

/*-------------Graph List-------------------*/

void graph_init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adjList[i] = NULL;
	}
}

void insert_vertex(Graph* g) {
	if ((g->n) + 1 > MAX_QUEUE_SIZE) { //n은 vertex 개수
		printf("\nvertex 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge(Graph*g,int u,int v){
	if (u >= g->n || v >= g->n) {
		printf("\nvertex 번호 오류\n");
		return;
	}
	/*vertex u번 자리에 vertex v넣고 v에 u연결*/
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adjList[u];
	g->adjList[u] = node;
}

void bfs_list(Graph* g, int v) {
	GraphNode* w;
	Queue* q = create_queue();
	
	//방문하고 en_queue!!
	visited[v] = TRUE;
	printf("\n%d 방문 -> ", v);
	en_queue(q, v);
	while (!is_empty(q)) { // queue 안에 element 있을때까지 반복!
		v = de_queue(q);
		// dequeue한 vertex v 인접 vertex 탐샘
		for (w = g->adjList[v]; w; w = w->link) {
			if (!visited[w->vertex]) { //미방문 vertex인 경우
				visited[w->vertex] = TRUE;
				printf("%d 방문 -> ", w->vertex);
				en_queue(q,w->vertex);
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
	insert_edge(g, 2, 0);
	insert_edge(g, 2, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	insert_edge(g, 3, 5);
	insert_edge(g, 5, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 0);
	insert_edge(g, 4, 5);
	insert_edge(g, 5, 4);
	insert_edge(g, 1, 5);
	insert_edge(g, 5, 1);

	//GraphList print
	for (int i = 0; i < g->n; i++) {
		GraphNode* horse = g->adjList[i];
		printf("\n %d vertex : ", i);
		while (horse != NULL) {
			printf("%d -> ", horse->vertex);
			horse = horse->link;
		}
		printf(" NULL ");
	}


	printf("\n\nBFS 시작\n");
	bfs_list(g, 0);
	printf("\nBFS 끝");


	return 0;
}