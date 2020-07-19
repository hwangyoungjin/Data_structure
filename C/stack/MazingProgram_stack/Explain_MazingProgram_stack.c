#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 300
#define EXIT_ROW 12
#define EXIT_COL 15
#define PLAYER 2
#define STOP 9


typedef struct offset { // 각 방향에 대한 이동 배열
	short int vert; //세로
	short int horiz; //가로
}offset;

offset move[8] = { // 8 가지 방향의 대한 Position index
{.vert = -1, .horiz = 0}, //N
{.vert = -1, .horiz = 1}, //NE
{.vert = 0, .horiz = 1}, //E
{.vert = 1, .horiz = 1}, //SE
{.vert = 1, .horiz = 0}, //S
{.vert = 1, .horiz = -1}, //SW
{.vert = 0, .horiz = -1}, //W
{.vert = -1, .horiz = -1 } // NW
};

typedef struct element { // 현재 row,col,dir
	short int row;
	short int col;
	short int dir;
}element;
element stack[MAX] = { 0, };
int top = -1;

// 경로 표시용 배열 ('0' 으로 initial) 
//-> 방문한위치 == 1 (BACKTACKED)
//-> 가지 않은곳 == 0
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

int maze[14][17] = {
	{5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,6},
	{3,PLAYER,1,0,0,0,1,1,0,0,0,1,1,1,1,1,3},
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
	{3,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,3},
	{7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8}
};

int IsEmpty(); // return true iff stack is empty
int IsFull(); // return true iff stack has no remaining capacity
void Push(element position); // add an element to the top of the stack
element Pop(); //delete the top element of the stack
void mazeOutput(); // maze print
void path(void); // 길을찾아 출력
void playerOutput(void); //현재 player 위치

int main() {
	mazeOutput();
	while (1) {
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
					printf("■");
					break;
				case 2:
					printf("옷");
					break;
				case 3:
					printf("│");
					break;
				case 4:
					printf("──");
					break;
				case 5:
					printf("┌");
					break;
				case 6:
					printf("┐");
					break;
				case 7:
					printf("└");
					break;
				case 8:
					printf("┘");
					break;
				case 9:
					printf("Ⅹ");
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

void playerOutput() {
	for (int i = 0; i < 14; i++) {
		{
			printf("\n");
			for (int j = 0; j < 17; j++) {
				switch (maze[i][j]) {
				case 0:
					printf("  ");
					break;
				case 1:
					printf("■");
					break;
				case 2:
					printf("옷");
					break;
				case 3:
					printf("│");
					break;
				case 4:
					printf("──");
					break;
				case 5:
					printf("┌");
					break;
				case 6:
					printf("┐");
					break;
				case 7:
					printf("└");
					break;
				case 8:
					printf("┘");
					break;
				case 9:
					printf("Ⅹ");
					break;
				default:
					break;
				}
			}
		}
	}
}

void path(void) { // 길을찾아 출력
	int i, row, col;
	int nextRow = 0, nextCol = 0; // 다음 위치
	int dir; // 방향
	int found = FALSE;
	element curPosition; // 현재 위치 element
	mark[1][1] = 1;
	top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 0; //처음 Pop을 위해 셋팅

	//확인용 : printf("\ncheck 1 top : %d\n", top);

	while (top > -1 && !found) { // stack is not empty and found exit 
		//확인용 : printf("\nPop call!!!\n");

		curPosition = Pop(); //더이상 갈 곳이 없으니 이전에 있던 곳으로 돌아가기
		row = curPosition.row;
		col = curPosition.col;
		dir = curPosition.dir;   // 0~div(ex.2) 검사끝, 다시 div(ex.2) 부터 다시 7까지 검사


		//stack내부 출력
		//확인용 : 	for (int j = top-1; j > -1 ; j--) {
		//확인용 : 		printf("\n\tstack[%d].row : %d,   stack[%d].col : %d, stack[%d].dir : %d \n",j, stack[j].row,j, stack[j].col,j, stack[j].dir);
		//확인용 :  }

		//확인용 : printf("%d %d %d ", row, col, dir);
		//확인용 : printf("\ncheck 2  top : %d, dir : %d\n",top,dir);


		while (dir < 8 && !found) {  // 
			/*dir 방향으로 0부터 7까지 순서대로 검사*/
			nextRow = row + move[dir].vert; //row position change
			nextCol = col + move[dir].horiz; //col position change

			//확인용 : printf("\ncheck 2-1  top : %d, dir : %d\n", top, dir);


			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) { //출구 도착 found exit
				maze[row][col] = PLAYER;
				maze[EXIT_ROW][EXIT_COL] = PLAYER;
				found = TRUE;
			}

			/* 이동할수 있으면서 내가 가보지 않은곳이라면 move*/
			else if (!maze[nextRow][nextCol] && (!mark[nextRow][nextCol])) { //

				/*이동하는것은 여기 밖에 없다!!!!*/

				//확인용 : printf("nextRow : %d, nextCol : %d\n\n",nextRow,nextCol);

				/*/*이동할 것이므로 현재 위치와 방향 저장*/
				curPosition.row = row;
				curPosition.col = col;
				curPosition.dir = dir; 

				//확인용 : printf("\nPush call!!!\n");

				Push(curPosition);

				//확인용 : printf("after push - cur.row : %d, cur.col : %d, cur dir : %d \n", curPosition.row, curPosition.col, curPosition.dir);

				/*방문할 위치*/
				row = nextRow;
				col = nextCol;
				/*방문 완료했으니 방문한곳 1 고정 놓고 방향 다시 0*/
				mark[curPosition.row][curPosition.col] = 1;
				dir = 0;

				/*방문한곳표시 -> 마지막 위치 X 출력 하기 (cf.pop하면 0 push하면 옷)*/
				maze[row][col] = STOP;

				/*//확인용 : playerOutput(); printf("\n");*/

			}
			/*이동할 수 없는 곳이거나 내가 이미 가봤던 곳이라면 다른방향으로*/
			else {
				dir++;
			}
		}//end while2



	}//end while2


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
	//확인용 : printf("\ncheck 3 top : %d\n", top);
	//확인용 : printf("\ncheck 4  top : %d\n", top);
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
		maze[curPosition.row][curPosition.col] = PLAYER;
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
		//pop을 했다는것은 이전에 갔던곳은 필요 없다는뜻
		maze[stack[top].row][stack[top].col] = 0;
		return stack[top--];
	}
}