#include <stdio.h>
#define MAX 5
#define TRUE 1
#define FALSE 0

typedef struct {
	int stackArr[MAX];
	int top;
}Stack;

void init(Stack* pstack) {
	pstack->top = -1;
}

int IsEmpty(Stack *pstack) {
	if (pstack->top == -1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int IsFull(Stack* pstack) {
	if (pstack->top  >=  MAX-1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void push(Stack* pstack, int value) {
	if (IsFull(pstack) == TRUE) {
		printf("stack Full, cannot add value.\n");
	}
	else {
		pstack->top++;
		pstack->stackArr[pstack->top] = value;
	}
}
void pop(Stack *pstack) {
	if (IsEmpty(pstack) == TRUE) {
		printf("stack Empty!, cannot delete value.\n");
	}
	else {
		pstack->top--;
	}
}
int top(Stack* pstack) {
	if (IsEmpty(pstack) == TRUE) {
		printf("stack Empty!!!!!");
		exit(-1);
	}
	else {
		return pstack->stackArr[pstack->top];
	}
}
int main() {
	Stack stack;
	init(&stack);
	push(&stack, 5); //  top 0
	push(&stack, 4); //  top 1
	push(&stack, 3); //  top 2
	push(&stack, 2); //  top 3 
	push(&stack, 1); //  top 4
	push(&stack, 100); // cannot add

	printf("Top : %d\n", top(&stack));
	pop(&stack); //delete 1, top 3
	printf("Top : %d\n", top(&stack));
	pop(&stack); //delete 2, top 2
	printf("Top : %d\n", top(&stack));
	pop(&stack); //delete 3, top 1
	printf("Top : %d\n", top(&stack));
	pop(&stack); //delete 4, top 0
	printf("Top : %d\n", top(&stack));
	pop(&stack); //delete 5 , top -1

	printf("\nTop of stack : %d\n", stack.top);
	pop(&stack); // cannot delete
	printf("Top : %d\n", top(&stack));

	printf("\n\n");

	return 0;
}