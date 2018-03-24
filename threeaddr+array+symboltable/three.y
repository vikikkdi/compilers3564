%{
	#include<bits/stdc++.h>
	using namespace std;
	int yylex();
	void yyerror(char *s);
	int block=-1, temp=1, id = 1;
	string type="";

	int getTemp(){	return temp++;	}

	typedef struct ENode{
		string code;
	}enode;

	struct ENode* makeENode(){
		struct ENode * temp = new ENode();
		return temp;
	}

	typedef struct NodeDec{
		string type, name, initialValue, code;
		vector<enode*> index;
	}nodedec;

	struct NodeDec * makeNodeDec(){
		struct NodeDec * temp = new NodeDec();
		return temp;
	}

	map<int, vector<nodedec> > symboltable;
	bool expression, first=true;

	void showBlock(){

		for(int i=0;i<=block;i++){
			for(vector<nodedec>::iterator it = symboltable[i].begin();it!=symboltable[i].end();it++){
				cout<<it->type<<" "<<it->name<<" "<<it->initialValue<<" index ::";
				for(int x=0;x<it->index.size();x++){	
					cout<<it->index[x]->code<<" ";
				}
				cout<<endl;
			}
		}
		cout<<endl<<endl;
		symboltable[block].resize(0);
		block--;
	}

	void assignType(string ty){
		for(int i=0;i<=block;i++){
			for(vector<nodedec>::iterator it = symboltable[i].begin();it!=symboltable[i].end();it++){
				if(it->type=="notAssigned"){
					it->type=ty;
				}
			}
		}
	}

	void checkIfArray(string ty){
		for(int i=0;i<=block;i++){
			for(vector<nodedec>::iterator it = symboltable[i].begin();it!=symboltable[i].end();it++){
				if(it->name==ty && it->index.size()>0){
					return ;
				}
			}
		}
		cout<<ty<<" is not an array"<<endl;
		exit(0);
	}

	void search(string name){
		for(vector<nodedec>::iterator it = symboltable[block].begin();it!=symboltable[block].end();it++){
			if(it->name==name){
				cout<<"Variable already declared!!"<<endl;
				exit(0);
			}
		}	
	}

	void variableCheck(string name){
		for(int i=0;i<=block;i++){
			for(vector<nodedec>::iterator it = symboltable[i].begin();it!=symboltable[i].end();it++){
				if(it->name==name){
					return ;
				}
			}
		}
		cout<<name<<" not declared"<<endl;
		exit(0);
	}

	string gen(string o1, string op, string o2){
		ostringstream ss;
		ss<<"t"<<getTemp();
		cout<<ss.str()<<" = "<<o1<<" "<<op<<" "<<o2<<";"<<endl;
		return ss.str();
	}
%}

%union{
	char * str;
	struct NodeDec* n;
	struct ENode * e;
}

%token ID VAL PL MI MUL DIV POW EQ OP CL OSB CSB AND OR NOT LT GT EQQ LTE GTE TYPE COMMA SEMICOLON OCB CCB
%type <str> ID VAL PL MI MUL DIV POW EQ OP CL OSB CSB AND OR NOT LT GT EQQ LTE GTE TYPE COMMA SEMICOLON OCB CCB Y TY
%type <n> d D LIST L L1
%type <e> E T F

%%
START : OCB{block++;} H START CCB{block--;} START
	| H START
	|;
H : d
	| {expression=true;}s{expression=false;};

d : D SEMICOLON;

D : TY L1 X Y{
			struct NodeDec no;
			no.name = $2->name;
			no.type = $1;
			no.initialValue = $4;
			no.index = $2->index;
			search(no.name);
			symboltable[block].push_back(no);
		}
	| TY LIST{assignType($1);};


TY : TYPE{$$=$1;};

LIST : LIST COMMA L1 X Y{
			struct NodeDec no;
			no.name = $3->name;
			no.type = "notAssigned";
			no.initialValue = $5;
			no.index = $3->index;
			search(no.name);
			symboltable[block].push_back(no);
		}
	| L1 X Y{
			struct NodeDec no;
			no.name = $1->name;
			no.type = "notAssigned";
			no.initialValue = $3;
			no.index = $1->index;
			search(no.name);
			symboltable[block].push_back(no);
		};

