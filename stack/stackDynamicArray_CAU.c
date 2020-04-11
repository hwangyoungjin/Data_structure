#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void* Element; //void* 형식을 Element형식 명으로 정의

typedef struct Stack {
	Element* buf;
	int ssize;
	int top;
}Stack;

typedef struct Data {
	int num;
	char* name;
}Data;



int IsEmpty(Stack* stack); // return true iff stack is empty
int IsFull(Stack* stack); // return true iff stack has no remaining capacity
void Push(Stack* stack, Element data); // add an element to the top of the stack
Element Pop(Stack* stack); //delete the top element of the stack


void expand(Stack* stack);
Stack* newStack();
void initStack(Stack* stack, int ssize);
void disposeStack(Stack* stack);
void deleteStack(Stack* stack);
Data* NewData(int num, const char* name);
void deleteData(Data* data);
void viewData(Data* data);




int main(void) {
	Data* data = 0;
	Stack* stack = newStack();
	Push(stack, NewData(3, "Rosa"));
	Push(stack, NewData(5, "John"));
	Push(stack, NewData(1, "Kim"));
	Push(stack, NewData(4, "Hwang"));

	printf("%-5s %-10s\n", "num", "name");
	while (!IsEmpty(stack)) { // 스택이 비어있지 않다면 반복
		data = (Data*)Pop(stack);
		viewData(data);
		deleteData(data); //Delete data
	}
	deleteStack(stack); //Delete stack

	return 0;
}
Stack* newStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	initStack(stack, 1);
	return stack;
}
void initStack(Stack* stack, int ssize) {
	stack->buf = (Element*)malloc(sizeof(Element)* ssize);
	stack->ssize = ssize;
	stack->top = -1;
}
void disposeStack(Stack* stack) {
	free(stack->buf);
}
void deleteStack(Stack*stack) {
	disposeStack(stack);
	free(stack);

}
int IsEmpty(Stack* stack) {
	return stack->top == -1; 
}

int IsFull(Stack *stack) {
	return (stack->top + 1) == stack->ssize;
}
void Push(Stack *stack, Element data) {
	if (IsFull(stack)) {
		expand(stack);
	}
	stack->top++;
	stack->buf[stack->top] = data;
}
Element Pop(Stack *stack) {
	Element re = 0;
	if (IsEmpty(stack)) {
		printf("Empty stack!");
		return re;
	}
	re = stack->buf[stack->top];
	stack->top--;
	return re;
}
void expand(Stack* stack) {
	stack->ssize * 2;
	stack->buf = (Element*)realloc(stack->buf, sizeof(Element) * stack->ssize);
}

/////////////////////////////////////////////////////////////////
Data* NewData(int num, const char* name) { //?????????????????????????????????????????/////////////////
	Data* data = (Data*)malloc(sizeof(Data));
	data->num = num;
	data->name = (char*)malloc(strlen(name));
	strcpy_s(data->name, strlen(name) + 1, name);
	return data;
}
//////////////////////////////////////////////////////////////

void deleteData(Data* data) {
	free(data->name);
	free(data);
}
void viewData(Data* data) {
	printf("%-5d %-10s\n", data->num, data->name);
}
