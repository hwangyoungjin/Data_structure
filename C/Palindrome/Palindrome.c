#include <stdio.h>
#include <string.h> //To use strlen 
#include <stdbool.h> // To use boolean
//20186757 HwangYoungJin

int main() {
	char word[20];
	int length = 0;
	bool isPalindrome = true;

	printf("Enter the query for checking a Palindrome : ");
	scanf_s("%s", word, sizeof(word));
	length = strlen(word); // Character length

	for (int i = 0; i < length / 2; i++) {
		if (word[i] != word[length -1 - i]) {
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome == true) {
		printf("\nIt is a Palindrom!!\n");
	}
	else {
		printf("\nIt is not a Palindrom!!\n");
	}
}