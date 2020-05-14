#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

/*순환적 탐색*/
TreeNode* search(TreeNode* node, int key); //O(h)

/*node 생성*/
TreeNode* new_node(int item); 

/*순환*/
TreeNode* insert_node(TreeNode* node, int key); //O(h)

/*반복 - root의 min값 구하기 : delete 자식 node 2개일때 사용*/
TreeNode* min_value(TreeNode* node);

/*순회 - key 값의 해당하는 node를 삭제 root 반환 */
TreeNode* delete_node(TreeNode* root, int key); //O(h)



/*순회*/
void in_order(TreeNode* node) {
	if (node == NULL) {
		return;
	}
	else {
		in_order(node->left);
		printf("[%d]  ", node->key);
		in_order(node->right);
	}
}
int main() {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	root = insert_node(root, 35);
	root = insert_node(root, 45);

	printf("\nBinary search Tree Travalsal result\n");
	in_order(root);
	printf("\n\n");
	if (search(root, 40) != NULL) {
		printf("이진탐색트리에서 40 발견\n");
	}
	else {
		printf("이진탐색트리에서 40 발견못함\n");
	}
	delete_node(root, 40);
	if (search(root, 40) != NULL) {
		printf("이진탐색트리에서 40 발견\n");
	}
	else {
		printf("이진탐색트리에서 40 발견못함\n");
	}
	return 0;
}

/*순환적 탐색*/
TreeNode* search(TreeNode* node, int key) { //O(h)
	if (node == NULL) {
		return NULL;
	}
	if (key == node->key) {
		return node;
	}
	else if (key < node->key) {
		search(node->left, key);
	}
	else {
		search(node->right, key);
	}
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

/*순회*/
TreeNode* insert_node(TreeNode* node, int key) { //O(h)
	//트리가 공백이면 새로운 node 반환
	if (node == NULL) {
		return new_node(key);
	}

	//공백이 아니면 아래로 down
	if (key < node->key) { // node의 왼쪽으로
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) { // node의 오른쪽으로
		node->right = insert_node(node->right, key);
	}

	//변경된 루트 포인터 반환
	return node;
}

TreeNode* min_value(TreeNode* node) {
	TreeNode* current = node;
	//맨 왼쪽 단말 노드 찾기
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

/*key 값의 해당하는 node를 삭제 root 반환 - 순회*/
TreeNode* delete_node(TreeNode* root, int key) { //O(h)
	if (root == NULL) {
		return root;
	}

	/*이동 구간*/
	/*key가 root->key보다 작으면 왼쪽으로 이동*/
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	/*key가 root->key보다 크면 오른쪽으로 이동*/
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}

	/*실질적인 삭제 code*/
	/*key가 root->key와 같은 상황*/
	else {
		/*삭제하는 node가 단말node or 자식이 1개인 node인 경우 */
		if (root->left == NULL) {  // 왼쪽이 NULL이면 오른쪽 node를 반환
			TreeNode* temp = root->right; // 단말 node이면 null 반환
			free(root);
			return temp; //부모노드에서 온 상황이므로 부모노드에 붙여주기 위해 반환
		}
		else if (root->right == NULL) { // 오른쪽이 NULL이면 왼쪽 node를 반환
			TreeNode* temp = root->left; // 단말 node이면 null 반환
			free(root);
			return temp;
		}

		/*삭제하는 node 가 자식이 2개인 상황*/
		TreeNode* temp = min_value(root->right); //오른쪽의 맨 왼쪽 값을 받아서
		root->key = temp->key; // root에 ket 값을 저장하고

		//root 오른쪽에 맨 왼쪽값은 단말노드 이므로 delete연산으로 삭제
		root->right = delete_node(root->right, temp->key);
	}

	/*연결시킨 후 반환*/
	return root;
}