#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct qNode {
	char* Data;
	struct qNode* Next;
}Node;

typedef struct listQueue {
	Node* Front;
	Node* Rear;
	int size;
}listQueue;

/*Operations*/

void EnQ(listQueue* Queue, Node* newNode);  // add an element at the rear of the queue
Node* DeQ(listQueue* Queue); //delete and return the front element of the queue
void createQueue(listQueue** Queue);
Node* createNode(char* Data); 
void deleteQueue(listQueue* Queue);
void deleteNode(Node* removeNode);
Node* Peek(listQueue* Queue); // Only return Queue's front


int main() {
	listQueue* Queue;
	createQueue(&(Queue));

	EnQ(Queue, createNode("a"));
	EnQ(Queue, createNode("b"));
	EnQ(Queue, createNode("c"));
	EnQ(Queue, createNode("d"));
	
	/*who's front?*/
	Node* temp1 = Peek(Queue);

	printf("\n-----Current Queue-----[size : %d]\n\n", Queue->size);
	printf("\nfront is : [%s]\n", Queue->Front->Data);
	printf("\nrear is : [%s]\n", Queue->Rear->Data);

	deleteQueue(Queue);

	return 0;
}

void createQueue(listQueue** Queue) { //Queue initialize
	(*Queue) = (listQueue*)malloc(sizeof(listQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Front = NULL;
	(*Queue)->size = 0;
}

Node* createNode(char* Data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = (char*)malloc(strlen(Data)+1);
	strcpy_s(newNode->Data, strlen(Data) + 1, Data);
	newNode->Next = NULL;
	return newNode;
}

void deleteNode(Node* removeNode) {
	free(removeNode->Data);
	free(removeNode);
}

Node* Peek(listQueue* Queue) { 
	return Queue->Front;
}

/*queue operation*/

void EnQ(listQueue* Queue, Node* newNode) {
	//if queue is empty
	if (Queue->size == 0) {
		Queue->Front = newNode;
		Queue->Rear = newNode;
	}
	else { // Queue Rear is newNode after Rear's next newNode
		Queue->Rear->Next = newNode;  
		Queue->Rear = newNode;

	}
	Queue->size++;
}

Node* DeQ(listQueue* Queue) {
	
	Node* tempNode = Queue->Front;
	if (Queue->size == 0) {
		printf("\nQueue empty!");
		return NULL;
	}
	else if (Queue->size == 1) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
		Queue->size --;
	}
	else {
		Queue->Front = Queue->Front->Next; //ready delete
		Queue->size--;
	}
	return tempNode;
}
void deleteQueue(listQueue* Queue) {
	int count = Queue->size;
	while (count-- != 0) {
		Node* temp = DeQ(Queue);
		printf("goodbye data : %s\n", temp->Data);
		deleteNode(temp);
	}
	free(Queue);
}


