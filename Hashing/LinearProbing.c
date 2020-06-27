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
//int transform(char* key) {
//	int num = 0;
//	while (*key) { //key가 null이 아닐때까지
//		num = 31 * num + *key++;
//	}
//	return num;
//}

//일반 적인 ascii 값 더하기
int transform(char* key) {
	int num=0;
	printf("\n%s의 ascii :", key);
	while (*key) {
		num += *key++;
	}
	printf(" %d\n", num);
	return num;
}



/*제산 함수를 사용한 해쉬 함수*/
int hash_function(char* key) {
	/*문자열 key를 정수로 변환 후 modular연산하여 반환*/
	return transform(key) % TABLE_SIZE;
}

/*linear probing : bucket 비어있는지 check*/
void hash_lp_add(element item, element hashTable[]) {
	int i, hashValue;
	hashValue = i = hash_function(item.key); // item key에 대응하는 hash address
	while (hashTable[i].key[0] != NULL) { // 첫번째문자 Key[0]이 null이면 아무것도 없기 때문에 stop
		if (!strcmp(item.key, hashTable[i].key)) { // 두 key값이 동일하면
			printf("\n탐색키가 중복 되었습니다.");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE; // hash address가 겹치지 않았으므로 다음 버킷에 넣기위해 ++
		if (i == hashValue) { //증가된 주소가 시작주소로 돌아오면 모든 버킷을 검사해도 남는 공간이 없는것 = 오류상태
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
	while (hashTable[i].key[0] != NULL) { //hashTable[i]의 value가 없을때까지 반복 // 여기서 중간에 삭제된공간 있으면 중단되는 단점존재
		if (!strcmp(item.key, hashTable[i].key)) {  // item의 key값과 hashkey가 동일하면 (0반환)
			printf("\n탐색 %s 위치 : %d\n", item.key, i);  // 찾은 value 출력하고 return
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hashValue) { // //증가된 주소가 시작주소로 돌아오면 모든 버킷을 검사해도 남는 공간이 없는것 = 오류상
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
	// do의 ASCII 코드값 (=transform(do))  : 100+111 mod 13 = 3
	// for의 ASCII 코드값 (=transform(for)) : 102+111+114 mod 13 = 2
	// ASCII 값으로 나타내면 => s[] = {3,2,12,9,9,9,12} // 9충돌 12충돌

	element e;
	//모든 단어 add
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		strcpy_s(e.key,sizeof(e.key), s[i]); //s[i]에 들어있는 문자열 복사
		hash_lp_add(e, hashTable);
		hash_lp_print(hashTable);
	}

	//모든 단어 탐색
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		strcpy_s(e.key, sizeof(e.key), s[i]);
		hash_lp_search(e,hashTable);
	}

	return 0;
}