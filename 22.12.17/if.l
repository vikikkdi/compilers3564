%%
if 	return IF;
else	return ELSE;
"("		return OP;
")"		return CL;
"{"		return OC;
"}"		return CC;
[ \t\n]		{printf("%s",yytext);};
[a-zA-Z0-9><+-=*/%&|!\[\];]+	return TEXT;
.	return yytext[0];		
%%
