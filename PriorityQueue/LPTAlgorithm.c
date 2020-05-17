#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200

typedef struct element {
	int id; // 기계 number
	int avail; // 기계가 사용가능하게 되는 시간
}element;

typedef struct Heap {
	element heap[MAX_SIZE];
	int heap_size;
}Heap;

Heap* create() {
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h) {
	h->heap_size = 0;
}

/*마지막 + 1 node 부터 위로 올라간다.*/
void insert_min_heap(Heap* h, element item) {
	int idx = ++h->heap_size; // item이 들어갈 idex

	/*마지막 +1 node부터 시작, index가 1이거나 item이 부모보다 클때까지 반복*/
	while (idx != 1 && item.avail < h->heap[idx / 2].avail) {
		/*item이 마지막 +1 node 부모 보다 작은경우*/

		h->heap[idx] = h->heap[idx / 2]; // 자식위치에 부모 내리기
		idx /= 2; // index 위로
	}
	h->heap[idx] = item; // 더이상 올라갈 수 없을때 item 저장

}

/*root부터 내려감*/
element delete_min_heap(Heap* h) {
	int parentIdx, childIdx;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size--];
	parentIdx = 1; // 나중에 마지막 node가 들어갈 idx
	childIdx = 2; // temp 들어갈 위치 판단용
	while (childIdx <= h->heap_size) { // 마지막 node까지 반복
		/*형제중에 작은 놈 선택*/
		if (childIdx < h->heap_size && h->heap[childIdx].avail > h->heap[childIdx + 1].avail) {
			childIdx++;
		}
		/*형제중에 작은놈이 마지막 node보다 크면 stop*/
		if (temp.avail < h->heap[childIdx].avail) {
			break;
		}
		
		/*min heap에서 자식이 더 작으므로 change */
		h->heap[parentIdx] = h->heap[childIdx];
		parentIdx = childIdx;
		childIdx *= 2;
	}

	
	h->heap[parentIdx] = temp;
	return item;

}

#define JOBS 7
#define MACHINES 3
int main() {
	/*jobs는 미리 정렬되어 있다고 가정*/
	int jobs[JOBS] = {8,7,6,5,3,2,1}; // 작업 소요 시간 
	element m = { 0,0 }; 
	Heap* h = create();
	init(h);
	/*avail 기계가 사용가능하게 되는 시간 초기화*/
	for (int i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}

	/*min Heap에서 기계를 꺼내서 작업을 할당하고 사용가능 시간을 증가*/
	/*이 후 다시 min Heap에 추가*/
	for (int i = 0; i <  JOBS; i++) {
		m = delete_min_heap(h);
		printf("\nJOB %d을  %d 시 부터 %d 시까지 기계 %d번에 할당\n", i + 1, m.avail, m.avail + jobs[i] , m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}

	return 0;
}