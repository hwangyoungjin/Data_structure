#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

/*��ȯ�� Ž��*/
TreeNode* search(TreeNode* node, int key); //O(h)

/*node ����*/
TreeNode* new_node(int item); 

/*��ȯ*/
TreeNode* insert_node(TreeNode* node, int key); //O(h)

/*�ݺ� - root�� min�� ���ϱ� : delete �ڽ� node 2���϶� ���*/
TreeNode* min_value(TreeNode* node);

/*��ȸ - key ���� �ش��ϴ� node�� ���� root ��ȯ */
TreeNode* delete_node(TreeNode* root, int key); //O(h)



/*��ȸ*/
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
		printf("����Ž��Ʈ������ 40 �߰�\n");
	}
	else {
		printf("����Ž��Ʈ������ 40 �߰߸���\n");
	}
	delete_node(root, 40);
	if (search(root, 40) != NULL) {
		printf("����Ž��Ʈ������ 40 �߰�\n");
	}
	else {
		printf("����Ž��Ʈ������ 40 �߰߸���\n");
	}
	return 0;
}

/*��ȯ�� Ž��*/
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

/*��ȸ*/
TreeNode* insert_node(TreeNode* node, int key) { //O(h)
	//Ʈ���� �����̸� ���ο� node ��ȯ
	if (node == NULL) {
		return new_node(key);
	}

	//������ �ƴϸ� �Ʒ��� down
	if (key < node->key) { // node�� ��������
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) { // node�� ����������
		node->right = insert_node(node->right, key);
	}

	//����� ��Ʈ ������ ��ȯ
	return node;
}

TreeNode* min_value(TreeNode* node) {
	TreeNode* current = node;
	//�� ���� �ܸ� ��� ã��
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

/*key ���� �ش��ϴ� node�� ���� root ��ȯ - ��ȸ*/
TreeNode* delete_node(TreeNode* root, int key) { //O(h)
	if (root == NULL) {
		return root;
	}

	/*�̵� ����*/
	/*key�� root->key���� ������ �������� �̵�*/
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	/*key�� root->key���� ũ�� ���������� �̵�*/
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}

	/*�������� ���� code*/
	/*key�� root->key�� ���� ��Ȳ*/
	else {
		/*�����ϴ� node�� �ܸ�node or �ڽ��� 1���� node�� ��� */
		if (root->left == NULL) {  // ������ NULL�̸� ������ node�� ��ȯ
			TreeNode* temp = root->right; // �ܸ� node�̸� null ��ȯ
			free(root);
			return temp; //�θ��忡�� �� ��Ȳ�̹Ƿ� �θ��忡 �ٿ��ֱ� ���� ��ȯ
		}
		else if (root->right == NULL) { // �������� NULL�̸� ���� node�� ��ȯ
			TreeNode* temp = root->left; // �ܸ� node�̸� null ��ȯ
			free(root);
			return temp;
		}

		/*�����ϴ� node �� �ڽ��� 2���� ��Ȳ*/
		TreeNode* temp = min_value(root->right); //�������� �� ���� ���� �޾Ƽ�
		root->key = temp->key; // root�� ket ���� �����ϰ�

		//root �����ʿ� �� ���ʰ��� �ܸ���� �̹Ƿ� delete�������� ����
		root->right = delete_node(root->right, temp->key);
	}

	/*�����Ų �� ��ȯ*/
	return root;
}