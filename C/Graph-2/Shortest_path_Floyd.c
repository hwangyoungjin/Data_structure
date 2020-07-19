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
				}
			}
		}
	}
	printA(g);
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
	return 0;
}