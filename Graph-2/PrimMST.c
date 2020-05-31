#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct Graph {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}Graph;

int selected[MAX_VERTICES];  

//현재까지 알려진 집합에서 갈 수 있는 정점까지의 거리를 모아둠
//index 1의 값이 10이라면 현재 집합에서 vertex 까지의 거리가 10 이라는 뜻
int distance[MAX_VERTICES]; 

/*최소 distance[v] 값을 갖는 정점을 반환*/
int get_min_vertex(int n) {
	// n은 vertex의 개수
	int v = 0;
	int i;
	for (i = 0; i < n; i++) {
		// 아직 선택되지 않은 정점의 번호를 v에 저장
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	// 이때 v는 방문하지 않은 vertex , v가 최소거리를 지니고 있는 정점인지를 확인
	for (i = 0; i < n; i++) {
		// vertex 0부터 n까지 방문하지 않고 v보다 거리가 짧은 vertex 저장
		if (!selected[i] && (distance[i] < distance[v])) {
			v = i;
		}
	}
	return v;
}

//s 는 탐색 시작 vertex
void prim(Graph* g, int s) {
	int i;
	int u, v;
	//------------------------------------------초기 시작------------------------
	//vertex 개수만큼 distance 무한대로 초기화
	for (u = 0; u < g->n; u++) { 
		distance[u] = INF;
	}

	//시작 vertex distance 0설정
	distance[s] = 0;
	

	//------------------------------------------초기 끝------------------------	

	// vertex 개수 만큼 반복
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n); //u는 방문안한 vertex중 가장 distance가 짧은 vertex
		printf("\ncheck! u : %d\n", u);
		
		selected[u] = TRUE; // 방문했다고 표시
		
		//가장짧은 vertex 길이가 무한대라면 prim 종료
		if (distance[u] == INF) { 
			return;
		}

		//{집합}을 구성했다고 가정
		printf("\nvertex %d 추가\n", u); 

		//2차원 배열에 있는 weight 값과 전역변수 distance 값 비교를 통한 
		//전역변수 distance 갱신을 위해 vertex 개수 반큼 반복
		for (v = 0; v < g->n; v++) { 
			//v는 vertex 0부터 n까지
			//vertex u 인접 vertex v라면
			if (g->weight[u][v] != INF) {
				//vertex u 인접 vertex v가 방문되지 않고 전역 distance 보다 weight가 작다면
				if (!selected[v] && g->weight[u][v] < distance[v]) {
					//전역 distance 갱신
					distance[v] = g->weight[u][v];
				}
			}
		}
	}
}

int main() {

	Graph g = { 7,
	{{0,29,INF,INF,INF,10,INF},
	{ 29,0,15,INF,INF,INF,15},
	{INF,16,0,12,INF,INF,INF},
	{INF,INF,12,0,22,INF,18},
	{INF,INF,INF,22,0,27,25},
	{10,INF,INF,INF,27,0,INF},
	{INF,15,INF,18,25,INF,0}}
	};

	printf("\n\n %d", g.n);

	prim(&g, 0);

	return 0;
}