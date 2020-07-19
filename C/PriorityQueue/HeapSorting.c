#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200

typedef struct {
	int key;
}element;
typedef struct Heap {
	element heap[MAX_SIZE];
	int heapSize;
}Heap;


Heap* create() {
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h) {
	h->heapSize = 0;
}

void insert_max_heap(Heap* h, element item) {
	int idx;
	idx = ++h->heapSize; 

	while (idx != 1 && item.key > h->heap[idx / 2].key) {
		h->heap[idx].key = h->heap[idx / 2].key;
		idx /= 2;
	}
	h->heap[idx].key = item.key;
}

element delete_max_heap(Heap* h) {
	int parentIdx, childIdx;
	element temp, item;
	item = h->heap[1];  //root 저장
	temp = h->heap[h->heapSize--]; //마지막 node 맨위에서 
	parentIdx = 1;
	childIdx = 2;
	while (childIdx <= h->heapSize) {
		if (h->heap[childIdx].key < h->heap[childIdx+1].key) {
			childIdx++;
		}
		if (temp.key >= h->heap[childIdx].key) {
			break;
		}
		h->heap[parentIdx] = h->heap[childIdx];
		parentIdx = childIdx;
		childIdx *= 2;
	}

	h->heap[parentIdx] = temp;
	return item;
}

void heap_sort(element a[], int size) {
	int i;
	Heap* h;
	h = create();
	init(h);
	/*step1.정렬안된 배열은 Max Heap에 넣는다.*/
	for (i = 0; i < size; i++) {
		insert_max_heap(h, a[i]);
	}
	/*step2. Max Heap 에서 하나씩 빼서 배열에 넣는다.*/
	for (i = (size - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}

#define SIZE 8
int main() {
	element list[SIZE] = { 23,56,11,9,56,99,27,4 };
	heap_sort(list, SIZE);
	
	printf("\n\n");
	for (int i = 0; i < SIZE; i++) {
		printf("[%d]\t", list[i].key);
	}
	printf("\n\n");
	return 0;
}

