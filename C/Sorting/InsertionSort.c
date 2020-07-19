#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0
int list[MAX_SIZE];

/*O(n^2)*/
void insertion_sort(int list[], int n) {
	int key,i,j;
	//맨처음 레코드는 정렬됨 
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; ( j >= 0 && key < list[j]); j--) {
			//list[j] 레코드가 key보다 더 크면 해당 레코드 '한칸 뒤로' 이동
 			list[j+1] = list[j];
		}
		//key 안쪽 정렬된 레코드와 비교 끝
		//비교가 끝나고 마지막 들어갈 자리 j에서 
		//j--하고 for문 나오므로 key가 들어갈 자리는 j+1
		list[j+1] = key;
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
	insertion_sort(list, n);
	printf("\n\n정렬 후 \n");
	for (i = 0; i < n; i++) {
		printf("%2d ", list[i]);
	}
	printf("\n\n");
	return 0;
}