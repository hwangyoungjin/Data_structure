#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

/*Check Sparse Matrix*/
/*Sparse Matrix Fomula is ( T >= (row)*(column)/2 ) */
/*T is 0 in total*/
int main() {
	int i; // row
	int j; // column
	int rows = 0, colums = 0;
	int Total = 0;

	printf("\n Please Enter Number of rows and columns : ");
	scanf("%d %d", &i, &j);

	int** a = malloc(sizeof(int*) * rows);
	for (rows = 0; rows < i; rows++) {
		a[rows] = malloc(sizeof(int) * j);
	}

	printf("\n Please Enter Number of Matrix Elements \n");
	for (rows = 0; rows < i; rows++) {
		for (colums = 0; colums < j; colums++) {
			scanf("%d", &a[rows][colums]);
		}
	}

	for (rows = 0; rows < i; rows++) {
		for (colums = 0; colums < j; colums++) {
			if (a[rows][colums] == 0) {
				Total += 1;
			}
		}
	}
	if (Total >= i * j / 2) {
		printf("\n The Matrix that you entered is a Sparse Matrix");
	}
	else {
		printf("\n The Matrix that you entered is Not a Sparse Matrix");
	}

	return 0;
}