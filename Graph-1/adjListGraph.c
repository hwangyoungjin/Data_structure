#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct Gragh {
	int n; // vertex 개수
	struct GraphNode* adjList[MAX_VERTEX];
}Graph;

/*그래프 초기화*/
void init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTEX; i++) {
		g->adjList[i] = NULL;
	}
}

/*vertex 삽입*/
void insert_vertex(Graph* g, int v) {
	if (v >= MAX_VERTEX) {
		printf("\nvertex 초과\n");
		return;
	}
	//개수 추가
	g->n++;
}

/*edge 삽입, vertex u의 adjList에 vertex v를 삽입*/
void insert_edge(Graph*g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		printf("\nedge 번호 잘못 입력\n");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;

	// 새로들어온 node는 기존에 연결된 node를 연결
	node->link = g->adjList[u]; 
	//다시 root는 새로들어온 node를 연결
	g->adjList[u] = node; 
}

void print_adj_list(Graph* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* horse = g->adjList[i];
		printf("vertex %d의 adjacency List  ", i);
		while (horse != NULL) {
			printf("-> %d  ", horse->vertex);
			horse = horse->link;
		}
		printf("\n");
	}
}

int main() {
	Graph* g = (Graph*)malloc(sizeof(Graph));
	init(g);
	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);

	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);

	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);

	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);

	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);

	print_adj_list(g);
	free(g);
	return 0;
}

