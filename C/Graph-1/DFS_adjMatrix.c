#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct Graph {
	int n; // vertex 개수 (번호는 0 부터)
	int adjMat[MAX_VERTICES][MAX_VERTICES];
}Graph;

int visited[MAX_VERTICES]; //방문 체크

/*graph init*/
void init(Graph* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		for (c = 0; c < MAX_VERTICES; c++) {
			g->adjMat[r][c] = 0;
		}
	}
}

/*insert vertex */
void insert_vertex(Graph* g) {
	/*vertex full인지 확인*/
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("\n\nvertex 초과\n");
		return;
	}
	g->n++;
}


/*insert edge*/
void insert_edge(Graph* g, int start, int end) {
	/*vertex 번호 확인 - 개수는 1부터,번호는 0 부터*/
	if (start >= (g->n) || end >= (g->n)) {
		printf("\n\nvertex 번호 오류\n");
		return;
	}
	g->adjMat[start][end] = 1;
	g->adjMat[end][start] = 1;
}


/* DFS */
void dfs_mat(Graph* g, int vertex) {
	int w;
	visited[vertex] = TRUE; //vertex v 방문표시
	printf("vertex %d -> ", vertex);
	
	/*인접 vertex 탐색*/
	for (w = 0; w < g->n; w++) {
		/*인접 vertex가 존재하고 해당 vertex가 방문하지않은 vertex라면 탐색*/
		if (g->adjMat[vertex][w] && !visited[w]) {
			dfs_mat(g, w);
		}
	}
}

int main() {
	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	init(g);
	for (int i = 0; i < 4; i++) {
		insert_vertex(g);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printf("\nDFS 시작\n\n");
	dfs_mat(g, 0);
	printf("\n\nDFS 끝");
	free(g);
	return 0;
}