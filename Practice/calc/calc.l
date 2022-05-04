%{
/* LEX source for calculator program */
#define YYSTYPE double
#include "calc.h"
%}
%%
[ \t]	; /* ignore blanks and tabs */
[0-9]+	{yylval = atoi(yytext); return NUMBER;}
[0.-9.]+	{yylval = atof(yytext); return NUMBER;}
"sqr"	return SQR;
\n|. 	return yytext[0];  /* return everything else */
%%
int yywrap() {return(0);}
