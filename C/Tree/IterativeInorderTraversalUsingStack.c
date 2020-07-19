#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* node) {
	if (top == SIZE - 1) {
		return;
	}
	else {
		stack[++top] = node;
	}
}
TreeNode* pop() {
	if (top < 0) {
		return NULL;
	}
	else {
		return stack[top--];
	}
}

void inOrder(TreeNode* root) {
	while (1) {
		while(root != NULL) { //계속 왼쪽으로 이동
			push(root);
			root = root->left;
		}
		root = pop(); // null 만나면 pop
		if (root==NULL) { // pop이 NULL이면 더이상 node 없으므로 break; 
			break;
		}
		printf("%d  ", root->data);
		root = root->right;
	}
}


/*
			15
		4		20
	   1	   16 25
*/

int main() {
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,&n1,NULL };
	TreeNode n3 = { 16,NULL,NULL };
	TreeNode n4 = { 25,NULL,NULL };
	TreeNode n5 = { 20,&n3,&n4 };
	TreeNode n6 = { 15,&n2,&n5 };
	TreeNode* root = &n6;

	inOrder(root);

}
