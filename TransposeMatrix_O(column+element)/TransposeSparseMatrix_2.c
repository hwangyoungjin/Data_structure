#include <stdio.h>
/*transpose Matrix*/
/*fase transpose O(column + element) */

typedef struct {
	int row;
	int column;
	int value;
}term;

void fastTranspose(term a[], term b[]) {
	int row_term[100];
	int starting_pos[100];
	int i, j;
	int num_cols = a[0].column;
	int num_term = a[0].value;
	b[0].row = a[0].column;
	b[0].column = a[0].row;
	b[0].value = a[0].value;
	if (a[0].value > 0) {
		for (i = 0; i < a[0].column; i++) {
			row_term[i] = 0;
		}
		for (i = 1; i <= a[0].value; i++) {
			// count number of index
			// if a[i].col == 0, increase row_Term[0] += 1
			row_term[a[i].column]++;
		}
		starting_pos[0] = 1;
		for (i = 1; i <= a[0].value; i++) {
			starting_pos[i] = starting_pos[i - 1] + row_term[i - 1];
		}
		for (i = 1; i <= a[0].value; i++) {
			j = starting_pos[a[i].column]++;
			b[j].row = a[i].column;
			b[j].column = a[i].row;
			b[j].value = a[i].value;
		}
	}

}

int main() {
	term a[100] = {
		{5,5,6}, // 5x5 , value 6��
		{0,0,1}, // 1��1�� value = 1
		{0,1,3}, // 1��2�� value = 3
		{1,4,7}, // 2��4�� value = 7
		{2,0,23}, // 3��1�� value = 23
		{4,2,2}, // 5��3�� value = 2
		{4,4,2} // 5��5�� value = 2
	};
	term b[100];
	int i, j;

	printf("���� ��: %d, ���� ��: %d, 0�� �ƴ� ���� ��: %d\n", a[0].row, a[0].column, a[0].value);

	for (i = 1; i < 7; i++) {
		printf("��: %d, ��: %d, ��: %d\n", a[i].row, a[i].column, a[i].value);
	}
	printf("\n\n");

	fastTranspose(a, b);

	printf("Fast Transpose processing has been finished.\n");
	printf("\n\n");


	printf("���� ��: %d, ���� ��: %d, 0�� �ƴ� ���� ��: %d\n", b[0].row, b[0].column, b[0].value);

	for (i = 1; i < 7; i++) {
		printf("��: %d, ��: %d, ��: %d\n", b[i].row, b[i].column, b[i].value);
	}
	printf("\n\n");

	return 0;
}