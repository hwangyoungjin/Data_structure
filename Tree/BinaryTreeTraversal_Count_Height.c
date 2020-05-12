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

void pre_order(TreeNode* root);
void in_order(TreeNode* root);
void post_order(TreeNode* root);

int get_node_count(TreeNode* root);
int get_height(TreeNode* root); //max함수 이용

int main() {
	TreeNode n1 = { 1,NULL,NULL };
	TreeNode n2 = { 4,&n1,NULL };
	TreeNode n3 = { 16,NULL,NULL };
	TreeNode n4 = { 25,NULL,NULL };
	TreeNode n5 = { 20,&n3, &n4 };
	TreeNode n6 = { 15,&n2,&n5 };
	TreeNode* root = &n6;

	printf("\n\nTree의 node 개수 : %d\n", get_node_count(root));
	printf("\n\nTree의 height : %d\n", get_height(root));

	printf("\n\npreOrder start\n");
	pre_order(root);
	printf("\n\ninOrder start\n");
	in_order(root);
	printf("\n\npostOrder start\n");
	post_order(root);
	printf("\n\n");


	return 0;
}

void pre_order(TreeNode *root) {
	if (root != NULL) {
		printf("%d  ",root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(TreeNode* root) {
	if (root != NULL) {
		in_order(root->left);
		printf("%d  ", root->data);
		in_order(root->right);
	}
}

void post_order(TreeNode* root) {
	if (root != NULL) {
		post_order(root->left);
		post_order(root->right);
		printf("%d  ", root->data);
	}

}

int get_node_count(TreeNode* root){
	int count = 0;

	if (root != NULL) {
		count = 1 + get_node_count(root->left) + get_node_count(root->right);
	}
	return count;
}

int get_height(TreeNode* root) {

	int height = 0;

	if (root != NULL) {
		height = 1 + max(get_height(root->left), get_height(root->right));
	}
	return height;

}