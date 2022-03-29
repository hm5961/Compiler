#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

/* 
1. expr �� expr + term {print(1)}
2. expr �� expr ? term {print(2)}
3. expr �� term {print(3)}
4. term �� term * factor {print(4)}
5. term �� term / factor {print(5)}
6. term �� factor {print(6)}
7. factor �� ( expr ) {print(7)}
8. factor �� 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
*/
/*
���� ���� ��ȯ
*/

/* 
1. ���ڿ� �迭�� ��ǲ������
2. ���ڴ� 8�� ��Ģ�� ���� factor��
3. ��ȣ�� �Ǻ� ��
4. * �Ǵ� / �� ��� 4�� �Ǵ� 5�� ��Ģ�� �����Ѵ�
5. �׸��� ���� ���� term, ������ ���� factor�� �����Ѵ�.
6. + �Ǵ� - �� ��� 1�� �Ǵ� 2�� ��Ģ�� �����Ѵ�.
7. �׸��� �������� expr ������ ���� term���� �����Ѵ�.
8. $������ ��ž ����
*/

/*
Ʈ�� ����
*/

/*
if char[now]�� Ÿ�԰� char[now+1]�� ������ error
Ÿ�� -> ���� and ������
==> �̰� main�� �ִ� lookahead = nexttoken();
*/

void match(char token);
char nexttoken();
char rest();
char term();
char expr();
char exp();

char lookahead;

void main() {
	lookahead = nexttoken();
	exp();
	while (1)
	{
		expr();
		if (lookahead == '$')
			printf("\n");
		else
			printf(" error\n");
	}
	return;
}

char nexttoken() {
	char c;
	while (1) {
		c = getchar();
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0') continue;
		return(c);
	}
	return;
}

void match(char token) {
	if (lookahead == token)
		lookahead = nexttoken();
	else {
		printf("error\n");
		exit(1);
	}
	return;
}

char rest() {
	if (lookahead == '+') {
		match('+');
		term();
		putchar('+');
		rest();
		putchar(1);
	}
	else if (lookahead == '-') {
		match('-');
		term();
		putchar('-');
		rest();
		putchar(2);
	}
	return putchar(3);
}

char rest2() {
	if (lookahead == '*') {
		match('*');
		term();
		putchar('*');
		rest();
		putchar(4);
	}
	else if (lookahead == '/') {
		match('/');
		term();
		putchar('/');
		rest();
		putchar(5);
	}
	return putchar(6);
}

char term() {
	if (isdigit(lookahead)) {
		putchar(lookahead);
		match(lookahead);
	}
	else
		match(lookahead);
	return;
}

char expr() {
	term();
	while (1)
	{
		if (lookahead == '+') {
			match('+');
			term();
			putchar('+');
		}
		else if (lookahead == '-') {
			match('-');
			term();
			putchar('-');
		}
		else
			break;
	}
	return;
}
char exp() {
	
	rest();
}
