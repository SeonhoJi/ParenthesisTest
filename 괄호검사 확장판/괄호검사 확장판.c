#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
// 스택초기화함수
void init_stack(StackType* s) {
	s->top = -1;
}
// 공백상태검출함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화상태검출함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택포화에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  // n= 문자열의길이
	init_stack(&s);// 스택의초기화

	for (i = 0; i < n; i++) {
		ch = in[i];// ch= 다음문자
		switch (ch) {
		case '(':   case '[':    case '{':
			push(&s, ch);
			break;
		case ')':   case ']':    case '}':
			if (is_empty(&s))  return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // 스택에남아있으면오류
	return 1;
}
int main(void) {
	char stnc[100];
	printf("괄호를 검사하기 위한 문자열을 입력하세요\n");
	gets(stnc, 100);
	char* p = stnc;

	if (check_matching(p) == 1)
		printf("%s Yes\n", p);
	else
	{
		printf("%s No\n", p);
	}
}