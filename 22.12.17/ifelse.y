%{
	#include<stdio.h>	
%}
%token IF ELSE OP CL OC CC TEXT

%%
	S : SF;

	SF : TEXT SF
		| IF OP TEXT CL OC SF CC ST
		| ;
	ST : ELSE OC SF CC SF {printf("matched !!!\n");}
		| error{printf("else{}\n");}SF;
%% 
#include "lex.yy.c"
main(){
	yyparse();	
}