#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key; 
}element;

typedef struct {
	element heap[MAX_ELEMENT]; //heap element를 배열의 저장
	int heap_size; // node 수
}HeapType;


// 생성
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화
void init(HeapType* h) {
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h의 item 삽입
void insert_max_heap(HeapType* h, element item) { // O(logN)
	int i;
	i = ++(h->heap_size);

	//트리를 거슬러 올라가면서 부모노드와 비교
	while (i != 1 && item.key > h->heap[i / 2].key) {
		/*삽입할 item 이 부모노드 보다 크고 i = 1 이 아닐때까지 반복*/
		
		h->heap[i] = h->heap[i / 2];  // 부모를 아래로 down
		i /= 2; // index는 위로
	}

	/*더이상 올라갈 곳 없으므로 item 삽입*/
	h->heap[i] = item;
}

// 삭제
element delete_max_heap(HeapType* h) { // O(logN)
	int parent, child;
	element item, temp; 

	item = h->heap[1]; // root 저장
	temp = h->heap[(h->heap_size)--]; // 움직일 node = 마지막 node , 넣고 size--
	parent = 1;
	child = 2;

	while (child <= h->heap_size) { // root 다음 부터 사이즈크기 만큼 반복

		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key) {
			/*이진트리이므로 자식 2개의 node중 temp와 비교할 큰놈을 선택 */
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			/*비교할 temp가 해당 level의 가장 큰 child보다 크면 stop*/
			break;
		}

		//tqmp가 child 보다 작으므로 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2; // 한 level down
	}

	h->heap[parent] = temp;
	return item;
}

int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create();
	init(heap);

	//insert
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);


	//delete
	e4 = delete_max_heap(heap);
	printf("\n\n< %d >\t", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d >\t", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d >\n\n", e6.key);

	free(heap);
	return 0;
}