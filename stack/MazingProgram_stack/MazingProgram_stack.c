#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 300
#define EXIT_ROW 12
#define EXIT_COL 15
#define START_POINT 2
#define PLAYER 2
#define STOP 9
#define END_POINT 0


typedef struct offset { // �� ���⿡ ���� �̵� �迭
	short int vert; //����
	short int horiz; //����
}offset;

offset move[8] = { // 8 ���� ������ ���� Position index
{.vert = -1, .horiz = 0}, //N
{.vert = -1, .horiz = 1}, //NE
{.vert = 0, .horiz = 1}, //E
{.vert = 1, .horiz = 1}, //SE
{.vert = 1, .horiz = 0}, //S
{.vert = 1, .horiz = -1}, //SW
{.vert = 0, .horiz = -1}, //W
{.vert = -1, .horiz = -1 } // NW
};

typedef struct element { // ���� row,col,dir
	short int row; 
	short int col;
	short int dir; 
}element;
element stack[MAX] = { 0, };
int top = -1;

// ��� ǥ�ÿ� �迭 ('0' ���� initial) 
//-> �湮����ġ == 1 (BACKTACKED)
//-> ���� ������ == 0
int mark[14][17] = { 
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
	{1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
	{1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
	{1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
	{1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
	{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
	{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
	{1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
	{1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
	{1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
	{1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

short maze[14][17] = {
	{5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6},
	{3,START_POINT,1,0,0,0,1,1,0,0,0,1,1,1,1,1,3},
	{3,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,3},
	{3,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,3},
	{3,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,3},
	{3,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,3},
	{3,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,3},
	{3,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,3},
	{3,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,3},
	{3,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,3},
	{3,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,3},
	{3,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,3},
	{3,0,1,0,0,1,1,1,1,1,0,1,1,1,1,END_POINT,3},
	{7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8}
};

int IsEmpty(); // return true iff stack is empty
int IsFull(); // return true iff stack has no remaining capacity
void Push(element position); // add an element to the top of the stack
element Pop(); //delete the top element of the stack and return element of top
void mazeOutput(); // maze print
void path(void); // Get Directions

int main() {
	printf("\n20186757 Hwang Young Jin\n");
	mazeOutput();
	int choice;
	printf("\nChoice : ");
	scanf_s("%d", &choice);
	switch (choice) {
	case 1: 
	{
		mazeOutput();
		break;
	}
	case 2:
		path();
		break;
	case 0:
		exit(0);
	}
	return 0;
}

void mazeOutput() {
	for (int i = 0; i < 14; i++) {
		{
			printf("\n");
			for (int j = 0; j < 17; j++) {
				switch (maze[i][j]) {
				case 0:
					printf("  ");
					break;
				case 1:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("����");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
				default:
					break;
				}
			}
		}
	}
	printf("\n ------------------------------");
	printf("\n - 1. Search a maze           -");
	printf("\n - 2. Print a successful path -");
	printf("\n - 0. Quit this program       -");
	printf("\n ------------------------------");

}

void path(void) { // ����ã�� ���
	int i, row, col;
	int nextRow=0, nextCol=0; // ���� ��ġ
	int dir; // ����
	int found = FALSE;
	element curPosition; // ���� ��ġ element
	mark[1][1] = 1;
	top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 0; //ó�� Pop�� ���� ����

	//Ȯ�ο� : printf("\ncheck 1 top : %d\n", top);
	
	while (top > -1 && !found) { // stack is not empty and found exit 
		
		curPosition = Pop(); // ���̻� �� ���� ������ ������ �ִ� ������ ���ư���
		row = curPosition.row;
		col = curPosition.col;
		dir = curPosition.dir;   // 0~div(ex.2) �˻糡, div+1(ex.3) ���� �ٽ� 7���� �˻�


		while (dir < 8 && !found) { 
			/*dir �������� 0���� 7���� ������� �˻�*/
				nextRow = row + move[dir].vert; //row position change
				nextCol = col + move[dir].horiz; //col position change
			
				
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) { //found exit
				maze[row][col] = PLAYER;
				maze[EXIT_ROW][EXIT_COL] = PLAYER;
				found = TRUE;
			}

			/* �̵��Ҽ� �����鼭 ���� ������ �������̶�� move*/
			else if (!maze[nextRow][nextCol] && ( !mark[nextRow][nextCol])) { //
	
				/*�̵��� ���̹Ƿ� ���� ��ġ�� ���� ����*/
				curPosition.row = row;
				curPosition.col = col;
				curPosition.dir = ++dir; 
				
				
				Push(curPosition);
				
				/*�湮�� ��ġ*/
				row = nextRow;
				col = nextCol;

				/*�湮 �Ϸ������� �湮�Ѱ� 1 ���� ���� ���� �ٽ� 0*/
				mark[curPosition.row][curPosition.col] = 1;
				dir = 0;

				/*�湮�Ѱ�ǥ�� -> ������ ��ġ X ��� �ϱ� (cf.pop�ϸ� 0 push�ϸ� ��)*/
				maze[row][col] = STOP;


			}
			/*�̵��� �� ���� ���̰ų� ���� �̹� ���ô� ���̶�� �ٸ���������*/
			else { 
				dir++;
			}
		}//end while2
		
		
		
	}//end while1
	
	
	if (found) {
		mazeOutput();
		printf("\nThe path is : \n");
		printf("row col\n");
		for (i = 0; i <= top; i++) {
			printf("[%2d, %2d]\n", stack[i].row, stack[i].col);
		}
		printf("[%2d, %2d]\n", row, col);
		printf("[%2d, %2d]\n", EXIT_ROW, EXIT_COL);
		printf("successful mazing game! \n\n");
	}
	else {
		printf("\n\nThe maze does not have a path\n\n");
	}
}

int IsEmpty() { // O(1)
	if (top < 0) {
		printf("\n stack is Empty!!\n");
		return TRUE;
	}
	else
		return FALSE;
}
int IsFull() { // O(1)
	if (top == MAX - 1) {
		printf("\n Stack is Full \n");
		return TRUE;
	}
	else return FALSE;
}

void Push(element curPosition) { // O(1)
	if (IsFull() == TRUE) {
		printf("\nCannot add element\n");
	}
	else {
		maze[curPosition.row][curPosition.col] = PLAYER; //��ġ ǥ�� �ϱ�
		top++;
		stack[top].row = curPosition.row;
		stack[top].col = curPosition.col;
		stack[top].dir = curPosition.dir;
	}
}
element Pop() { // O(1)
	if (IsEmpty() == TRUE) {
		printf("\nCannot delete element\n");
	}
	else {
		maze[stack[top].row][stack[top].col] = 0; // ���� ��ġ ǥ�� ���ֱ�
		return stack[top--];
	}
}