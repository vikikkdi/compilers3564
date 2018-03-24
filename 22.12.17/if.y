%{
	#include<stdio.h>	
	extern char* yytext;
%}
%token IF ELSE OP CL OC CC TEXT

%%
	S : SF;

	SF : TEXT{printf("%s",yytext);} SF
		| IF{printf("%s",yytext);} OP{printf("%s",yytext);} TEXT{printf("%s",yytext);} CL{printf("%s",yytext);} OC{printf("%s",yytext);} SF CC{printf("%s",yytext);} ST
		| ;
	ST : ELSE {printf("%s",yytext);} OC{printf("%s",yytext);} SF CC{printf("%s",yytext);} SF
		| {printf("else{}\n");};
%% 
#include "lex.yy.c"
main(){
	yyparse();
}