#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

int list[MAX_SIZE];

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left; // 왼쪽의 부분리스트를 만드는 index
	high = right + 1; // 오른쪽 부분리스트를 만드는 index
	pivot = list[left]; // 기준은 항상 리스트의 맨 왼쪽 
	do { //low와 high가 교차할때 까지 반복
		do {
			low++; //low는 left+1 부터 시작!
		} while (list[low] < pivot); 
		do {
			high--; //do while 쓰기위해 high는 right+1 했으므로--하고 시작
		} while (list[high] > pivot);
		
		//low는 현재 pivot보다 작은 값의 index
		//high는 현재 pivot보다 큰 값의 index

		if (low < high) { // low와 high 교차하지 않았다면
			// list[low]와 list[high] 값은 
			// 각 리스트에 적합하지않은 값이므로 교환
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low < high); 

	//low와 high가 교차하면 high가 가르키는 데이터와 pivot 교환
	//pivot을 중앙에 위치 시킨다.
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;
	//이때 high값은 pivot의 위치 index 값이므로 해당 값 반환
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		//q는 현재 list에서 pivot을 기준으로 정렬된 배열로 만들고
		//반환되는 pivot의 index 값을 저장
		int q = partition(list, left, right);
		//q는 고정된 위치이므로 부분리스트에서
		//왼쪽 부분리스트는 left~q-1
		//오른쪽 부분리스트는 q+1~right
		quick_sort(list, left, q-1); 
		quick_sort(list, q + 1, right);
	}
}

int main() {

	int i, su;
	int check[100] = { 0, }; // 랜덤 중복 숫자 없애기용
	int	n = MAX_SIZE;
	for (i = 0; i < 100000; i++) {
		su = rand() % 100; //0~99사이의 숫자 랜덤으로 출력
		if (check[su] == FALSE && i < n) {
			check[su] = TRUE;
			list[i] = su;
		}
	}

	printf("\n정렬 전 \n");
	for (i = 0; i < n; i++) {
		printf("%2d ", list[i]);
	}

	quick_sort(list,0,n-1);
		
	printf("\n\n정렬 후 \n");
	for (i = 0; i < n; i++) {
		printf("%2d ", list[i]);
	}
	printf("\n\n");
	return 0;
}