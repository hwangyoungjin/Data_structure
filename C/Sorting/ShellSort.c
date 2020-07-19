#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

int list[MAX_SIZE];

/*기존 insertion_sort와 유사*/
void inc_insertion_sort(int list[],int first, int last, int gap) {
	int i, j, key;
	for (i = first+gap; i < last; i += gap) { // 맨앞은 정렬되어 있으므로 first+gap부터
		key = list[i];
		for (j = i - gap; j >= first && key<list[j]; j-=gap) {
			list[j+gap] = list[j];
		}
		list[j + gap] = key;
	}
}

/*평균 O(n^1.5), 최악 O(n^2)*/
void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap >0; gap /= 2) {
		if (gap % 2 == 0) { 
			//연구결과로 간격이 홀수인 경우가 더 빠르다
			gap++;
		}
		for (i = 0; i < n; i++) {
			inc_insertion_sort(list, i, n, gap);
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
	shell_sort(list, n);
	printf("\n\n정렬 후 \n");
	for (i = 0; i < n; i++) {
		printf("%2d ", list[i]);
	}
	printf("\n\n");
	return 0;
}
