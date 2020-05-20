#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct Gragh {
	int n; // vertex ����
	struct GraphNode* adjList[MAX_VERTEX];
}Graph;

/*�׷��� �ʱ�ȭ*/
void init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTEX; i++) {
		g->adjList[i] = NULL;
	}
}

/*vertex ����*/
void insert_vertex(Graph* g, int v) {
	if (v >= MAX_VERTEX) {
		printf("\nvertex �ʰ�\n");
		return;
	}
	//���� �߰�
	g->n++;
}

/*edge ����, vertex u�� adjList�� vertex v�� ����*/
void insert_edge(Graph*g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		printf("\nedge ��ȣ �߸� �Է�\n");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;

	// ���ε��� node�� ������ ����� node�� ����
	node->link = g->adjList[u]; 
	//�ٽ� root�� ���ε��� node�� ����
	g->adjList[u] = node; 
}

void print_adj_list(Graph* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* horse = g->adjList[i];
		printf("vertex %d�� adjacency List  ", i);
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

