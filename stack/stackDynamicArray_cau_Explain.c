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

	// stack ����
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->buf = (void**)malloc(sizeof(void*) * 1);

	// data1����
	Data* data1 = (Data*)malloc(sizeof(Data));
	data1->num = 10;
	char c1[10] = "hwang";
	data1->name = (char*)malloc(strlen(c1)+1);
	strcpy_s(data1->name, strlen(c1) + 1, c1);

	// stack�� data1 �ֱ�
	stack->buf[0] = (Data*)data1;

	// data1���
	Data* su = (Data*)stack->buf[0];
	printf("%d, %s\n", su->num, su->name);

	// stack ���Ҵ�
	realloc(stack->buf, sizeof(void*) * 2);
	//or stack->buf = (void**)realloc(stack->buf,sizeof(void*) * 2);


	// data2����
	Data* data2 = (Data*)malloc(sizeof(Data));
	data2->num = 20;
	char c2[10] = "youngjin";
	data2->name = (char*)malloc(strlen(c2)+1);
	strcpy_s(data2->name, strlen(c2) + 1, c2);

	//// stack�� data2 �ֱ�
	stack->buf[1] = (Data*)data2;
	Data* su1 = (Data*)stack->buf[1];

	// data2���
	printf("%d, %s\n", su1->num, su1->name);


	// realloc �Ŀ� buf[0]�� data1 ����ִ��� Ȯ���ϱ�
	Data* su2 = (Data*)stack->buf[0];
	printf("%d, %s\n", su2->num, su2->name);

	// data1,data2 �޸� ��ȯ
	free(data1->name);
	free(data1);

	free(data2->name);
	free(data2);

	//// stack �޸� ��ȯ
	free(stack->buf);
	free(stack);
	return 0;
}


