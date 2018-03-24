%{
#include<stdio.h>
#include<string.h>
void yyerror(const char* st);
int yywrap();

%}

%token FOR OPB CLB CLC OPC SMC TEXT NRC DO WHILE

%type <str> S s st do for FOR OPB CLB CLC OPC SMC TEXT NRC DO WHILE

%union{
	char *str;
}

%%

S:	for S
	| do S
	| s S
	|;

for: FOR OPB TEXT SMC TEXT SMC TEXT CLB {printf("%s;\nwhile(%s)",$3,$5);} OPC{printf("{");} s {printf("%s;\n",$7);}CLC {printf("}");};

s:	TEXT{printf("%s",$1);} SMC{printf(";");} S
	| ;

st: TEXT SMC st
	|;

do:	DO OPC st CLC WHILE OPB TEXT CLB SMC {printf("while(%s){%s}",$7,$3);};
	
%%

void yyerror(const char* st){
	printf("error: %s\n",st);
}

int yywrap(){	return 1;	}

int main(){	yyparse();	}