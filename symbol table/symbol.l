%{
	#include "symbol.hh"
	#include<stdio.h>
%}

%%
"{"	return OPB;
"}"	return OCB;
","	return COM;
";"	return SMC;
(const|signed|short|unsigned)?" "*(int|float|char|string|auto|double|long|void)	return TYPE;
struct|break|else|switch|case|enum|register|typedef|extern	return KEY;
return|union|continue|for|default|goto|sizeof|volatile|do|if|static|while	return KEY;
[a-zA-Z_][a-zA-Z0-9_]*		return ID;
[\n\t]	;
" "	;
.	;
%%