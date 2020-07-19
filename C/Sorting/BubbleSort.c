#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

int list[MAX_SIZE];

void bubble_sort(int list[], int n) {
	int i, j,temp;
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j + 1] < list[j]) {
				temp = list[j + 1];
				list[j + 1] = list[j];
				list[j] = temp;
			}
		}
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
	bubble_sort(list, n);
	printf("\n\n정렬 후 \n");
	for (i = 0; i < n; i++) {
		printf("%2d ", list[i]);
	}
	printf("\n\n");
	return 0;
}