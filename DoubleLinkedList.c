#include <stdio.h>
#include <stdlib.h>


typedef struct listNode {
	int date;
	struct listNode* Next;
	struct listNode* Prev;
}Node;

Node* createNode(int data);	
void deleteNode(Node* node);
Node* getNode(Node* head, int index);
int countNode(Node* head);
void addNode(Node** head, Node* newNode); 
void insertNode(Node* current, Node* newNode);
void removeNode(Node** head, Node* remove); 

int main() {
	int i = 0;
	int count = 0;
	//future head
	Node* list = NULL;
	Node* newNode = NULL;
	Node* curr = NULL;
	for (i = 0; i < 5; i++) {
		newNode = createNode(i);
		addNode(&list, newNode);
	}

	//print
	count = countNode(list);
	for (i = 0; i < count; i++) {
		curr = getNode(list, i);
		printf("list[%d] = %d\n",i, curr->date);
	}
	printf("============== 5 Node Created==============\n");

	//insert
	newNode = createNode(99);
	curr = getNode(list, 0);
	insertNode(curr, newNode);

	newNode = createNode(12);
	curr = getNode(list, 4);
	insertNode(curr, newNode);

	//print
	count = countNode(list);
	for (i = 0; i < count; i++) {
		curr = getNode(list, i);
		printf("list[%d] = %d\n", i, curr->date);
	}
	printf("============== 2 Node inserted ==============\n");

	//remove
	newNode = getNode(list, 1);
	removeNode(&list, newNode);
	newNode = getNode(list, 0);
	removeNode(&list, newNode);

	//print
	count = countNode(list);
	for (i = 0; i < count; i++) {
		curr = getNode(list, i);
		printf("list[%d] = %d\n", i, curr->date);
	}
	printf("============== 2 Node removed ==============\n");


	return 0;
}

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	//init
	newNode->date = data;
	newNode->Next= NULL;
	newNode->Prev = NULL;
	return newNode;
}
void deleteNode(Node* node) {
	free(node);
}
Node* getNode(Node* head, int index) {
	Node* horse = head;
	int count = 0;
	while (horse != NULL) {
		if (count++ == index) {
			return horse;
		}
		horse = horse->Next;
	}
	return NULL;
}
int countNode(Node* head) { 
	int count = 0;
	Node* horse = head;
	while (horse != NULL) {
		horse = horse->Next;
		count++;
	}
	return count;
}
void addNode(Node** head, Node* newNode) {
	//no list exists
	if ((*head) == NULL) {
		*head = newNode;
	}
	else {
		Node* horse = *head;
		while (horse->Next != NULL) {
			horse = horse->Next;
		}
		horse->Next = newNode;
		newNode->Prev = horse;
	}
}

void insertNode(Node* current, Node* newNode) {
	//head
	if (current->Next == NULL && current->Prev == NULL) {
		current->Next = newNode;
		newNode->Prev = current;
	}
	//not head
		
	if (current->Next == NULL) { //iff tail
		current->Next = newNode;
		newNode->Prev = current;
		}
	else { // in the middle of 2 Node
		current->Next->Prev = newNode;
		newNode->Prev = current;
		newNode->Next = current->Next;
		current->Next = newNode;
	}
}
void removeNode(Node** head, Node* remove) {
	//head
	if (*head == remove) {
		*head = remove->Next;
	}
	//when remove has next link to go
	if (remove->Next != NULL) {
		remove->Next->Prev = remove->Prev;
	}
	//when remove has prev link to go
	if (remove->Prev != NULL) {
		remove->Prev->Next = remove->Next;
	}
	deleteNode(remove);
}
