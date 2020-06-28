#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef void* Element; //void* 형식을 Element형식 명으로 정의 
//Element는 data*를 받기 때문 
//data가 구조체가 아닌 int형 하나라면 typedef int element로 가능

typedef struct Data { 
	int num;
	char* name;
}Data;

typedef struct Stack {
	Element* buf; //buf는 모든 데이터를 가리키는 포인터이어야 한다.
	// buf는 extend에 의해 계속 커진다.
	int ssize;
	int top;
}Stack;





int IsEmpty(Stack* stack); // return true iff stack is empty
int IsFull(Stack* stack); // return true iff stack has no remaining capacity
void Expand(Stack* stack); // stack IsFull == true인 경우 buf 확장
void Push(Stack* stack, Element data); // add an element to the top of the stack
Element Pop(Stack* stack); //return the top element of the stack
void DeleteData(Data* data); //	data 삭제 free(data->name); 에서 왜 오류가 나는지..?
void DeleteStack(Stack* stack); // stack 메모리 반환


Stack* NewStack(); //stack 생성
void InitStack(Stack* stack, int ssize); // stack buf size 1 초기화
Data* NewData(int num, const char* name); // data 생성

void ViewData(Data* data); // data 출력




int main() {
	Data* data = NULL;
	Stack* stack = NewStack(); //stack 동적할당 //size는 1로 초기화
	Push(stack, NewData(3, "Rosa"));
	Push(stack, NewData(5, "John"));
	Push(stack, NewData(1, "Kim"));
	Push(stack, NewData(4, "Hwang"));

	printf("%-5s %-10s\n", "num", "name");
	
	while (!IsEmpty(stack)) { // 스택이 비어있지 않다면 반복
		data = (Data*)Pop(stack);
		ViewData(data);
		DeleteData(data); 
	}
	DeleteStack(stack); 
	return 0;
}
Stack* NewStack() { 
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	InitStack(stack, 1);
	return stack;
}
void InitStack(Stack* stack, int ssize) {  
	stack->buf = (Element*)malloc(sizeof(Element)*ssize); //초기화시 buf도 size만큼 할당필요
	stack->ssize = ssize;
	stack->top = -1;
}

void DeleteStack(Stack*stack) {
	free(stack->buf);
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
	stack->buf[++stack->top] = data;
}
Element Pop(Stack *stack) {
	Element re = 0;
	if (IsEmpty(stack)) {
		printf("Empty stack!");
		return re;
	}
	return stack->buf[stack->top--];
}
void Expand(Stack* stack) {
	stack->ssize *= 2;
	stack->buf = (Element*)realloc(stack->buf, sizeof(Element) * stack->ssize); 
	//relloc의 반환타입은 void*이므로 형변환해주어야 한다.
	//buf에 사이즈를 2배 증가
}

Data* NewData(int num, const char* name) {  // name의 값 변경 불가
	Data* data = (Data*)malloc(sizeof(Data));
	data->num = num;
	data->name = (char*)malloc(strlen(name)+1); 
	strcpy_s(data->name, strlen(name) + 1, name);
	return data;
}

void DeleteData(Data* data) {
	free(data->name); 
	free(data);
}
void ViewData(Data* data) {
	printf("%-5d %-10s\n", data->num, data->name);
}
