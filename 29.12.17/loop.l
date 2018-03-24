%{
	#include<stdio.h>
	#include "y.tab.h"
%}

text [a-zA-Z0-9+\-=/*<>!&|,]

%%
for			yylval.str=strdup(yytext);return FOR;
do			yylval.str=strdup(yytext);return DO;
while		yylval.str=strdup(yytext);return WHILE;
"("			yylval.str=strdup(yytext);return OPB;
")"			yylval.str=strdup(yytext);return CLB;
"{"			yylval.str=strdup(yytext);return OPC;
"}"			yylval.str=strdup(yytext);return CLC;
";"			yylval.str=strdup(yytext);return SMC; 
({text}" "?)*		yylval.str=strdup(yytext);return TEXT;
[\n \t]+	printf("%s",yytext);
.			yylval.str=strdup(yytext);return NRC;
%%