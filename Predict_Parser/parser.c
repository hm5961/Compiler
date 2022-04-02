#include<stdio.h>
#include<stdlib.h>

/* 
1. expr → expr + term {print(1)}
2. expr → expr ? term {print(2)}
3. expr → term {print(3)}
4. term → term * factor {print(4)}
5. term → term / factor {print(5)}
6. term → factor {print(6)}
7. factor → ( expr ) {print(7)}
8. factor → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 

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
(e는 앱실론) 
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
	exp();
	
	if (lookahead == '$')
		printf("\n");
		
	else
	{
		printf(" error");
		exit(1);
	}
}

void match(char token) {
	
	if (lookahead == token)
		lookahead = nexttoken();
		
	else 
	{
		printf(" error");
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


void exp() 
{
	term();
	printf("3");
	rest1();
}

void term() 
{
	factor();
	printf("6");
	rest2();
}

void rest1(){
	
	if(lookahead == '+')
	{
		match('+');
		term();
		printf("1");
		rest1();
	}
	else if(lookahead == '-')
	{
		match('-');
		term();
		printf("2");
		rest1();
	}
}

void rest2(){
	
	if(lookahead == '*')
	{
		match('*');
		factor();
		printf("4");
		rest2();
	}
	else if(lookahead == '/')
	{
		match('/');
		factor();
		printf("5");
		rest2();
	}
}


void factor(){
	
	if(isdigit(lookahead))
	{
		match(lookahead);
	}
	
	else if(lookahead == '(')
	{
		match(lookahead);
		exp();
		printf("7");
		if(lookahead == ')')
		{
			match(lookahead);
		}
		else
		{
			printf(" error");
			exit(1);
		}
	}
	else
	{
		printf(" error");
		exit(1);
	}
}
