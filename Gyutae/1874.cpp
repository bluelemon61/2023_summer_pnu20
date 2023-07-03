#include <stdio.h>
#include <stdlib.h>
// IMPORTANT: C is faster than C++!
// In Windows, don't forget to use "_CRT_SECURE_NO_WARNINGS"!
int* stack;
char* answer;
int index_answer = 0;
int index = 0;

void push(int x) {
	stack[index++] = x;
	answer[index_answer++] = '+';
}

void pop() {
	index--;
	answer[index_answer++] = '-';
}

int main() {
	int n;
	scanf("%d", &n);
	stack = (int*) malloc(sizeof(int) * n);
	answer = (char*) malloc(sizeof(char) * 2 * n + 1);

	int index_A = 1;
	for (int i = 0; i < n; i++) {
		int Ai;
		scanf("%d", &Ai);

		if (Ai >= index_A) {
			for (; index_A <= Ai; index_A++) {
				push(index_A);
			}
			pop();
		}
		else {
			if (stack[index - 1] == Ai) {
				pop();
			}
			else {
				printf("NO\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < index_answer; i++) {
		printf("%c\n", answer[i]);
	}

	return 0;
}