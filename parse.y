%{
	#include <stdio.h>
	#include <stdlib.h>
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern FILE *yyout;
	int yyerror(const char *s);
%}

%union{
	char *kval;
	int   ival;
	char *dval;
	char *oval;
	char *sval;
	char *lval;
}

%token <kval> Keyword
%token <ival> Digits
%token <dval> Identifier
%token <oval> Operator
%token <sval> Separator
%token <lval> String

%%

A: 
	Keyword A
	{
		printf("\nKeyword\t\t-->\t  %s",$1);
	}
|
	Digits A
	{
		printf("\nDigit\t\t-->\t  %d",$1);
	}
|
	Identifier A
	{
		printf("\nIdentifier\t-->\t  %s",$1);
	}
|
	Operator A
	{
		printf("\nOperator\t-->\t  %s",$1);
	}
|
	Separator A
	{
		printf("\nSeparator\t-->\t  %s",$1);
	}
|
	String A
	{
		printf("\nString\t\t-->\t  %s",$1);free($1);
	}
|
	Keyword 
	{
		printf("\nKeyword\t-->\t  %s",$1);
	}
|
	Digits 
	{
		printf("\nDigit\t-->\t  %d",$1);
	}
|
	Identifier 
	{
		printf("\nIdentifier\t-->\t  %s",$1);
	}
|
	Operator 
	{
		printf("\nOperator\t-->\t  %s",$1);
	}
|
	Separator 
	{
		printf("\nSeparator\t-->\t  %s",$1);
	}
|
	String 
	{
		printf("\nString\t-->\t  %s",$1);free($1);
	};
%%

int main() 
{   
        yyin=fopen("test.lp", "r"); 
        yyparse();
}

int yyerror(const char *s)
{
	printf("\nSyntax error! %s", s);
	exit(-1);
}