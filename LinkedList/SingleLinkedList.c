/*linked list new, add, delete, getNode*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
	int data;
	struct Node* Next;
}Node;

int nodeCount; // head�� 0����

Node* NewNode(int data); // node ����

/*���������͸� ����ϴ� ������ head�� ����Ű�� �����Ͱ� NULL���� ���� �ֱ� ����*/
void AddNode(Node** head, Node* newNode); // list ���� �߰�

Node* GetNode(Node* head, int index); // index�� �ش��ϴ� node ��ȯ
void DeleteNode(Node* head); // list ������ node ����

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

	/*ù ��°, head�� Node�� ������*/
	if (*head == NULL) {
		*head = newNode; // �ٷ� ��忡 ����
		return;
	}
	/*�� ��°, �ϳ��� ��尡 ������*/
	else {
		/*�������� ������� Ȯ���� ���� horse �ʿ�*/
		Node* horse = *head;
		while (horse->Next != NULL) {
			horse = horse->Next;
		}
		horse->Next = newNode;
		return;
	}
}

void DeleteNode(Node** head) {

	/*������ ������� Ȯ���ϰ� FREE �� ���� horse*/
	Node* horse = NULL;

	/*������-1 ��° node->Next = NULL*/
	Node* beforeNode = NULL;

	if (*head == NULL) { // node�� �ϳ��� ������
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

Node* GetNode(Node* head, int index) { // index��°�� node�� ��ȯ
	Node* horse = head;
	for (int i = 1; i <= index; i++) {
		horse = horse->Next;
	}
	return horse;
}