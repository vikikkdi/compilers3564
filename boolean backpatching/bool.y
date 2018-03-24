%{
	#include<bits/stdc++.h>
	using namespace std;
	int yylex();
	void yyerror(char *s);
	
	typedef struct Node{
		set<int> trueList;
		set<int> falseList;
	}node;

	typedef struct ENode{
		string code;
	}enode;

	struct Node* makeNode(){
		struct Node* temp = new Node();
		return temp;
	}

	struct ENode* makeENode(){
		struct ENode* temp = new ENode();
		temp->code = "";
		return temp;
	}

	int temp=100;
	map<int, string> mp;
	
	void print(){
		map<int, string>::iterator it = mp.begin();
		for(;it!=mp.end();it++){
			cout<<it->first<<" "<<it->second<<endl;
		}
		cout<<endl;
	}

	set<int> merge(set<int> a, set<int> b){
		set<int> res;
		res.insert(a.begin(),a.end());
		res.insert(b.begin(),b.end());
		return res;
	}

	int getTemp(){	return temp++;	}

	void backPatch(set<int> a, int *add){
		ostringstream ss;
		ss<<*add;
/*		for(set<int>::iterator it=a.begin();it!=a.end();it++){
			cout<<*it<<endl;
		}*/

		for(set<int>::iterator it=a.begin();it!=a.end();it++){
			mp[*it] = mp[*it]+ss.str();
		}
	}
%}

%union{
	struct ENode * es;
	struct Node * s;
	char *str;
	int * val;
}

%token ID VAL PL MI MUL DIV POW EQ OP CL OSB CSB AND OR NOT LT GT EQQ LTE GTE
%type <str> ID VAL PL MI MUL DIV POW EQ OP CL OSB CSB AND OR NOT LT GT EQQ LTE GTE RELOP
%type <s> B 
%type <val> M
%type <es> E T F

%%

S : B{print();};

B : B OR M B{$$=makeNode(); backPatch($1->falseList,$3); $$->trueList = merge($1->trueList, $4->trueList); $$->falseList=$4->falseList;}
	| B AND M B{$$=makeNode(); backPatch($1->trueList,$3); $$->falseList = merge($1->falseList, $4->falseList); $$->trueList = $4->trueList;}
	| NOT B{$$=makeNode(); $$->trueList=$2->falseList; $$->falseList=$2->trueList;}
	| OP B CL{$$=makeNode(); $$->trueList=$2->trueList; $$->falseList=$2->falseList;}
	| E RELOP E{$$=makeNode(); int cu1 = getTemp(); int cu2 = getTemp(); $$->trueList.insert(cu1); $$->falseList.insert(cu2);mp[cu1]="if "+$1->code+$2+$3->code+" goto "; mp[cu2]="goto ";}
	| "1"{$$=makeNode(); int cu = getTemp(); $$->trueList.insert(cu); mp[cu]="goto ";}
	| "0"{$$=makeNode(); int cu = getTemp(); $$->falseList.insert(cu); mp[cu]="goto ";};

M : {*$$=temp;};

RELOP : AND{$$="&&";}
		| OR{$$="||";}
		| NOT{$$="!";}
		| GT{$$=">";}
		| LT{$$="<";}
		| GTE{$$=">=";}
		| LTE{$$="<=";}
		| EQQ{$$="==";};

E : E PL T{$$=makeENode(); $$->code=$1->code+"+"+$3->code;}
	| E MI T{$$=makeENode(); $$->code=$1->code+"-"+$3->code;}
	| T{$$=makeENode(); $$->code=$1->code;};

T : T MUL F{$$=makeENode(); $$->code=$1->code+"*"+$3->code;}
	| T DIV F{$$=makeENode(); $$->code=$1->code+"/"+$3->code;}
	| F{$$ = makeENode(); $$->code = $1->code;};

F : OP E CL{$$=makeENode(); $$->code = $2->code;}
	| ID{$$=makeENode(); $$->code = $1;};

%%

void yyerror(char* s)
{
	cout<<s<<endl;
}
int yywrap(){	return 1;	}
int main()
{
	yyparse();
}
