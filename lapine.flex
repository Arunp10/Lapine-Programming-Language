%{
	#include <stdio.h>
	#include "parse.tab.h"
	extern int yylex();

%}

Keyword (Lapine|hay|dayn|thrang|blang|lapine|os|el-os|el|fix|stop|goOn|goBack|alpha|beta)
Digits [0-9]
Identifier [a-zA-Z]
Operator [+|-|*|/|=|==|<|>|<=|=>|!=]
Separator [{|}|;|,|(|)]
String \"([^\\\"]|\\.)*\"
Newline [ \t\n]


%%
{Keyword} {yylval.kval = strdup(yytext); return Keyword;}
{Digits}+ {yylval.ival = atoi(yytext); return Digits;}
{Identifier}({Identifier}|{Digits})* {yylval.dval = strdup(yytext); return Identifier;}
{Operator} {yylval.oval = strdup(yytext); return Operator;}
{Separator} {yylval.sval = strdup(yytext); return Separator;}
{String} {yylval.lval = strdup(yytext); return String;}
{Newline}+
. {printf("Invalid Token %s ",yytext);}
%%

int yywrap(void)
{
	return 1;
}