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


/*순환 - 찾은 결과 출력하고 해당 node 반환*/
TreeNode* searchBST(TreeNode* root, element key); //O(h)

/*node 삽입*/
void insert_root(TreeNode** root, element key);

/*순환 - insert_root()를 통해 사용되는 함수 : node 넣기*/
TreeNode* insert_key(TreeNode* root, element key); //O(h)

/*반복 - 해당 key 보유한 node 삭제*/
void delete_node(TreeNode* root, element key); //O(h)

/*height 구하기*/
int get_tree_height(TreeNode* root);

/*node 수 구하기*/
int get_number_all_node(TreeNode* root);

/*모든 node 삭제*/
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

/*찾은 결과 출력하고 해당 node 반환*/
TreeNode* searchBST(TreeNode* root, element key) {
	int compare = 0;
	TreeNode* current = root;
	
	/*노드 찾고 반환하기 - 반복*/
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

/*node 넣기 - 순환*/
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
	else { // 단말노드 찾으러 level down 
		compare = strcmp(key.word, current->key.word);
		if (compare > 0) { //key->root-key
			/*반환된 값 오른쪽으로 붙이기*/
			current->right = insert_key(current->right, key);
			return current;
		}
		else if (compare < 0) { //key < root-key
			/*반환된 값 오른쪽으로 붙이기*/
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

/*해당 key 보유한 node 삭제 - 반복*/
void delete_node(TreeNode* root, element key) {
	TreeNode* parent = NULL, * current = NULL, * succ = NULL, * succ_parent = NULL;
	TreeNode* child = NULL;
	current = root;
	/*root 가 NULL이 아니고 key값을 찾지 못할 때까지 반복*/
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

	/*단말 노드 삭제*/
	if ((current->left == NULL) && (current->right == NULL)) {
		/*부모 자식 연결 끊기*/
		if (parent != NULL) {
			if (parent->left == current) { //삭제 node가 부모왼쪽인경우
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}
		}
		else { //부모 null일떄
			root = NULL;
		}
		printf("\n%s Delete\n", current->key.word);
	}
	/*자식노드 한개일때*/
	else if ((current->left == NULL) || (current->right == NULL)) {
		/*연결 할 child 저장*/
		if (current->left != NULL) {
			child = current->left;
		}
		else {
			child = current->right;
		}
		/*Parent와 child 연결*/
		if (parent != NULL) {
			if (parent->left == current) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else { // 부모가 null일때
			root = child;
		}
		printf("\n%s Delete\n", current->key.word);
	}
	/*자식노드 2개일때*/
	else {
		succ_parent = current;
		succ = current->right; //succ는 current의 오른쪽 자식
		//cur오른쪽 자식의 맨 왼쪽 단말 node 찾기
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		/*current 오른쪽 자식의 왼쪽자식이 있는경우*/
		if (succ_parent->left == succ) {
			/*왼쪽 자식의 오른쪽 자식이 있을수도 있으므로*/
			succ_parent->left = succ->right; // 없다면 NULL들어감
		}
		/*current 오른쪽 자식의 왼쪽자식이 없는경우*/
		else { //succ_parent의 오른쪽은 succ이므로
			succ_parent->right = succ->right; // 없다면 NULL들어감
		}
		printf("\n%s Delete\n", current->key.word);
		current->key = succ->key; // current 위치에 바꿀 node key값 저장
		current = succ; //current가 succ를 받아서 대신 free해준다.
	}
	free(current);
}

int get_tree_height(TreeNode* root) {
	/*1+자식 중의 큰 height 값 반환*/
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
	/*postOrder 순서로 모든 node 삭제*/
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