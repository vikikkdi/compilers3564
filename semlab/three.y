%{
	#include<bits/stdc++.h>
	using namespace std;
	int yylex();
	void yyerror(char *s);

	int to_int(string s){
		int val = 0;
		for(int i=s.length()-1;i>=0;i--){
			val = (val*10)+(s[i]-'0');
		}
		return val;
	}

	map<string, vector<int> > symbol;
%}

%union{
	char * str;
}

%token <str> TYPE VAL AND OR NOT LT GT EQQ LTE GTE PL MI MUL DIV OP CL OCB CCB OSB CSB EQ COMMA SEMICOLON IF ELSE WHILE TRUE FALSE NTE INIT AT HASH QN ID

%%

START : S{printf("Accepted\n");};

S : INIT ID{
			vector<int> a;
			a.resize(0);
			symbol[$2] = a;
		} S
	| INIT ID COMMA VAL{
			vector<int> a;
			a.push_back(to_int($4));
			symbol[$2] = a;
		} S
	| D S
	| C S
	| Q S
	| H S
	| P S
	|;

D : AT ID{
		if(symbol.find($2)==symbol.end()){
			yyerror("Not declared");
		}
		vector<int> a(symbol[$2]);
		for(int i=0;i<a.size();i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	};

C : ID EQ ID OR ID{
		if(symbol.find($1)==symbol.end() || symbol.find($3)==symbol.end() || symbol.find($5)==symbol.end()){
			yyerror("Not declared");
		}
		vector<int> l1(symbol[$3]);
		for(int i=0;i<symbol[$5].size();i++){
			l1.push_back(symbol[$5][i]);
		}
		symbol[$1] = l1;
	};

Q : ID QN VAL{
		if(symbol.find($1)==symbol.end()){
			yyerror("Not declared");
		}
		vector<int> l1(symbol[$1]);
		bool flag = false;
		for(int i=0;i<l1.size();i++){
			if(l1[i]==to_int($3)){
				flag = true;
				break;
			}
		}
		if(flag){
			cout<<$3<<" is present in "<<$1<<endl;
		}else{
			cout<<$3<<" is not present in "<<$1<<endl;
		}
	};

H : ID HASH ID{
		if(symbol.find($1)==symbol.end() || symbol.find($3)==symbol.end()){
			yyerror("Not declared");
		}
		vector<int> l1(symbol[$1]);
		vector<int> l2(symbol[$3]);
		bool flag = true;
		for(int i=0;i<min(l1.size(),l2.size());i++){
			if(l1[i]!=l2[i]){
				flag = false;
				break;
			}
		}
		if(l1.size()==l2.size() && flag){
			cout<<$1<<" and "<<$3<<" are same"<<endl;
		}else{
			cout<<$1<<" and "<<$3<<" are not same"<<endl;
		}
	};

P : PL ID{
		if(symbol.find($2)==symbol.end()){
			yyerror("Not declared");
		}
		vector<int> l1(symbol[$2]);
		int val = 0;
		for(int i=0;i<l1.size();i++){
			val += l1[i];
		}
		cout<<"Sum of elements in list "<<$2<<" is "<<val<<endl;
	};

%%
void yyerror(char * s)
{
	cout<<s<<endl;
	exit(0);
}
int yywrap(){	return 1;	}
int main()
{
	yyparse();
}