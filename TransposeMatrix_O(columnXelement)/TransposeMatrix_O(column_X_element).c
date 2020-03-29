#include <stdio.h>
/*Transpose Matrix*/
/* O(colunmn*element) */


typedef struct {
	int row;
	int column;
	int value;
}term;

void Transpose(term a[], term b[]) {
	int i, j, currentb;
	b[0].column = a[0].row;
	b[0].row = a[0].column;
	b[0].value = a[0].value;

	if (a[0].value > 0) {
		currentb = 1;
		for (i = 0; i < a[0].column; i++) {
			for (j = 1; j <= a[0].value; j++) {
				if (a[j].column == i) {
					b[currentb].column = a[j].row;
					b[currentb].row = a[j].column;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}
}


int main() {
	int i, j;
	term a[100] = {
		{5,5,6}, // 5x5 , value 6개
		{0,0,1}, // 0행0열 value = 1
		{0,1,3}, // 0행1열 value = 3
		{1,4,7}, // 1행4열 value = 7
		{2,0,23}, // 2행0열 value = 23
		{4,2,2}, // 4행2열 value = 2
		{5,5,2} // 5행5열 value = 2
	};
	term b[100];


	printf("행의 수: %d, 열의 수: %d, 0이 아닌 항의 수: %d\n", a[0].row, a[0].column, a[0].value);

	for (i = 1; i < 6; i++) {
		printf("행: %d, 열: %d, 값: %d\n", a[i].row, a[i].column, a[i].value);
	}
	printf("\n\n");

	Transpose(a, b);

	printf("Transpose processing has been finished.\n");
	printf("\n\n");


	printf("행의 수: %d, 열의 수: %d, 0이 아닌 항의 수: %d\n", b[0].row, b[0].column, b[0].value);

	for (i = 1; i < 6; i++) {
		printf("행: %d, 열: %d, 값: %d\n", b[i].row, b[i].column, b[i].value);
	}
	printf("\n\n");

	return 0;
}