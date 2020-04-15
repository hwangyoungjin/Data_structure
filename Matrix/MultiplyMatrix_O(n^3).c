
#include <stdio.h>

void multiplyMartrices(int a[][3], int b[][3], int c[][3]);

int main() {
	int a[3][3] = {
		{1,0,0},
		{2,3,0},
		{4,5,6}
	};
	int b[3][3] = {
		{0,0,1},
		{0,2,3},
		{4,5,6}
	};
	int c[3][3]= {
		{ 0,0,0 },
		{ 0,0,0 },
		{ 0,0,0 }
	};

	printf("20186757 Hwang Young Jin\n\n");


	printf("\n\n");
	printf("MultiplyMartrices\n\n");
	multiplyMartrices(a,b,c);

	for (int i = 0; i < sizeof(a[0]) / sizeof(int); i++) {
		for (int j = 0; j < sizeof(b) / sizeof(b[0]); j++) {
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void multiplyMartrices(int a[][3], int b[][3], int c[][3]) {
	
	int i = sizeof(a[0]) / sizeof(a[0][0]); // 12/4 = 3 : row_pos
	int j = sizeof(b) / sizeof(b[0]); // 36/12 = 3 : column_pos
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}