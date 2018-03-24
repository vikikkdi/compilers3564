%{
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
extern "C"{
	int yylex(void);
	void yyerror(const char* st){
		printf("error: %s\n",st);
	}
	int yywrap(){	return 1;	}
}

typedef struct Node{
	struct Node *left, *right;
	char* val;
}node;

node * makeNode(char* val, node* left, node* right){
	node* s = new node();
	s->val = val;
	s->left = left;
	s->right = right;
	return s;
}

node * start;

void iprint(node* a){
	if(a){
		printf("%s",a->val);
		iprint(a->left);
		iprint(a->right);
	}
}

%}

%token PL MUL DIV MOD ID OP CL MIN
%type<s> E T F
%type <str> PL MUL DIV MOD ID OP CL MIN

%union{
	char *str;
	struct Node *s;
}

%%
E1: E{iprint($1);printf("\n");};

E: E PL T{$$ = makeNode($2,$1,$3);}
	| E MIN T{$$ = makeNode($2,$1,$3);}
	|T{$$ = $1;};

T: T MUL F{$$ = makeNode($2,$1,$3);}
	| T DIV F{$$ = makeNode($2,$1,$3);}
	| F{$$ = $1;};

F:	OP E CL{$$ = $2;}
	| ID{$$ = makeNode($1,NULL,NULL);};
%%

int main(){	
	printf("\n\n\n\n");
	yyparse();
}