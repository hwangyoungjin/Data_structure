#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key; 
}element;

typedef struct {
	element heap[MAX_ELEMENT]; //heap element�� �迭�� ����
	int heap_size; // node ��
}HeapType;


// ����
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ
void init(HeapType* h) {
	h->heap_size = 0;
}

// ���� ����� ������ heap_size�� ���� h�� item ����
void insert_max_heap(HeapType* h, element item) { // O(logN)
	int i;
	i = ++(h->heap_size);

	//Ʈ���� �Ž��� �ö󰡸鼭 �θ���� ��
	while (i != 1 && item.key > h->heap[i / 2].key) {
		/*������ item �� �θ��� ���� ũ�� i = 1 �� �ƴҶ����� �ݺ�*/
		
		h->heap[i] = h->heap[i / 2];  // �θ� �Ʒ��� down
		i /= 2; // index�� ����
	}

	/*���̻� �ö� �� �����Ƿ� item ����*/
	h->heap[i] = item;
}

// ����
element delete_max_heap(HeapType* h) { // O(logN)
	int parent, child;
	element item, temp; 

	item = h->heap[1]; // root ����
	temp = h->heap[(h->heap_size)--]; // ������ node = ������ node , �ְ� size--
	parent = 1;
	child = 2;

	while (child <= h->heap_size) { // root ���� ���� ������ũ�� ��ŭ �ݺ�

		// ���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ã�´�.
		
		if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key) {
			/*����Ʈ���̹Ƿ� �ڽ� 2���� node�� temp�� ���� ū���� ���� */
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			/*���� temp�� �ش� level�� ���� ū child���� ũ�� stop*/
			break;
		}

		//tqmp�� child ���� �����Ƿ� �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2; // �� level down
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