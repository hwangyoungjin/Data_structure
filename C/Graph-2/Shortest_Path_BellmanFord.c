#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// 간선 구조체
// src = 시작점, dest = 도착점, weight = 가중치
struct Edge
{
    int src, dest, weight;
};

// 그래프 구조체
// V :: 정점의 수 E :: 간선의 수
// edge :: 포인터 형식으로 서로 다른 정점을 연결하기 위해 존재
struct Graph
{
    int V, E;

    struct Edge* edge;
};

// V와 E를 통해 정점과 간선의 수를 가진 그래프를 생성한다.
struct Graph* createGraph(int V, int E)
{   
    //1.graph를 만들고
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph)); 

    graph->V = V;
    graph->E = E;

    //2.생성할 edge포인터 배열 만들기 
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

    return graph;
}


// 결과를 출력하기 위한 함수
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        dist[i] == INT_MAX ? printf("%d \t\tINF\n", i) : printf("%d \t\t %d\n", i, dist[i]);
}

// src에서 모든 다른 정점까지의 최단 거리를 찾아주는 BellmanFord 함수이다.
// 음의 가중치 까지 적용이 가능하다.
void BellmanFord(struct Graph* graph, int src) // graph와 시작점입력
{
    int V = graph->V; //vertex개수
    int E = graph->E; //edge 개수
    int* dist = (int*)malloc(sizeof(int) * V); // int *dist[V]과 같다.
    // vertex 개수만큼 배열 생성
    // dist는 시작점 scr에서 해당 vertex까지 가는 최단거리를 저장하는 배열

    // 모든 최단 거리를 무한대로 지정해주고, 시작점(src)만 0으로 초기화 한다.
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // 벨만 포드 알고리즘 (relax함수)
    for (int i = 1; i <= V - 1; i++) { //사이클이 발생하면 안되므로 V-1번 만큼만 실행
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;  //edge j에 해당하는 시작점
            int v = graph->edge[j].dest; //edge j에 해당하는 도착점
            int weight = graph->edge[j].weight; ////edge j에 해당하는 가중치
            // 정점u가(시작점이) 무한대가 아니고, 
            // 시작점까지의 최단 거리 + 가중치가 도착점의 가중치 
            // 보다 작을 때 업데이트 해준다.
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                //dist[v] 는 시작점에서 edge j의 도착점까지 저장된 최단거리
                dist[v] = dist[u] + weight;
        }
    }

    // 음의 가중치 때문에 무한히 최단 경로가 작아지는 것이 있다면
    // 탐색하여 알려준다.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        // if문에서 현재위치 최단거리 + 가중치가 계속해서 더 작아질 경우
        // 음의 사이클이 있다고 판단한다.
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("%d to %d  : Graph contains negative weight cycle\n",u,v);
    }

    printArr(dist, V);

    return;
}



// 사이클 없는경우
//int main()
//{
//    int V = 5;  // 정점의 수
//    int E = 9;  // 간선의 수
//    struct Graph* graph = createGraph(V, E);
//
//    // 그래프 정보를 입력해준다.
//    graph->edge[0].src = 0; // 0에서 
//    graph->edge[0].dest = 2; // 2로 가는 간선의
//    graph->edge[0].weight = 1; // 가중치는 1로 정한다.
//
//    graph->edge[1].src = 0;
//    graph->edge[1].dest = 3;
//    graph->edge[1].weight = 5;
//
//    graph->edge[2].src = 1;
//    graph->edge[2].dest = 2;
//    graph->edge[2].weight = -2;
//
//    graph->edge[3].src = 2;
//    graph->edge[3].dest = 1;
//    graph->edge[3].weight = 4;
//
//    graph->edge[4].src = 2;
//    graph->edge[4].dest = 3;
//    graph->edge[4].weight = 4;
//
//    graph->edge[5].src = 3;
//    graph->edge[5].dest = 0;
//    graph->edge[5].weight = -1;
//
//    graph->edge[6].src = 3;
//    graph->edge[6].dest = 1;
//    graph->edge[6].weight = 3;
//
//    graph->edge[7].src = 4;
//    graph->edge[7].dest = 0;
//    graph->edge[7].weight = 1;
//
//    graph->edge[8].src = 4;
//    graph->edge[8].dest = 2;
//    graph->edge[8].weight = -1;
//
//    BellmanFord(graph, 0);
//
//    return 0;
//}


//사이클 있는경우
//int main()
//{
//    int V = 5;  // 정점의 수
//    int E = 9;  // 간선의 수
//    struct Graph* graph = createGraph(V, E);
//
//    // 그래프 정보를 입력해준다.
//    graph->edge[0].src = 0; // 0에서 
//    graph->edge[0].dest = 1; // 1로 가는 간선의
//    graph->edge[0].weight = -2; // 가중치는 -2로 정한다.
//
//    graph->edge[1].src = 0;
//    graph->edge[1].dest = 2;
//    graph->edge[1].weight = 5;
//
//    graph->edge[2].src = 0;
//    graph->edge[2].dest = 3;
//    graph->edge[2].weight = 3;
//
//    graph->edge[3].src = 1;
//    graph->edge[3].dest = 0;
//    graph->edge[3].weight = -2;
//
//    graph->edge[4].src = 1;
//    graph->edge[4].dest = 4;
//    graph->edge[4].weight = 4;
//
//    graph->edge[5].src = 3;
//    graph->edge[5].dest = 1;
//    graph->edge[5].weight = 3;
//
//    graph->edge[6].src = 4;
//    graph->edge[6].dest = 2;
//    graph->edge[6].weight = 1;
//
//    graph->edge[7].src = 4;
//    graph->edge[7].dest = 0;
//    graph->edge[7].weight = 1;
//
//    graph->edge[8].src = 4;
//    graph->edge[8].dest = 3;
//    graph->edge[8].weight = -2;
//
//    BellmanFord(graph, 0);
//
//    return 0;
//}


int main()
{
    int V = 6;  // 정점의 수
    int E = 9;  // 간선의 수
    struct Graph* graph = createGraph(V, E);

    // 그래프 정보를 입력해준다.
    graph->edge[0].src = 0; // 0에서 
    graph->edge[0].dest = 1; // 1로 가는 간선의
    graph->edge[0].weight = 3; // 가중치는 3로 정한다.

    graph->edge[1].src = 0;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 7;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 4;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 5;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 5;
    graph->edge[4].weight = 6;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 3;

    graph->edge[6].src = 5;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = -6;

    graph->edge[7].src = 3;
    graph->edge[7].dest = 5;
    graph->edge[7].weight = 1;

    graph->edge[8].src = 3;
    graph->edge[8].dest = 4;
    graph->edge[8].weight = 9;

    BellmanFord(graph, 0);

    return 0;
}
