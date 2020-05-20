#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 200

typedef struct element {
	char word[MAX_WORD_LENGTH];
	char mean[MAX_MEAN_LENGTH];
}element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;


/*��ȯ - ã�� ��� ����ϰ� �ش� node ��ȯ*/
TreeNode* searchBST(TreeNode* root, element key); //O(h)

/*node ����*/
void insert_root(TreeNode** root, element key);

/*��ȯ - insert_root()�� ���� ���Ǵ� �Լ� : node �ֱ�*/
TreeNode* insert_key(TreeNode* root, element key); //O(h)

/*�ݺ� - �ش� key ������ node ����*/
void delete_node(TreeNode* root, element key); //O(h)

/*height ���ϱ�*/
int get_tree_height(TreeNode* root);

/*node �� ���ϱ�*/
int get_number_all_node(TreeNode* root);

/*��� node ����*/
TreeNode* delete_all_node(TreeNode* root);

void menu() {
	printf("\n===================");
	printf("\n\t1 : Insert");
	printf("\n\t2 : Delete");
	printf("\n\t3 : Search");
	printf("\n\t4 : Print");
	printf("\n\t5 : Exit");
	printf("\n\t6 : Print height of tree");
	printf("\n\t7 : Output the total number of nodes");
	printf("\n\t8 : Delete all nodes");
	printf("\n===================\n");
}

void in_order_display(TreeNode* root) {
	
	if (root == NULL) {
		return;
	}
	else {
		in_order_display(root->left);
		printf("\n%s : %s", root->key.word, root->key.mean);
		in_order_display(root->right);
	}
}

int main() {
	char choice;
	element key;
	TreeNode* root = NULL, * temp;
	printf("\n20186757 Hwang Young Jin\n");
	do {
		menu();
		choice = getchar();
		getchar();
		switch (choice - '0') {
		case 1:
			printf("\n[Word input] Please enter a word : ");
			gets(key.word);
			printf("\n[Word input] Please enter the meaning of the word : ");
			gets(key.mean);
			insert_root(&root, key);
			break;
		case 2:
			printf("\n[Delete word] Enter the wordd to delete : ");
			gets(key.word);
			delete_node(root, key);
			break;
		case 3:
			printf("\n[Word Search] Enter the word to search : ");
			gets(key.word);
			temp = searchBST(root, key);
			if (temp != NULL) {
				printf("\nWord meaning : %s", temp->key.mean);
			}
			else {
				printf("\nThis word is not in the dictionary.");
			}
			break;
		case 4:
			printf("\t[Dictionary print]");
			in_order_display(root);
			printf("\n\t[End of dictionary]\n");
			break;
		case 6:
			printf("\nBST Height : %d",get_tree_height(root));
			break;
		case 7:
			printf("\nNumber of all Nodes : %d", get_number_all_node(root));
			break;
		case 8:
			if (delete_all_node(root) == NULL) {
				root = NULL;
				printf("\nDelete all nodes!");
			}
			break;
		}
	} while ((choice - '0') != 5);

	return 0;
}

/*ã�� ��� ����ϰ� �ش� node ��ȯ*/
TreeNode* searchBST(TreeNode* root, element key) {
	int compare = 0;
	TreeNode* current = root;
	
	/*��� ã�� ��ȯ�ϱ� - �ݺ�*/
	while (current != NULL) {
		compare = strcmp(key.word, current->key.word);
		if (compare > 0) { // node-key < key
			current = current->right;
		}
		else if (compare < 0) { // key < node-key
			current = current->left;
		}
		else {
			printf("\nSearch word : %s", current->key.word);
			return current;
		}
	}
}

