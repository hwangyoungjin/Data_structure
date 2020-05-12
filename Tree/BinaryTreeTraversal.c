#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

/*
			15
		4		20
	   1	   16 25
*/

void preOrder(TreeNode* root);
void inOrder(TreeNode* root);
void postOrder(TreeNode* root);


int main() {
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,&n1,NULL };
	TreeNode n3 = { 16,NULL,NULL };
	TreeNode n4 = { 25,NULL,NULL };
	TreeNode n5 = { 20,&n3, &n4 };
	TreeNode n6 = { 15,&n2,&n5 };
	TreeNode* root = &n6;

	printf("\n\npreOrder start\n");
	preOrder(root);
	printf("\n\ninOrder start\n");
	inOrder(root);
	printf("\n\npostOrder start\n");
	postOrder(root);


	return 0;
}

void preOrder(TreeNode *root) { 
	if (root != NULL) {
		printf("%d  ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(TreeNode* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d  ", root->data);
		inOrder(root->right);
	}
}

void postOrder(TreeNode* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d  ", root->data);
	}

}