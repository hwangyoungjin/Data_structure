#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 5

int IsEmpty(); // return true iff stack is empty
int IsFull(); // return true iff stack has no remaining capacity
int Top(); //return top element to the top of the stack
void Push(int element); // add an element to the top of the stack
void Pop(); //delete the top element of the stack
void StackFull(); //double capacity 


int capacity = MAX;
int stackarr[MAX] = { 0, }; // array init '0'
int* pStackarr = stackarr; 
int top = -1;


int main() {
	

	Push(5);
	printf("%d\n", Top());
	Push(4);
	printf("%d\n", Top());
	Push(3);
	printf("%d\n", Top());
	Push(2);
	printf("%d\n", Top());
	Push(1);
	printf("%d\n", Top());
	Push(100);

	StackFull();
	Push(100);
	printf("%d\n", Top());
	Push(200);
	printf("%d\n", Top());
	Push(300);
	printf("%d\n", Top());
	Push(400);
	printf("%d\n", Top());
	Push(500);
	printf("%d\n\n", Top());
	int i=0;
	while (i < 10) {
		Pop();
		printf("%d\n", Top());
		i++;
	}


	return 0;
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
	if (top >= capacity - 1) {
		printf("\n Stack is Full \n");
		return TRUE;
	}
	else return FALSE;
}
int Top() { // O(1)
	if (IsEmpty() == TRUE) { exit(0); }
	else {
		printf("\ntop : %d\n", top);
		return pStackarr[top];
	}
	
}
void Push(int element) { // O(1)
	if (IsFull()==TRUE) {
		printf("\nCannot add element\n");
	}
	else {
		pStackarr[++top] = element;
	}
}
void Pop() { // O(1)
	if (IsEmpty() == TRUE) {
		printf("\nCannot delete element\n");
	}
	else {
		top--;
	}
}
void StackFull() { // O(n)
	int* ps=NULL;
	ps=(int*)realloc(ps, 2*capacity*sizeof(*ps)); //sizeof(*pStackarr) = sizeof(int)
	
	pStackarr = ps;
	for (int i = 0; i < capacity; i++) {
		pStackarr[i] = stackarr[i];
	}

	capacity *= 2;

	printf("\nStack capacity doubling\n");
}