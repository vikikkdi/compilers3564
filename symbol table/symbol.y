%{
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
extern char* yytext;
extern "C"{
	int yylex(void);
	void yyerror(const char* st){
		printf("error: %s\n",yytext);
	}
	int yywrap(){	return 1;	}
}

vector< vector<string> > s(100000);
void print();
void remove();
map<string,int> find(vector<string>);
int i=0;
%}

%token TYPE KEY ID OPB OCB COM SMC

%%
S: OPB{i++;} STMT OCB{print();remove();} S
	|;

STMT: TYPE{s[i].push_back(yytext);} ID{s[i].push_back(yytext);} T
	| S
	| ;

T: COM ID{s[i].push_back(yytext);} T
	| SMC STMT

%%

map<string, int> find(vector<string> vec){
	
}

void print(){
	for(int x=1;x<=i;x++){
		for(int y=0;y<s[x].size();y++){
			cout<<s[x][y]<<" ";
		}
		cout<<endl;
	}
	cout<<"-------------END OF BLOCK---------------"<<endl;
}

void remove(){
	s[i].resize(0);
	i--;
}

int main(){	
	cout<<"\n\n\n\n\n";
	yyparse();
}