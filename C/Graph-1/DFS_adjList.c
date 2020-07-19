#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct Graph {
	int n; //vertex 개수
	struct GraphNode* adjList[MAX_VERTICES];
}Graph;

int visited[MAX_VERTICES]; // 방문기록

/*graph 초기화*/
void init(Graph* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adjList[i] = NULL;
	}
}


/*vertex insert*/
void insert_vertex(Graph* g) {
	/*vertex 초과 체크*/
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("\n\nvertex 초과!\n");
		return;
	}
	g->n++;
}

/*edge insert = node 연결 */
/*vertex u의 adjList에 vertex v를 삽입 + v 뒤에 u연결*/
void insert_edge(Graph* g, int u, int v) {
	/*u, v 번호 검사*/
	if (u >= g->n || v >= g->n) {
		printf("\n\nvertex 번호 오류!");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v; //vertex number
	node->link = g->adjList[u]; // v를 기존에 있던 u를 연결
	g->adjList[u] = node; // u자리에 v들어간다
}

void dfs_list(Graph* g, int v) {
	GraphNode* w;
	visited[v] = TRUE;
	printf("vertex %d -> ", v);
	
	/*w는 adjList[0] 부터 null일때 까지 다음 link로 이동*/
	/*또는 for (w = g->adjList[v]; w!=NULL; w=w->link) */
	for (w = g->adjList[v]; w; w=w->link) {
		if (!visited[w->vertex]) {
			dfs_list(g, w->vertex);
		}
	}
}

int main() {
	Graph* g;
	Graph* g1 = NULL;
	g = (Graph*)malloc(sizeof(Graph));
	init(g);
	for (int i = 0; i < 4; i++) {
		insert_vertex(g);
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

	printf("\nDFS 시작\n\n");
	dfs_list(g, 0);
	printf("\n\nDFS 끝");
	free(g);
	return 0;
}