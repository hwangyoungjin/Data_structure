#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

/*==================union-find==================*/

int parent[MAX_VERTICES];
void set_init() {
	for (int i = 0; i < MAX_VERTICES; i++) {
		parent[i] = -1;
	}
}
int set_find(int curr) {
	if (parent[curr] == -1) {
		return curr;
	}
	while (parent[curr] != -1) {
		// curr의 부모 index 값 넣어주기
		curr = parent[curr]; 
	}
	return curr;
}

/*vertex 번호를 집합으로!*/
void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);

	if(root1 != root2){
		//최종 root는 root2가 된다.
		//b집합 root2 유지 roo1을 root2에 붙인다.
		parent[root1] = root2;
	}
}

/*==================Graph==================*/
#define INT 1000
typedef struct Edge {
	int start, end, weight;
}Edge;

typedef struct Graph {
	int n; //edge의 개수
	int vertex_n; // vertex 개수
	//list,matrix 모두 X ==>> Edge로 멤버구성
	struct Edge edges[2 * MAX_VERTICES];
}Graph;

/*Graph init*/
void graph_init(Graph* g) {
	g->n = 0;
	g->vertex_n = 0;
	for (int i = 0; i < MAX_VERTICES * 2; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INT; 
	}
}

/*edge 삽입*/
void insert_edge(Graph* g,int start,int end,int weight) {
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = weight;
	g->n++;
}

//---------------qsort()에 사용되는 함수---------------------
int compare(const void* a, const void* b) {
	Edge* x = (Edge*)a;
	Edge* y = (Edge*)b;
	return (x->weight - y->weight);
}

/*==================kruskal's MST algorithm==================*/

void kruskal(Graph* g) {
	int edge_accepted = 0; // 현재까지 선택된 edge 수
	int uset, vset; // vertex u 와 vertex v의 집합 번호
	Edge e;
	set_init(g);
	
	//stdlib.h에 포함된 qsort 호출
	qsort(g->edges, g->n, sizeof(Edge), compare);

	printf("\nKruskal MIT algorithm\n");
	int i = 0;

	/*vertex 개수 n 일때 edge 가 n-1개 될때까지 반복*/
	while (edge_accepted < (g->vertex_n-1)) { 
		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);
		

		if (uset != vset) { // 서로 속한 집합이 다르면
			printf("\nedge (%d, %d) - weight : %d 선택\n", e.start, e.end, e.weight);
			edge_accepted++; //edge 수 증가
			
			//uset을 vset에 연결  root는 vset이 된다.
			set_union(uset, vset); // 두집합 합치기
		}
		i++;
	}
}



int main() {
	Graph* g = (Graph*)malloc(sizeof(Graph));
	graph_init(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);
	g->vertex_n = 7;
	kruskal(g);
	free(g);


	return 0;
}