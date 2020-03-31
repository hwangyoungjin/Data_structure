#include <stdio.h>
#define MAX 100
/*Transpose Matrix*/
/* O(colunmn*element) */
/*20186757 HwangYoungJin*/
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
	/*
	ex. A matrix
	1  0 3 0 0
	0  0 0 0 7
	23 0 0 0 0
	0  0 0 0 0
	0  0 2 0 2
	*/
	term a[MAX] = {
		{5,5,6},
		{0,0,1},
		{0,1,3},
		{1,4,7},
		{2,0,23},
		{4,2,2},
		{4,4,2}
	};
	term b[MAX];
	int i, j;

	printf("Number of rows: %d, Number of columns: %d, non-zero elements: %d\n", a[0].row, a[0].column, a[0].value);

	for (i = 1; i < 7; i++) {
		printf("row: %d, column: %d, value: %d\n", a[i].row, a[i].column, a[i].value);
	}
	printf("\n\n");

	fastTranspose(a, b);

	printf("Fast Transpose processing has been finished.\n");
	printf("\n\n");

	printf("Number of rows: %d, Number of columns: %d, non-zero elements: %d\n", b[0].row, b[0].column, b[0].value);

	for (i = 1; i < 7; i++) {
		printf("row: %d, column: %d, value: %d\n", b[i].row, b[i].column, b[i].value);
	}
	printf("\n\n");

	return 0;
}