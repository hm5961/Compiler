#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

/* 
1. expr → expr + term {print(1)}
2. expr → expr ? term {print(2)}
3. expr → term {print(3)}
4. term → term * factor {print(4)}
5. term → term / factor {print(5)}
6. term → factor {print(6)}
7. factor → ( expr ) {print(7)}
8. factor → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
*/
/*
우측 기준 변환
*/

/* 
1. 문자열 배열을 인풋받으면
2. 숫자는 8번 규칙에 의해 factor로
3. 기호는 판별 후
4. * 또는 / 일 경우 4번 또는 5번 규칙을 적용한다
5. 그리고 왼쪽 항은 term, 오른쪽 항은 factor을 적용한다.
6. + 또는 - 일 경우 1번 또는 2번 규칙을 적용한다.
7. 그리고 왼쪽항은 expr 오른쪽 항은 term으로 적용한다.
8. $나오면 스탑 리딩
*/

/*
트리 구조
*/

/*
if char[now]의 타입과 char[now+1]이 같으면 error
타입 -> 숫자 and 연산자
==> 이게 main에 있는 lookahead = nexttoken();
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
