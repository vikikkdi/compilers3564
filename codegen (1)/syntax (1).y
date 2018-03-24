%{
	#include<bits/stdc++.h>
	using namespace std;
	int yylex();
	void yyerror(char *);

	typedef struct Node{
		struct Node *left, *right;
		int label, x;
		string reg;
		string temp;
		bool flag;
		char* val;
	}node;

	node * makeNode(char* val, node* left, node* right){
		node* s = new node();
		s->val = val;
		s->left = left;
		s->right = right;
		s->label = 0;
		s->x = 0;
		s->reg = "";
		s->temp = "";
		s->flag = false;
		return s;
	}

	node * start;
	int cc = 1;

	void iprint(node* a){
		if(a){
			iprint(a->left);
			iprint(a->right);
			if(!(a->left&&a->right)){
				a->label = 1;
			}else{
				if(a->left->label==a->right->label){
					a->label = a->left->label+1;
				}else{
					a->label = max(a->left->label,a->right->label);
				}
				a->x = cc;
				cc+=1;
			}
		}
	}

	void oprint(node  * a){
		if(a){
			oprint(a->left);
			oprint(a->right);
			printf("%s/%d ",a->val,a->label);
		}
	}

	string str(int val){
		ostringstream os;
		os<<val;
		return os.str();
	}

	void generate(node * a, int base){
		if(a){
			if(!a->left && !a->right){
				a->reg = "R"+str(base);
				cout<<"LD "<<a->reg<<" "<<a->val<<endl;
				generate(a->left,base);
				generate(a->right,base);
			}
			else if(a->left->label == a->right->label){
				generate(a->right,base+1);
				generate(a->left,base);
				cout<<a->val<<" "<<a->right->reg<<" "<<a->left->reg<<" "<<a->right->reg<<endl;
				a->reg = a->right->reg;
			}else{
				if(a->left->label > a->right->label){
					generate(a->left,base);
					generate(a->right,base);
					cout<<a->val<<" "<<a->left->reg<<" "<<a->left->reg<<" "<<a->right->reg<<endl;
					a->reg = a->left->reg;
				}else{
					generate(a->right,base);
					generate(a->left,base);
					cout<<a->val<<" "<<a->right->reg<<" "<<a->right->reg<<" "<<a->left->reg<<endl;
					a->reg = a->right->reg;
				}
			}
		}
	}

	void generate2(node * a, int base, int r){
		if(a){
			if(a->label>=r){
				base = 1;
				a->flag = true;
			}
			if(!a->left && !a->right){
				a->reg = "R"+str(base);
				cout<<"LD "<<a->reg<<" "<<a->val<<endl;
				generate2(a->left,base,r);
				generate2(a->right,base,r);
			}
			else if(a->left->label == a->right->label){
				generate2(a->right,base+1,r);
				generate2(a->left,base,r);
				string right, left;
				bool ff = false;
				if(a->left->flag){
					cout<<"LD "<<a->left->reg<<" "<<a->left->temp<<endl;
					ff = true;
					left = a->left->reg;
				}else{
					left = a->left->reg;
				}
				if(a->right->flag){
					if(ff){
						a->right->reg = "R"+str(r-1);
					}
					cout<<"LD "<<a->right->reg<<" "<<a->right->temp<<endl;
					right = a->right->reg;
				}else{
					right = a->right->reg;
				}
				cout<<a->val<<" "<<right<<" "<<left<<" "<<right<<endl;
				a->reg = a->right->reg;
				if(a->flag){
					a->temp = "t"+str(a->x);
					cout<<"ST "<<a->temp<<" "<<a->reg<<endl;
				}
			}else{
				if(a->left->label > a->right->label){
					generate2(a->left,base,r);
					generate2(a->right,base,r);
					string right, left;
					bool ff = false;
					if(a->left->flag){
						ff = true;
						cout<<"LD "<<a->left->reg<<" "<<a->left->temp<<endl;
						left = a->left->reg;
					}else{
						left = a->left->reg;
					}
					if(a->right->flag){
						if(ff){
							a->right->reg = "R"+str(r-1);
						}
						cout<<"LD "<<a->right->reg<<" "<<a->right->temp<<endl;
						right = a->right->reg;
					}else{
						right = a->right->reg;
					}
					cout<<a->val<<" "<<left<<" "<<right<<" "<<left<<endl;
					a->reg = left;
					if(a->flag){
						a->temp = "t"+str(a->x);
						cout<<"ST "<<a->temp<<" "<<a->reg<<endl;
					}
				}else{
					generate2(a->right,base,r);
					generate2(a->left,base,r);
					string right, left;
					bool ff = false;
					if(a->left->flag){
						ff = true;
						cout<<"LD "<<a->left->reg<<" "<<a->left->temp<<endl;
						left = a->left->reg;
					}else{
						left = a->left->reg;
					}
					if(a->right->flag){
						if(ff){
							a->right->reg = "R"+str(r-1);
						}
						cout<<"LD "<<a->right->reg<<" "<<a->right->temp<<endl;
						right = a->right->reg;
					}else{
						right = a->right->reg;
					}
					cout<<a->val<<" "<<right<<" "<<right<<" "<<left<<endl;
					a->reg = right;
					if(a->flag){
						a->temp = "t"+str(a->x);
						cout<<"ST "<<a->temp<<" "<<a->reg<<endl;
					}
				}
			}
		}
	}

	void generate3(node * a, int base, int r){
		if(a){
			if(!a->left && !a->right){
				a->reg = "R"+str(base);
				cout<<"LD "<<a->reg<<" "<<a->val<<endl;
				return ;
			}
			if(a->label <= r){
				if(a->left->label == a->right->label){
					int k=a->left->label;
					generate3(a->right,base+1, r);
					generate3(a->left,base, r);
					cout<<a->val<<" R"<<base+k<<" R"<<base+k-1<<" R"<<base+k<<endl;
				}else{
					node * b;
					node * s;
					if(a->left->label > a->right->label){
						b = a->left;
						s = a->right;
					}else{
						b = a->right;
						s = a->left;
					}
					generate3(b, base, r);
					generate3(s, base, r);
					int m=s->label;
					int k=b->label;
					if(a->left->label>a->right->label)
						cout<<a->val<<" R"<<base+k-1<<" R"<<base+k-1<<" R"<<base+m-1<<endl;
					else
						cout<<a->val<<" R"<<base+k-1<<" R"<<base+m-1<<" R"<<base+k-1<<endl;
				}
			}else{
				node * b;
				node * s;
				if(a->left->label > a->right->label){
					b = a->left;
					s = a->right;
				}else{
					b = a->right;
					s = a->left;
				}
				generate3(b,1,r);
				cout<<"ST t"<<a->label<<" R"<<r<<endl;
				if(s->label >=r){
					generate3(s,1,r);
				}else{
					generate3(s,base-s->label,r);
				}
				cout<<"LD R"<<r-1<<" t"<<a->label<<endl;
				if(b==a->right)
				{
					cout<<a->val<<" R"<<r<<" R"<<r<<" R"<<r-1<<endl;
				}
				else{
					cout<<a->val<<" R"<<r<<" R"<<r-1<<" R"<<r<<endl;
				}
			}
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
E1: E{
		iprint($1);
		oprint($1);
		printf("\nRequired number of register is %d\n",$1->label);
		int r=2;
		printf("The number of available registers is %d\n",r);
		generate3($1,1,r);
		printf("\n");
	};

E: E PL T{$$ = makeNode($2,$1,$3);}
	| E MIN T{$$ = makeNode($2,$1,$3);}
	|T{$$ = $1;};

T: T MUL F{$$ = makeNode($2,$1,$3);}
	| T DIV F{$$ = makeNode($2,$1,$3);}
	| F{$$ = $1;};

F:	OP E CL{$$ = $2;}
	| ID{$$ = makeNode($1,NULL,NULL);};
%%

void yyerror(char* s)
{
	cout<<s<<endl;
}
int yywrap(){	return 1;	}


int main(){	
	yyparse();
}
