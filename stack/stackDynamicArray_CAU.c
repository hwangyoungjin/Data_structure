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


void Expand(Stack* stack); // stack 확장
Stack* NewStack(); //
void InitStack(Stack* stack, int ssize); // 초기화
void DisposeStack(Stack* stack); 
void DeleteStack(Stack* stack);
Data* NewData(int num, const char* name);
void DeleteData(Data* data);
void ViewData(Data* data);




int main(void) {
	Data* data = NULL;
	Stack* stack = NewStack();
	Push(stack, NewData(3, "Rosa"));
	//Push(stack, NewData(5, "John"));
	//Push(stack, NewData(1, "Kim"));
	//Push(stack, NewData(4, "Hwang"));

	printf("%-5s %-10s\n", "num", "name");
	while (!IsEmpty(stack)) { // 스택이 비어있지 않다면 반복
		data = (Data*)Pop(stack);
		ViewData(data);
		DeleteData(data); //Delete data
	}
	DeleteStack(stack); //Delete stack

	return 0;
}
Stack* NewStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	InitStack(stack, 1);
	return stack;
}
void InitStack(Stack* stack, int ssize) {
	stack->buf = (Element*)malloc(sizeof(Element)* ssize);
	stack->ssize = ssize;
	stack->top = -1;
}
void DisposeStack(Stack* stack) {
	free(stack->buf);
}
void DeleteStack(Stack*stack) {
	DisposeStack(stack);
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
		Expand(stack);
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
void Expand(Stack* stack) {
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

void DeleteData(Data* data) {
	free(data->name);
	free(data);
}
void ViewData(Data* data) {
	printf("%-5d %-10s\n", data->num, data->name);
}
