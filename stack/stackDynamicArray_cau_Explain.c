#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Element;

typedef struct Stack {
	void** buf;
	int ssize;
	int top;
}Stack;

typedef struct Data {
	int num;
	char* name;
}Data;

int main() {

	// stack 생성
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->buf = (void**)malloc(sizeof(void*) * 1);

	// data1생성
	Data* data1 = (Data*)malloc(sizeof(Data));
	data1->num = 10;
	char c1[10] = "hwang";
	data1->name = (char*)malloc(strlen(c1)+1);
	strcpy_s(data1->name, strlen(c1) + 1, c1);

	// stack에 data1 넣기
	stack->buf[0] = (Data*)data1;

	// data1출력
	Data* su = (Data*)stack->buf[0];
	printf("%d, %s\n", su->num, su->name);

	// stack 재할당
	realloc(stack->buf, sizeof(void*) * 2);
	//or stack->buf = (void**)realloc(stack->buf,sizeof(void*) * 2);


	// data2생성
	Data* data2 = (Data*)malloc(sizeof(Data));
	data2->num = 20;
	char c2[10] = "youngjin";
	data2->name = (char*)malloc(strlen(c2)+1);
	strcpy_s(data2->name, strlen(c2) + 1, c2);

	//// stack에 data2 넣기
	stack->buf[1] = (Data*)data2;
	Data* su1 = (Data*)stack->buf[1];

	// data2출력
	printf("%d, %s\n", su1->num, su1->name);


	// realloc 후에 buf[0]의 data1 살아있는지 확인하기
	Data* su2 = (Data*)stack->buf[0];
	printf("%d, %s\n", su2->num, su2->name);

	// data1,data2 메모리 반환
	free(data1->name);
	free(data1);

	free(data2->name);
	free(data2);

	//// stack 메모리 반환
	free(stack->buf);
	free(stack);
	return 0;
}


