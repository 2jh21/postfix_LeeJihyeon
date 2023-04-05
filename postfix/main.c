#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Full!\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return 0;
	}
	else return s->data[(s->top)--];
}

int eval(char exp[]) {
	int op1, op2, i;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		
		if (ch >= '0' && ch <= '9') {
			push(&s, ch - '0');
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case'+': push(&s, op1 + op2); break;
			case'-': push(&s, op1 - op2); break;
			case'*': push(&s, op1 * op2); break;
			case'/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main() {
	int result, i;
	char postfix[MAX_STACK_SIZE];

	while (1) {
		printf("후위표기식 입력: ");
		scanf_s("%s", postfix, MAX_STACK_SIZE);

		int len = strlen(postfix);
		int valid_input = 1;

		for (i = 0; i < len; i++) {
			char ch = postfix[i];

			if (ch >= '0' && ch <= '9') {
			}
			else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			}
			else {
				valid_input = 0;
				printf("error!\n\n");
				break;
			}
		}
		if (valid_input) {
			result = eval(postfix);
			printf("\n결과값은 %d\n", result);
			break;
		}
	}
	return 0;
}