/*node �ֱ� - ��ȯ*/
TreeNode* insert_key(TreeNode* root, element key) {
	TreeNode* newNode;
	TreeNode* current = root;
	int compare = 0;
	if (current == NULL) {
		newNode = (TreeNode*)malloc(sizeof(TreeNode));
		newNode->key = key;
		newNode->right = NULL;
		newNode->left = NULL;
		return newNode;
	}
	else { // �ܸ���� ã���� level down 
		compare = strcmp(key.word, current->key.word);
		if (compare > 0) { //key->root-key
			/*��ȯ�� �� ���������� ���̱�*/
			current->right = insert_key(current->right, key);
			return current;
		}
		else if (compare < 0) { //key < root-key
			/*��ȯ�� �� ���������� ���̱�*/
			current->left = insert_key(current->left, key);
			return current;
		}
		else {
			printf("\nThe same word already exists\n");
			return current;
		}
	}
}

void insert_root(TreeNode** root, element key) {
	*root = insert_key(*root, key);
}

/*�ش� key ������ node ���� - �ݺ�*/
void delete_node(TreeNode* root, element key) {
	TreeNode* parent = NULL, * current = NULL, * succ = NULL, * succ_parent = NULL;
	TreeNode* child = NULL;
	current = root;
	/*root �� NULL�� �ƴϰ� key���� ã�� ���� ������ �ݺ�*/
	while ((current != NULL) && strcmp(current->key.word, key.word) != 0) {
		parent = current;
		if (strcmp(key.word, current->key.word) < 0) { //key < root-key
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	if (current == NULL) {
		printf("\nNo key to look for\n");
		return;
	}

	/*�ܸ� ��� ����*/
	if ((current->left == NULL) && (current->right == NULL)) {
		/*�θ� �ڽ� ���� ����*/
		if (parent != NULL) {
			if (parent->left == current) { //���� node�� �θ�����ΰ��
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
		else { //�θ� null�ϋ�
			root = NULL;
		}
		printf("\n%s Delete\n", current->key.word);
	}
	/*�ڽĳ�� �Ѱ��϶�*/
	else if ((current->left == NULL) || (current->right == NULL)) {
		/*���� �� child ����*/
		if (current->left != NULL) {
			child = current->left;
		}
		else {
			child = current->right;
		}
		/*Parent�� child ����*/
		if (parent != NULL) {
			if (parent->left == current) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else { // �θ� null�϶�
			root = child;
		}
		printf("\n%s Delete\n", current->key.word);
	}
	/*�ڽĳ�� 2���϶�*/
	else {
		succ_parent = current;
		succ = current->right; //succ�� current�� ������ �ڽ�
		//cur������ �ڽ��� �� ���� �ܸ� node ã��
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		/*current ������ �ڽ��� �����ڽ��� �ִ°��*/
		if (succ_parent->left == succ) {
			/*���� �ڽ��� ������ �ڽ��� �������� �����Ƿ�*/
			succ_parent->left = succ->right; // ���ٸ� NULL��
		}
		/*current ������ �ڽ��� �����ڽ��� ���°��*/
		else { //succ_parent�� �������� succ�̹Ƿ�
			succ_parent->right = succ->right; // ���ٸ� NULL��
		}
		printf("\n%s Delete\n", current->key.word);
		current->key = succ->key; // current ��ġ�� �ٲ� node key�� ����
		current = succ; //current�� succ�� �޾Ƽ� ��� free���ش�.
	}
	free(current);
}

int get_tree_height(TreeNode* root) {
	/*1+�ڽ� ���� ū height �� ��ȯ*/
	int height = 0;
	TreeNode* current = root;
	if (root != NULL) {

		height = 1 + max(get_tree_height(current->left), get_tree_height(current->right));
	}
	return height;
}

int get_number_all_node(TreeNode* root) {
	int count = 0;
	TreeNode* current = root;

	if (root != NULL) {
		count = 1 + get_number_all_node(current->left) + get_number_all_node(current->right);
	}
	return count;
}

TreeNode* delete_all_node(TreeNode* root) {
	/*postOrder ������ ��� node ����*/
	TreeNode* current = root;
	if (current == NULL) {
		return NULL;
	}
	else{
		delete_all_node(current->left);
		delete_all_node(current->right);
		free(current);
		return NULL;
	}
}