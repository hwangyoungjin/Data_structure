#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct element {
	int studentNum;
	char name[10];
	char address[20];
}element;

typedef struct Stack {
	int top;
	element stackArr[MAX_SIZE];
}Stack;


Stack stack;

void init(Stack* stack) {
	stack->top = -1;
}

int isEmpty(Stack* stack) {
	if (stack->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(Stack* stack) {
	if (stack->top == MAX_SIZE - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

//item 넣기
void push(element item, Stack* stack) {
	if (isFull(stack)) { // stack이 가득찼다면
		printf("\nstack is Full!");
		return;
	}
	else { // 가득차지 않았다면
		stack->stackArr[++stack->top] = item;
		return;
	}
}

//item 빼고 삭제
element pop(Stack* stack) {
	if (isEmpty(stack)) { //stack이 비었다면
		printf("\nstack is Empty!!");
	}
	else {
		return stack->stackArr[stack->top--];
	}
}

//item 빼기만 하기
element peek(Stack* stack) {
	if (isEmpty(stack)) { //stack이 비었다면
		printf("\nstack is Empty!!");
	}
	else {
		return stack->stackArr[stack->top];
	}
}


int main() {

	init(&stack);
	element e = { 10,"young","nowon" };
	element e1 = { 16,"young123","nowon2" };
	element e2= { 7,"234235","n352623" };

	push(e,&stack);
	push(e1, &stack);
	push(e2, &stack);
	element e3, e4, e5;
	e3 = pop(&stack);
	e4 = pop(&stack);
	e5 = pop(&stack);

	printf("\n");
	printf("\npop : %d, %s, %s\n", e3.studentNum, e3.name, e3.address);
	printf("\npop : %d, %s, %s\n", e4.studentNum, e4.name, e4.address);
	printf("\npop : %d, %s, %s\n", e5.studentNum, e5.name, e5.address);
	printf("\n");
	return 0;
}