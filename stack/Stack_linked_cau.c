#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node* ptr;
}node;
node* top, * top1, * temp;
//temp is used in push, top1 is used in pop 
int count; //node count 

/*operate*/
int topElement(); //return top element in stack
void push(int data);
void pop();
// void empty();
void display();
void destroy();
// void stackCount();
void create();

int main() {
	create();
	int choice = 0;
	int data = 0;
	while (1) {
		printf("\n\n 1 - Push");
		printf("\n 2 - Pop");
		printf("\n 3 - Top");
		printf("\n 4 - Exit");
		printf("\n 5 - Display");
		printf("\n 6 - Stack Count");
		printf("\n 7 - Destroy Stack");
		printf("\n Enter choice : ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nEnter data : ");
			scanf_s("%d", &data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			printf("%d",topElement());
			break;
		case 4:
			exit(0);
		case 5:
			display();
			break;
		case 6:
			printf("count : %d", count);
			break;
		case 7:
			destroy();
			break;
		}
	}
	return 0;
}

void create() {
	top = NULL;
}

void push(int data) {
	if (top == NULL) { //first node initialize
		top = (node*)malloc(1 * sizeof(node));
		top->ptr = NULL;
		top->info = data;
	}
	else { // node is one or more 
		temp = (node*)malloc(1 * sizeof(node));
		temp->ptr = top;
		temp->info = data;
		top = temp;
	}
	count++;
}

void pop() {
	top1 = top;
	if (top1 == NULL) { //stack is empty
		printf("\nError : Trying to top from empty stack");
	}
	else { // stack has one or more nodes
		top1 = top1->ptr;
		printf("\n Popped value : %d ", top->info);
		top = top1;
		count--;
	}
}

int topElement() {
	return top->info;
}

void destroy() { 
	top1 = top;

	/*stack has one or more nodes*/
	while (top1 != NULL) { 
		top1 = top->ptr; // it is the same as top1->ptr
		free(top);
		top = top1;
		top1 = top1->ptr;
	}
	free(top);
	printf("top->info : %d", top->info);
	top = NULL;
	printf("\n All stack elements destroyed");
	count = 0;
}

void display() {
	node* top2 = top; // down step display
	while (top2 != NULL) {
		printf("%d ", top2->info);
		top2 = top2->ptr;
	}
}