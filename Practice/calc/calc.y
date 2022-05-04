%{
/* YACC source for calculator program */
# include <stdio.h>
#define YYSTYPE double
%}
%token NUMBER SQR
%left '+' '-'
%left '*' 
%left  SQR
%%
comm : comm '\n'
	| lambda
	| comm expr  '\n' {printf("%f\n", $2);}
	| comm error '\n' {yyerrok; printf(" Try again \n");}
	;
expr : '(' expr ')' {$$ = $2;}
	| expr '+' expr {$$ = $1 + $3;}
	| expr '-' expr {$$ = $1 - $3;}
	| expr '*' expr {$$ = $1 * $3;} 
	| SQR  expr     {$$ = $2 * $2;}
	| NUMBER
	;
lambda: /* empty */
	;
%%
//#include "calclex.c"
//#define YYSTYPE double
yyerror(char *s){ printf("%s\n",s);}
main(){  return yyparse(); }

