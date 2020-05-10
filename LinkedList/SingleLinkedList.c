/*linked list new, add, delete, getNode*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
	int data;
	struct Node* Next;
}Node;

int nodeCount; // head는 0으로

Node* NewNode(int data); // node 생성

/*이중포인터를 사용하는 이유는 head를 가르키는 포인터가 NULL값일 수도 있기 때문*/
void AddNode(Node** head, Node* newNode); // list 끝에 추가

Node* GetNode(Node* head, int index); // index에 해당하는 node 반환
void DeleteNode(Node* head); // list 마지막 node 삭제

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->Next = NULL;
	head->data = 0;

	AddNode(&head, NewNode(3));
	AddNode(&head, NewNode(4));
	AddNode(&head, NewNode(5));
	AddNode(&head, NewNode(6));

	/*print*/
	Node* pNode = NULL;
	for (int i = 1; i <= nodeCount; i++) {
		pNode = GetNode(head, i);
		printf("\nNO.%d Node's data : %d", i, pNode->data);
	}

	DeleteNode(&head);
	DeleteNode(&head);

	printf("\n\n");
	for (int i = 1; i <= nodeCount; i++) {
		pNode = GetNode(head, i);
		printf("\nNO.%d Node's data : %d", i, pNode->data);
	}

	AddNode(&head, NewNode(7));

	printf("\n\n");
	for (int i = 1; i <= nodeCount; i++) {
		pNode = GetNode(head, i);
		printf("\nNO.%d Node's data : %d", i, pNode->data);
	}
	return 0;
}

Node* NewNode(int data) {
	nodeCount++;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->Next = NULL;
	return newNode;
}

void AddNode(Node** head, Node* newNode) {

	/*첫 번째, head에 Node가 없을때*/
	if (*head == NULL) {
		*head = newNode; // 바로 헤드에 연결
		return;
	}
	/*두 번째, 하나라도 노드가 있을때*/
	else {
		/*마지막이 어디인지 확인할 변수 horse 필요*/
		Node* horse = *head;
		while (horse->Next != NULL) {
			horse = horse->Next;
		}
		horse->Next = newNode;
		return;
	}
}

void DeleteNode(Node** head) {

	/*마지막 어디인지 확인하고 FREE 할 변수 horse*/
	Node* horse = NULL;

	/*마지막-1 번째 node->Next = NULL*/
	Node* beforeNode = NULL;

	if (*head == NULL) { // node가 하나도 없을때
		return;
	}
	else {
		horse = *head;
		while (horse->Next != NULL) {
			beforeNode = horse;
			horse = horse->Next;
		}
		beforeNode->Next = NULL;
		free(horse);
		nodeCount--;
		return;
	}
}

Node* GetNode(Node* head, int index) { // index번째의 node를 반환
	Node* horse = head;
	for (int i = 1; i <= index; i++) {
		horse = horse->Next;
	}
	return horse;
}