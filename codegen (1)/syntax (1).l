%{
	#include<bits/stdc++.h>
	using namespace std;
	#include "y.tab.h"
%}


%%
"("   	yylval.str=strdup(yytext);return OP;
")"		yylval.str=strdup(yytext);return CL;
"+"		yylval.str=strdup(yytext);return PL;
"-"		yylval.str=strdup(yytext);return MIN;
"*"		yylval.str=strdup(yytext);return MUL;
"/"		yylval.str=strdup(yytext);return DIV;
[a-zA-Z_][a-zA-Z0-9_]*		yylval.str=strdup(yytext);return ID;
[\n \t]	;
.	;
%%