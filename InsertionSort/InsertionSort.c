#include <stdio.h>

void insertion_sort(int list[], int n) { // 작은수 앞에서 부터 이동
	int i;
	int key;
	for (i = 1; i < n; i++) {
		key = list[i]; // 앞에는 정렬된것으로 간주
		int j; // 앞에 정렬된 수 중 가장 큰 수의 index인 j 는 i-1 부터 조금씩 작아진다.
		for (j = i - 1; j >= 0 && key < list[j]; j--) {
			// j가 0보다 크고, key는 list[j]보다 작으면 정렬안으로 이동할것이다
			// j값은 정렬된 수들 뒤부터 앞으로 가면서 모두 비교할것이므로 j--
			list[j + 1] = list[j];  //즉, 정렬된 놈들중 key보다 큰놈 오른쪽으로 이동
		}

		list[j + 1] = key; // key값은 자기보다 큰놈들 다 뒤로 보내고 자신이 들어갈 위치에 들어간다.
		//모두 비교 완료 후 마지막에 j--이므로 다시 j+1 해준다.
	}
}

int main() {
	int i = 0;
	int n = 5;
	int list[5] = { 8,5,6,2,4 };

	printf("sort  : ");
	insertion_sort(list, n);

	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	return 0;
}