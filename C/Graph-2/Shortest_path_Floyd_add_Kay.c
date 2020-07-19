#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERICES 100
#define INF 1000000 /*무한대 뜻*/

typedef struct Graph {
	int n;
	int adjMatrix[MAX_VERICES][MAX_VERICES];
}Graph;

int A[MAX_VERICES][MAX_VERICES];

/*========Path 출력용 kay[][] 선언, 0으로 초기화========*/
int kay[MAX_VERICES][MAX_VERICES] = { 0, };

void printA(Graph* g) {
	int i, j;
	printf("=======================\n");
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF) {
				printf("  * ");
			}
			else {
				printf("%3d ", A[i][j]);
			}
		}
		printf("\n");
	}
	printf("=======================\n");
}

void floyd(Graph* g) {
	int i, j, k;

	/*A^-1 만들기 = adjMatrix 복사*/
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			A[i][j] = g->adjMatrix[i][j];
		}
	}
	printA(g);

	/*vertex 수 만큼 반복 마지막 A^(n) 까지 구하고 종료 */
	for (k = 0; k < g->n; k++) { // A^(k)
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				//vertex k를 들렸다가는게 빠른지
				//direct로 가는게 빠른지 검사
				if (A[i][k] + A[k][j] < A[i][j]) {
					A[i][j] = A[i][k] + A[k][j];
					//kay update
					kay[i][j] = k;
				}
			}
		}
	}
	printA(g);
}
/*=====================Output A Shortest Path=====================*/

void output_path(int i, int j, int start) { 

	if (i == j) { // i와j가 같다면 0 이므로 return
		return;
	}
	if (kay[i][j] == 0) { // kay[i][j] == 0 이면 같다면 중간 vertex 없음
		if (start == i) { // i가 시작vertex이라면 i출력
			printf("%d  ", i);
		}
		// 중간 vertex 없으면 
		// 왼쪽 부터 순회하므로 오른쪽 vertex인 j 출력하고 return
		printf("%d  ", j);

	}
	else { // 중간 vertex가 있다면 왼쪽 -> 왼쪽순 순회으로 
		output_path(i, kay[i][j], start);
		output_path(kay[i][j], j, start);
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

	floyd(&g);

	printf("\n\nvertex %d 부터 vertex %d 까지 MST : ", 0, 1);
	output_path(0, 1, 0);
	return 0;
}