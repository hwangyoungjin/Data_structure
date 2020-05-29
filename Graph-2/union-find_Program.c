#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

/*=====================Union-Find-Algorithm====================*/

int parent[MAX_VERTICES]; //부모노드

/*부모노드(=배열) 초기화*/
void set_init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
}

/*find*/
/*curr이 속하는 집합의 root 반환*/
int set_find(int curr) {
	if (parent[curr] == -1) { // 부모가 없으면
		return curr;
	}
	while (parent[curr] != -1) { // 부모가 없을때까지 반복
		// curr의 부모 index 값 넣어주기
		curr = parent[curr];
	}
	return curr;
}

/*union*/
/*두 원소(a,b)가 속한 집합 합치기*/
/*b가 속한 집합 root2 유지 roo1을 root2에 붙인다.*/
void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2) {
		////최종 root는 root2가 된다.
		parent[root1] = root2;
	}
}
