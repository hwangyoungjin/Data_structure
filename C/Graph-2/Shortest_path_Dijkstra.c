#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /*infinite*/

typedef struct Graph {
	int n;
	int adjMatrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

int distance[MAX_VERTICES]; // 시작vertex 으로 부터 최단경로 거리
int found[MAX_VERTICES]; // 방문한 vertex 표시 (S집합)

/*가장 짧은 distance, 방문하지 않은 vertex 선택하여 vertex번호 => minpos 반환*/
int choose(int distance[], int vertex_n, int found[]) {
	int i, min, minpos;
	min = INT_MAX; // limit.h에 존재 int의 max값

	minpos = 1; // 반환할 distance 짧은 vertex 번호 : 1부터 시작한다.
	for (i = 0; i < vertex_n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

/*찾은 경로 출력*/
void print_status(Graph* g) {
	static int step = 1;
	printf("STEP %d : ", step++);
	printf("distance : ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF) {
			printf(" * ");
		}
		else {
			printf("%2d ", distance[i]);
		}
	}
	printf("\n");
	printf(" found : ");
	for (int i = 0; i < g->n; i++) {
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

/*외부 반복 n번 내부반복 2n번 = O(n^2)*/
void shortest_path(Graph* g, int start) {
	int i, u, w; //w : 다음
	
	/*distance 와 S집합(found) init*/
	for (i = 0; i < g->n; i++) {
		distance[i] = g->adjMatrix[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;


	for (i = 0; i < g->n - 1; i++) {
		print_status(g); // 현재 status 확인
		u = choose(distance, g->n, found); //최단 거리 vertex 번호 
		found[u] = TRUE; // 해당 vertex S집합에 넣기
		
		/*현재 S집합을 기준으로 distance 갱신*/
		for (w = 0; w < g->n; w++) { 
			if (!found[w]) { // S 집합이 아니고
				// 시작vertex부터 vertex w까지 저장된 거리(distance[w])보다 
				// 짧은 distance나오면 갱신
				if ((distance[u] + g->adjMatrix[u][w]) < distance[w]) {
					/*시작 vertex부터 w vertex까지 거리를 갱신*/
					// 시작 vertex 부터 u vertex까지 거리에 
					// u vertex부터 w까지의 거리를 더한다. 
					distance[w] = distance[u] + g->adjMatrix[u][w];
				}
			}
		}
	}
}


int main() {

	Graph g = { 7,
	{{0,7,INF,5,INF,2,INF},
	{7,0,6,INF,2,INF,INF},
	{INF,6,0,2,INF,INF,2},
	{5,INF,2,0,INF,5,INF},
	{INF,2,INF,INF,0,2,INF},
	{2,INF,INF,5,2,0,4},
	{INF,INF,2,INF,INF,4,0}}
	};

	shortest_path(&g, 0);
	return 0;
}