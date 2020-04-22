#include <stdio.h>
#include <stdlib.h>

/*node*/
typedef struct sNode {
	int data;
	struct sNode* next;
}sNode;

/*structure of queue having two stacks*/
typedef struct queue {
	struct sNode* stack1; //push
	struct sNode* stack2; //pop
}queue;

/*Function to push an item to stack*/
void push(sNode** top_ref, int new_data);

/*Function to pop an item from stack*/
int pop(sNode** top_ref);

/*Function to insertion an item to queue*/
void insertion(queue* q, int x);

/*Function to deletion an item from queue*/
int deletion(queue* q);



int main() {
	/*Create a queue wuth item 1 2 3*/
	queue* q = (queue*)malloc(sizeof(queue));
	q->stack1 = NULL; //push
	q->stack2 = NULL; //pop
	insertion(q, 1); //push(1)
	insertion(q, 2); //push(2)
	insertion(q, 3); //push(3)

	/*deletion item*/
	printf("%d ", deletion(q));
	printf("%d ", deletion(q));
	printf("%d ", deletion(q));

	return 0;
}

void insertion(queue* q, int x) {
	push(&q->stack1, x);
}

int deletion(queue* q) {
	int x;
	/*If both stacks are empty then error*/
	if (q->stack1 == NULL && q->stack2 == NULL) {
		printf("Q is empty");
		getchar();
		exit(0);
	}
	/*Move elements from stack1 to stack2 only if stack2 is empty*/
	if (q->stack2 == NULL) {
		while (q->stack1 != NULL) {
			x = pop(&q->stack1); // pop element of stack1
			push(&q->stack2, x); // push element of stack2
		}
	}
	x = pop(&q->stack2);
	return x;
}

void push(sNode** top_ref, int new_data) {
	/*allocate node*/
	sNode* new_node = (sNode*)malloc(sizeof(sNode)); //sizeof(sNode) = 8
	if (new_node == NULL) {
		printf("Stack overflow\n");
		getchar();
		exit(0);
	}
	/*put in the data*/
	new_node->data = new_data;
	/*link the old list off the new node*/
	new_node->next = (*top_ref);
	/*move the head to point to the new node*/
	(*top_ref) = new_node;
}

int pop(sNode** top_ref) {
	int res;
	sNode* top;
	/*If stack is empty then error*/
	if (*top_ref == NULL) {
		printf("Stack underflow \n");
		getchar(); // null delete
		exit(0);
	}
	else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}


