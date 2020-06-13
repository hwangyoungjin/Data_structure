#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 10 // key의 최대 길이
#define TABLE_SIZE 13 // 해싱테이블의 크기는 prime
typedef struct element {
	char key[KEY_SIZE];
}element;

element hashTable[TABLE_SIZE];


/*hash table 초기화*/
void init(element hashTable[]) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i].key[0] = NULL;
	}
}

/*문자로된 key를 숫자로 변환 = > 호너의 방법 이용*/
int transform(char* key) {
	int num = 0;
	while (*key) { //key가 null이 아닐때까지
		num = 31 * num + *key++;
	}
	return num;
}

/*제산 함수를 사용한 해쉬 함수*/
int hash_function(char* key) {
	/*문자열 key를 정수로 변환 후 modular연산하여 반환*/
	return transform(key) % TABLE_SIZE;
}

/*linear probing 이용 하여 bucket 비어있는지 check*/
void hash_lp_add(element item, element hashTable[]) {
	int i, hashValue;
	hashValue = i = hash_function(item.key); //hash address
	while (hashTable[i].key[0] != NULL) { // Key가 null이면 stop
		if (!strcmp(item.key, hashTable[i].key)) { // 두 key값이 동일하면
			printf("\n탐색키가 중복 되었습니다.");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hashValue) {
			printf("\nTable FULL!!");
			exit(1);
		}
	}
	hashTable[i] = item;
}

/*hash table search*/
void hash_lp_search(element item, element hashTable[]) {
	int i, hashValue;
	hashValue = i = hash_function(item.key);
	while (hashTable[i].key[0] != NULL) {
		if (!strcmp(item.key, hashTable[i].key)) {
			printf("\n탐색 %s 위치 : %d\n", item.key, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hashValue) {
			printf("\n찾는 값이 테이블에 없음\n");
			return;
		}
	}
	printf("\n찾는 값이 테이블에 없음\n");
}

/*hash table 출력*/
void hash_lp_print(element ht[]) {
	int i;
	printf("\n=================\n");
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%d] %s\n", i, ht[i].key);
	}
	printf("\n=================\n");
}

int main() {
	//포인터 배열
	char* s[] = { "do","for","if","case","else","return","function" };
	element e;
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		strcpy_s(e.key,sizeof(e.key), s[i]);
		hash_lp_add(e, hashTable);
		hash_lp_print(hashTable);
	}
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		strcpy_s(e.key, sizeof(e.key), s[i]);
		hash_lp_search(e,hashTable);
	}


	return 0;
}