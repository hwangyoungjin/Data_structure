#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200

typedef struct element {
	int id; // ��� number
	int avail; // ��谡 ��밡���ϰ� �Ǵ� �ð�
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

/*������ + 1 node ���� ���� �ö󰣴�.*/
void insert_min_heap(Heap* h, element item) {
	int idx = ++h->heap_size; // item�� �� idex

	/*������ +1 node���� ����, index�� 1�̰ų� item�� �θ𺸴� Ŭ������ �ݺ�*/
	while (idx != 1 && item.avail < h->heap[idx / 2].avail) {
		/*item�� ������ +1 node �θ� ���� �������*/

		h->heap[idx] = h->heap[idx / 2]; // �ڽ���ġ�� �θ� ������
		idx /= 2; // index ����
	}
	h->heap[idx] = item; // ���̻� �ö� �� ������ item ����

}

/*root���� ������*/
element delete_min_heap(Heap* h) {
	int parentIdx, childIdx;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size--];
	parentIdx = 1; // ���߿� ������ node�� �� idx
	childIdx = 2; // temp �� ��ġ �Ǵܿ�
	while (childIdx <= h->heap_size) { // ������ node���� �ݺ�
		/*�����߿� ���� �� ����*/
		if (childIdx < h->heap_size && h->heap[childIdx].avail > h->heap[childIdx + 1].avail) {
			childIdx++;
		}
		/*�����߿� �������� ������ node���� ũ�� stop*/
		if (temp.avail < h->heap[childIdx].avail) {
			break;
		}
		
		/*min heap���� �ڽ��� �� �����Ƿ� change */
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
	/*jobs�� �̸� ���ĵǾ� �ִٰ� ����*/
	int jobs[JOBS] = {8,7,6,5,3,2,1}; // �۾� �ҿ� �ð� 
	element m = { 0,0 }; 
	Heap* h = create();
	init(h);
	/*avail ��谡 ��밡���ϰ� �Ǵ� �ð� �ʱ�ȭ*/
	for (int i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}

	/*min Heap���� ��踦 ������ �۾��� �Ҵ��ϰ� ��밡�� �ð��� ����*/
	/*�� �� �ٽ� min Heap�� �߰�*/
	for (int i = 0; i <  JOBS; i++) {
		m = delete_min_heap(h);
		printf("\nJOB %d��  %d �� ���� %d �ñ��� ��� %d���� �Ҵ�\n", i + 1, m.avail, m.avail + jobs[i] , m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}

	return 0;
}