X : EQ
	|;

Y : ID{$$=$1;}
	| VAL{$$=$1}
	|{$$=""};


s : S SEMICOLON{first=true;id=1;};

S : L EQ E{
			cout<<$1->name<<"["<<$1->code<<"] = "<<$3->code<<endl;
		}
	| ID EQ E{
			cout<<$1<<" = "<<$3->code<<endl;
		};

L1 : ID{
			$$ = makeNodeDec();
			$$->name=$1;
			if(expression){
				variableCheck($1);
				$$->code = $1;
			}
		}
	| L{$$=$1;};

L : ID OSB E CSB{
			$$=makeNodeDec(); 
			$$->name = $1;
			$$->index.push_back($3); 
			string a=$1;
			if(expression){
				checkIfArray($1);
				string h="";
				for(int i=block;i>=0;i--){
					bool flag=false;
					for(vector<nodedec>::iterator it = symboltable[i].begin();it!=symboltable[i].end();it++){
						if(it->name==$1){
							for(int x=0;x<it->index.size()-id;x++){	
								h+=it->index[x]->code+"*";
							}
							flag=true;
							id++;
							break;
						}
					}
					if(flag)	break;
				}
				$$->code = gen($3->code,"*",h+"4");
				id=1;
			}
		}
	
	|L OSB E CSB{
			$$=makeNodeDec();
			$$->name = $1->name;
			$$->index.push_back($3); 
			for(int x=0;x<$1->index.size();x++){ 	
				$$->index.push_back($1->index[x]);	
			}
			if(expression){
				string temp;
				if(first){
					temp = gen($1->code,"+",$3->code);
					first=false;
				}else{string h="";
					for(int i=block;i>=0;i--){
						bool flag=false;
						for(vector<nodedec>::iterator it = symboltable[i].begin();it!=symboltable[i].end();it++){
							if(it->name==$1->name){
								for(int x=0;x<it->index.size()-id;x++){	
									h+=it->index[x]->code+"*";
								}
								flag=true;
								id++;
								break;
							}
						}
						if(flag)	break;
					}
					temp = gen($1->code,"*",$3->code);
				}
				$$->code = temp;
			}
		};

E : L{
			$$=makeENode(); 
			$$->code=gen($1->name,"[",$1->code+"]");
		}
	| E PL T{
			$$=makeENode(); 
			string temp=gen($1->code,"+",$3->code);
			if(first)	temp = gen(temp,"*","4");
			$$->code=temp;
		}
	| E MI T{
			$$=makeENode(); 
			string temp=gen($1->code,"-",$3->code);
			if(first)	temp = gen(temp,"*","4");
			$$->code=temp;

		}
	| T{
			$$=makeENode(); 
			$$->code=$1->code;
		};

T : L{
			$$=makeENode(); 
			$$->code=gen($1->name,"[",$1->code+"]");
		}
	| T MUL F{
			$$=makeENode(); 
			string temp=gen($1->code,"*",$3->code);
			if(first)	temp = gen(temp,"*","4");
			$$->code=temp;
		}
	| T DIV F{
			$$=makeENode(); 			
			string temp=gen($1->code,"/",$3->code);
			if(first)	temp = gen(temp,"*","4");
			$$->code=temp;
		}
	| F{
			$$ = makeENode(); 
			$$->code = $1->code;
		};

F : L{
			$$=makeENode(); 
			$$->code=gen($1->name,"[",$1->code+"]");
		}
	| OP E CL{
			$$=makeENode(); 
			$$->code = $2->code;
		}
	| ID{
			if(expression)
				variableCheck($1);
			$$=makeENode(); 
			$$->code = $1;
		}
	| VAL{
			if(expression)
				variableCheck($1);
			$$=makeENode(); 
			$$->code = $1;
		};


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