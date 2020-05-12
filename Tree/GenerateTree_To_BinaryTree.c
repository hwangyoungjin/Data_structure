#include <stdio.h>
#include <stdlib.h>
/*Homework Exam (Mid-Term)*/
/*	No.1 questions.	*/
/*20186757 Hwang Young Jin*/

typedef struct TreeNode {
	int Data;
	int count; // child에 연결된 node 수
	struct TreeNode *child;
}TreeNode;

/* 입력 : (1(2(567)34(89)) 
				1

		/		|	   ＼
		2		3		4							
	   /|＼		   	   / |
	  5 6 7			   8 9

*/

TreeNode* NewRootNode(int data) {
	TreeNode* rootNode = (TreeNode*)malloc(sizeof(TreeNode));
	rootNode->Data = data;
	rootNode->count = 0;
	rootNode->child = NULL;
	return rootNode;
}

void InsertNode(TreeNode* node,int data) { // 부모노드
	node->count += 1;// +1은 node 추가를 의미
	node->child = (TreeNode*)realloc(node->child, sizeof(TreeNode) * (node->count)); // 자식생성
	node->child[node->count - 1].Data = data;
	node->child[node->count - 1].count = 0;
	node->child[node->count - 1].child = NULL;
}

void PreorderNode(TreeNode* root) { 
	if (root == NULL ) {
	}
	printf("\ndata : %d", root->Data);
	for (int i = 0; i < root->count; i++) {
		PreorderNode(&(root->child[i]));
	}
}

int main() {
	TreeNode* root = NULL;
	int level=0,num = 0;
	char treedata[30];
	char* tree;
	
	/*일반트리  -> 이진트리*/
	printf("\n ===   /*Homework Exam (Mid-Term)*/ ");
	printf("\n ===  /*	No.1 questions.	*/ ");
	printf("\n === /*20186757 Hwang Young Jin*/ ");

	printf("\n\n ===   '(' and ')' distinguishes levels   === ");
	printf("\n\n ===  Input levels define up to 3 levels  === ");
	printf("\n\n === Data can only be entered from 0 to 9 === ");
	printf("\n\n Enter the data [ ex.(1(2(567)34(89))) ] : ");

	scanf_s("%s", treedata, sizeof(treedata));
	tree = treedata;
	while (*tree != '\0') {
		if (*tree >= 48 && *tree <= 57) { // 숫자변환 가능한지
			num = *tree - 48;
			if (level == 1) {
				root = NewRootNode(num); 
			}
			else if(level == 2){
				InsertNode(root, num);
			}
			else if (level == 3) {
				InsertNode(&(root->child[(root->count)-1]), num);
			}
		}
		else if(*tree == 40) { // '(' 인지 
			level++;
		}
		else if(*tree == 41){ // ')' 인지 
			level--;
		}
		tree++;
	}
	
	/*이진트리의 preorder로 출력*/
	printf("\n\nPreorder Start");
	PreorderNode(root);
	printf("\nPreorder End\n");
	
}
