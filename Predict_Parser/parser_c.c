#include<stdio.h>
#include<stdlib.h>
/* 
expr -> term Rest

Rest -> + term print(+) Rest
	   | - term print(-) Rest
	   | e
	   
term -> factor Rest2
		| * factor print(*) Rest2
		| / factor print(/) Rest2
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
	//exp();
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
	while (1) {
		c = getchar();
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
			continue;
		return(c);
	}
}

void exp() {
	printf("e->\t");
	term();
	printf("¢¹3¢·\t");
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
	if(lookahead == '+')
	{
		match('+');
		term();
		printf("¢¹1¢·\t");
		rest1();
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
	if(isdigit(lookahead))
	{
		match(lookahead);
	}
	
	else if(lookahead == '(')
	{
		match(lookahead);
		exp();
		printf("¢¹7¢·");
		if(lookahead == ')')
		{
			match(lookahead);
		}
		else
		{
			printf("error\n");
			exit(1);
		}
	}
	
	else
	{
		printf("error\n");
		exit(1);
	}
}
