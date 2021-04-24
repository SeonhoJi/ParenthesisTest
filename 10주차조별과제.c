#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 50
typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
// �����ʱ�ȭ�Լ�
void init_stack(StackType* s) {
	s->top = -1;
}
// ������°����Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}
// ��ȭ���°����Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "������ȭ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

// �����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���ð��鿡��\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  // n= ���ڿ��Ǳ���
	init_stack(&s);// �������ʱ�ȭ

	for (i = 0; i < n; i++) {
		ch = in[i];// ch= ��������
		switch (ch) {
		case '(':
			push(&s, ch);
			break;
		case ')':
			if (is_empty(&s))  return 0;
			else {
				open_ch = pop(&s);
				if (open_ch == '(' && ch != ')') {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // ���ÿ��������������
	return 1;
}
int main(void) {
	char* p = "(()())";
	if (check_matching(p) == 1)
		printf("%s ��ȣ�˻缺��\n", p);
	else
	{
		printf("%s ��ȣ�˻����\n", p);
	}
		


	char* a = "()(()";
	if (check_matching(a) == 1)
		printf("%s ��ȣ�˻缺��\n", a);
	else
		printf("%s ��ȣ�˻����\n", a);

}