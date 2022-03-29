#include<stdio.h>
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
char nexttoken();
char exp();
char term();
char factor();
char rest();
char rest2();
char same(char token);
char lookahead;

void main() {
	lookahead = nexttoken();
	exp();
	while (1)
	{
		exp();
		if (lookahead == '$')
		{
			printf("\n");
			return;
		}
		else
			printf("error\n");
	}
	return;
}

void match(char token) {
	if (lookahead == token)
	{
		//same(token);
		lookahead = nexttoken();
	}
	else {
		printf("error\n");
		exit(1);
	}
}

char same(char token){

	if(isdigit(token))
	{
		if(isdigit(lookahead))
		{
			printf("double num error");
			exit(1);
		}
	}
	else if( token != '(' || token != ')')
	{
		if(!isdigit(token))
		{
			if(!isdigit(lookahead))
			{
				printf("double cal error");
				exit(1);
			}
		}
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

char exp() {
	printf("e->\t");
	term();
	printf("¢¹3¢·\t");
	rest();
}

char term() {
	printf("t->\t");
	factor();
	printf("¢¹6¢·\t");
	rest2();
}

char rest(){
	printf("r1->\t");
	if(lookahead == '+'){
		match('+');
		term();
		printf("¢¹1¢·\t");
		rest();
	}
	else if(lookahead == '-'){
		match('-');
		term();
		printf("¢¹2¢·\t");
		rest();
	}
	else if(lookahead == '$')
	{
		printf("$ end");
		exit(1);
	}		
	
		match(lookahead);
}

char rest2(){
	printf("r2->\t");
	if(lookahead == '*'){
		match('*');
		printf("¢¹4¢·\t");
		factor();
		rest2();
	}
	else if(lookahead == '/'){
		match('/');
		printf("¢¹5¢·\t");
		factor();
		rest2();
	}
}

char factor(){
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
		putchar("error\n");
	}
}
