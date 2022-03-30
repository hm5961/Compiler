#include<stdio.h>
#include<stdlib.h>
/* 
������ȹ ���� ���� �����Ͽ�
��ȯ
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

//������ ������ ������ �������� ����Ѵ�.

void exp() {
	printf("e->\t");
	term();
	printf("3\t"); // ���� Ž��ó�� ����ϵ��� term���� ���Ŀ� ����ϵ��� �Ѵ�.
	rest1();
}

void term() {
	printf("t->\t");
	factor();
	printf("6\t");
	rest2();
}

void rest1(){
	
	printf("r1->\t");
	if(lookahead == '+') // ���� lookahead�� '+'���
	{
		match('+');
		term(); // term�Լ� ���� ��
		printf("1\t"); // 1�� ����ϰ�
		rest1(); // ��� �����Ѵ�.
	}
	else if(lookahead == '-')
	{
		match('-');
		term();
		printf("2\t");
		rest1();
	}
	else if(lookahead == '$')
	{
		printf("$\tend");
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
		printf("4\t");
		rest2();
	}
	else if(lookahead == '/'){
		match('/');
		factor();
		printf("5\t");
		rest2();
	}
	else
		return;
}

void factor(){
	
	printf("f->\t");
	if(isdigit(lookahead)) // �� ��ġ�� �ִ� lookahread�� �������� Ȯ��
	{
		match(lookahead); // �´ٸ� nexttoken���� �Ѿ���� �Ѵ�.
	}
	
	else if(lookahead == '(') //  �� ��ġ�� �����Ѱ� ��ȣ���
	{
		match(lookahead); // nexttoken���� �Ѿ ����
		exp(); // exp�� �Ѿ ��ȣ �� ������ ������ �ǵ��� �Ѵ�.
		printf("7\t);
		if(lookahead == ')') // '(' ���� ')'�� ������ ��� 
		{
			match(lookahead); // �������� �Ѿ ����Ѵ�
		}
		else // �ƴ϶�� ���� ��� �� �����Ѵ�.
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
