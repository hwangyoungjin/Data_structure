#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 50

typedef struct Graph {
	int n; // ������ ����
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}Graph;


/*�ʱ�ȭ*/
void init(Graph* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTEX; r++) {
		for (c = 0; c < MAX_VERTEX; c++) {
			g->adjMatrix[r][c] = 0;
		}
	}
}


/*vertex ����*/
void insert_vertex(Graph* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n���� ���� �ʰ�\n");
		return;
	}
	g->n++;
}

/*edge ����*/
void insert_edge(Graph* g, int start, int end) {
	if (start >= g->n || end >= g->n) { 
		// ���� vertex ��ȣ���� ũ�ٸ� ����!
		printf("\n�׷��� : vertex ��ȣ ����\n");
		return;
	}
	g->adjMatrix[start][end] = 1;
	g->adjMatrix[end][start] = 1;
}

/*matrix ���*/
void print_adj_matrix(Graph* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d  ", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

int main() {

	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	init(g);
	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_matrix(g);
	free(g);
	return 0;
}