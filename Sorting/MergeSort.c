#include<stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

int list[MAX_SIZE];
int sorted[MAX_SIZE]; // merge 과정에서 추가 공간 필요

void merge(int list[], int left, int  mid, int right) {

	int i, j, k, l;
	i = left; // 앞 배열 시작 index
	j = mid+1; // 뒤 배열 시작 index
	k = left; // merge할 배열 시작 index

	/*분할 정렬된 list merge*/
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}
	if (i > mid) {//뒤 배열 남아있는 레코드 일괄 복사
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
		}
	}
	else { // j > right -> 앞 배열 남아있는 레코드 일괄 복사
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
		}
	}

	/*배열 sorted[]의 리스트를 배열 list[]로 재 복사*/
	for (int l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) { // 크기가 1이상이라면
		mid = (left + right) / 2; // 크기 1이상이므로 divide
		merge_sort(list, left, mid); // 앞부분 배열 정렬
		merge_sort(list, mid+1, right);// 뒷부분 배열 정렬
		merge(list, left, mid, right); // 정렬 된 앞,뒤 배열 merge
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

	merge_sort(list, 0, n-1);

	printf("\n\n정렬 후 \n");
	for (i = 0; i < n; i++) {
		printf("%2d ", list[i]);
	}
	printf("\n\n");
	return 0;
}