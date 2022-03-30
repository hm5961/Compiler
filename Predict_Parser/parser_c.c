#include<stdio.h>
#include<stdlib.h>
/* 
번역계획 수행 예를 참조하여

변환
expr -> term print(3) rest1

rest1 -> + term print(1) rest1
	   | - term print(2) rest1
	   | e
	   
term -> factor print(6) rest2
		| * factor print(4) rest2
		| / factor print(5) rest2
		| e
factor -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 
	| ( exp ) print(7) 
	| e
*/
void match(char token);
void exp();
void term();
void factor();
void rest1();
void rest2();
char nexttoken();

char lookahead;

void main() {
	lookahead = nexttoken();
	while (1)
	{
		exp();
		if (lookahead == '$')
		{
			printf("\n");
			return;
		}
		else
		{
			printf("error\n");
			exit(1);
		}
	}
}

void match(char token) {
	if (lookahead == token)
	{
		lookahead = nexttoken();
	}
	else 
	{
		printf("error\n");
		exit(1);
	}
}

char nexttoken() {
	char c;
	while (1) 
	{
		c = getchar();
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
			continue;
		return(c);
	}
}

//위에서 정리한 내용을 바탕으로 출력한다.

void exp() {
	printf("e->\t");
	term();
	printf("3\t"); // 중위 탐색처럼 기능하도록 term실행 이후에 출력하도록 한다.
	rest1();
}

void term() {
	printf("t->\t");
	factor();
	printf("¢¹6¢·\t");
	rest2();
}

void rest1(){
	
	printf("r1->\t");
	if(lookahead == '+') // 지금 lookahead가 '+'라면
	{
		match('+');
		term(); // term함수 실행 후
		printf("¢¹1¢·\t"); // 1을 출력하고
		rest1(); // 재귀 실행한다.
	}
	else if(lookahead == '-')
	{
		match('-');
		term();
		printf("¢¹2¢·\t");
		rest1();
	}
	else if(lookahead == '$')
	{
		printf("¢¹$¢·end");
		exit(1);
	}		
	else
		return;
}

void rest2(){
	printf("r2->\t");
	if(lookahead == '*'){
		match('*');
		factor();
		printf("¢¹4¢·\t");
		rest2();
	}
	else if(lookahead == '/'){
		match('/');
		factor();
		printf("¢¹5¢·\t");
		rest2();
	}
	else
		return;
}

void factor(){
	
	printf("f->\t");
	if(isdigit(lookahead)) // 이 위치에 있는 lookahread가 숫자인지 확인
	{
		match(lookahead); // 맞다면 nexttoken으로 넘어가도록 한다.
	}
	
	else if(lookahead == '(') //  이 위치에 도착한게 괄호라면
	{
		match(lookahead); // nexttoken으로 넘어간 다음
		exp(); // exp로 넘어가 괄호 쪽 내용이 선실행 되도록 한다.
		printf("¢¹7¢·");
		if(lookahead == ')') // '(' 후 ')'에 도달할 경우 
		{
			match(lookahead); // 다음으로 넘어가 계속한다
		}
		else // 아니라면 에러 출력 후 종료한다.
		{
			printf("error\n"); //
			exit(1);
		}
	}
	
	else
	{
		printf("error\n");
		exit(1);
	}
}
