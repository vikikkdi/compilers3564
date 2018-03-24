/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TYPE = 258,
     ID = 259,
     VAL = 260,
     AND = 261,
     OR = 262,
     NOT = 263,
     LT = 264,
     GT = 265,
     EQQ = 266,
     LTE = 267,
     GTE = 268,
     PL = 269,
     MI = 270,
     MUL = 271,
     DIV = 272,
     OP = 273,
     CL = 274,
     OCB = 275,
     CCB = 276,
     OSB = 277,
     CSB = 278,
     EQ = 279,
     COMMA = 280,
     SEMICOLON = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     TRUE = 285,
     FALSE = 286,
     NTE = 287
   };
#endif
/* Tokens.  */
#define TYPE 258
#define ID 259
#define VAL 260
#define AND 261
#define OR 262
#define NOT 263
#define LT 264
#define GT 265
#define EQQ 266
#define LTE 267
#define GTE 268
#define PL 269
#define MI 270
#define MUL 271
#define DIV 272
#define OP 273
#define CL 274
#define OCB 275
#define CCB 276
#define OSB 277
#define CSB 278
#define EQ 279
#define COMMA 280
#define SEMICOLON 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define TRUE 285
#define FALSE 286
#define NTE 287




/* Copy the first part of user declarations.  */
#line 1 "three.y"

	#include<bits/stdc++.h>
	using namespace std;
	int yylex();
	void yyerror(char *s);

	int tempC = 1;	int getTemp(){	return tempC++;	}
	int ins = 0;	int getIns(){	return ins++;	}
	string type="";
	int block=-1;
	int basicBlockCount = 0;

	typedef struct Node{
		int ins;
		string type, name, code;
		vector<string> index;
		vector<int> nextList;
		vector<int> trueList, falseList;
	}node;

	node* makeNode(){
		ostringstream s;
		s<<"t"<<getTemp();
		node* temp = new Node();
		temp->code = s.str();
		return temp;
	}

	node* makeNode2(string x){
		node *temp=new node();
		temp->code=x;
		temp->name=x;
		return temp;
	}

	typedef struct NodeDec{
		string type, value;
		vector<string> index;
	}nodedec;

	nodedec* makeNodeDec(){
		nodedec* temp = new NodeDec();
		return temp;
	}

	map<int, map<string, nodedec *> > symboltable;
	map<int, string> instructions;
	set<int> leaders;
	vector< pair<int,int> > leaderLineNo;
	vector< vector<int> > basicBlocks;

	void showBlock(){
		for(int i=0;i<=block;i++){
			for(map<string,nodedec*>::iterator it=symboltable[i].begin();it!=symboltable[i].end();it++){
				cout<<it->first<<" "<<it->second->value<<" "<<it->second->type<<" ";
				for(int k=0;k<it->second->index.size();k++){	cout<<it->second->index[k]<<" ";	}
				cout<<endl;
			}
		}
		symboltable.erase(symboltable.find(block));
		block--;
		cout<<endl<<endl<<endl;
	}

	void checkId(string name){
		for(map<string, nodedec*>::iterator it=symboltable[block].begin();it!=symboltable[block].end();it++){
			if(it->first==name){
				cout<<"Variable "<<name<<" already declared"<<endl;
				exit(0);
			}
		}
	}

	void checkDeclared(string name){
		for(int i=block;i>=0;i--){
			for(map<string,nodedec*>::iterator it=symboltable[i].begin();it!=symboltable[i].end();it++){
				if(it->first==name)	return;
			}
		}
		cout<<name<<" not declared"<<endl;
		exit(0);
	}

	string getType(string name){
		for(int i=block;i>=0;i--){
			for(map<string, nodedec*>::iterator it=symboltable[i].begin();it!=symboltable[i].end();it++){
				if(it->first==name){
					return it->second->type;
				}
			}
		}
		return "";
	}
	vector<string> getIndex(string name){
		for(int i=block;i>=0;i--){
			for(map<string, nodedec*>::iterator it=symboltable[i].begin();it!=symboltable[i].end();it++){
				if(it->first==name){
					return it->second->index;
				}
			}
		}
		vector<string> x;
		return x;
	}

	vector<int> mergeVectors(vector<int> a, vector<int> b){
		vector<int> res(a.begin(),a.end());
		for(int i=0;i<b.size();i++)	res.push_back(b[i]);
		return res;
	}

	void bp(vector<int> a,int num)
	{
		ostringstream ss;
		ss<<num;

		for(vector<int>::iterator it=a.begin();it!=a.end();it++){
			instructions[*it] = instructions[*it]+ss.str();
		}
	}

	bool findBlock(int val){
		for(int i=0;i<leaderLineNo.size();i++){
			if(leaderLineNo[i].second==val){
				return true;
			}
		}
		return false;
	}

	int findBlockNo(int val){
		for(int i=0;i<leaderLineNo.size();i++){
			if(leaderLineNo[i].second==val){
				return leaderLineNo[i].first;
			}
		}
		return -1;
	}

	int findLineNo(int val){
		for(int i=0;i<leaderLineNo.size();i++){
			if(leaderLineNo[i].first==val){
				return leaderLineNo[i].second;
			}
		}
		return -1;
	}

	bool cmp(pair<int,int> a, pair<int,int> b){
		if(a.second<b.second)	return true;
		return false;
	}

	void generate_leaders(){
		leaders.insert(0);
		for(map<int, string>::iterator it=instructions.begin();it!=instructions.end();it++){
			string ins = it->second;
			if((ins[0]=='i' && ins[1]=='f')||(ins[0]=='g'&&ins[1]=='o'&&ins[2]=='t'&&ins[3]=='o')){
				string s="";
				for(int x=ins.length()-1;x>=0;x--){
					if(ins[x]==' '){
						break;
					}
					s+=ins[x];
				}
				string val = "";
				for(int x = s.length()-1;x>=0;x--){
					val+=s[x];
				}
				istringstream ss(val);
				int x;
				ss>>x;
				if(!findBlock(it->first+1)){
					leaders.insert(it->first+1);
				}
				if(!findBlock(x)){
					leaders.insert(x);
				}
			}
		}
		for(map<int, string>::iterator it=instructions.begin();it!=instructions.end();it++){
			if(leaders.find(it->first)!=leaders.end()){
				leaderLineNo.push_back(make_pair(basicBlockCount,it->first));
				basicBlockCount++;
			}
		}
		cout<<"LEADERS :: "<<endl;
		for(int i=0;i<leaderLineNo.size();i++){
			cout<<"BLOCK NO :: "<<leaderLineNo[i].first<<"  STATEMENT NO :: "<<leaderLineNo[i].second<<endl;
		}
		cout<<endl;
	}

	void generate_basic_blocks(){
		basicBlocks.resize(basicBlockCount);
		for(int i=0;i<leaderLineNo.size()-1;i++){
			int bb = leaderLineNo[i].first;
			string st = instructions[leaderLineNo[i+1].second-1];
			if(st[0]=='g'&& st[1]=='o'&& st[2]=='t'&& st[3]=='o'){
				string s="";
				for(int x=st.length()-1;x>=0;x--){
					if(st[x]==' '){
						break;
					}
					s+=st[x];
				}
				string val = "";
				for(int x = s.length()-1;x>=0;x--){
					val+=s[x];
				}
				istringstream ss(val);
				int x;
				ss>>x;
				basicBlocks[bb].push_back(findBlockNo(x));
			}
			else if(st[0]=='i' && st[1]=='f'){
				basicBlocks[bb].push_back(bb+1);
				string s="";
				for(int x=st.length()-1;x>=0;x--){
					if(st[x]==' '){
						break;
					}
					s+=st[x];
				}
				string val = "";
				for(int x = s.length()-1;x>=0;x--){
					val+=s[x];
				}
				istringstream ss(val);
				int x;
				ss>>x;
				basicBlocks[bb].push_back(findBlockNo(x));	
			}
			else{
				basicBlocks[bb].push_back(bb+1);
			}
		}
		cout<<"BASIC BLOCKS :: "<<endl;
		for(int i=0;i<basicBlocks.size();i++){
			cout<<i<<" :: ";
			for(int j=0;j<basicBlocks[i].size();j++){
				cout<<basicBlocks[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	typedef struct dagNode{
		int instNo;
		bool isRes;
		string index;
		string name;
		struct dagNode* opr;
		vector<struct dagNode *> childList;
		vector<struct dagNode *> labelList;
	}dagnode;

	int cc=0;

	dagnode * makeDagNode(string name){
		dagnode * temp = new dagnode();
		temp->name = name;
		temp->opr=NULL;
		temp->index="#";
		temp->instNo = cc+1;
		temp->isRes = false;
		cc+=1;
		return temp;
	}

	vector<string> split(char delim, string st) {
		vector<string> temp;
		string t = "";
		for(int i=0;i<st.length();i++){
			if(st[i]==delim){
				temp.push_back(t);
				t="";
			}else{
				t+=st[i];
			}
		}
		temp.push_back(t);
		return temp;
		for(int i=0;i<temp.size();i++){
			cout<<temp[i]<<"\t";
		}cout<<endl;

	}

	map<string, dagnode *> dagMap;
	vector<dagnode *> opResMap;
		

	dagnode * searchOperator(string opr, string leftV, string rightV){
		dagnode * result = makeDagNode(opr);
		string val = leftV;
		while(dagMap.find(leftV)!=dagMap.end()){
			val = leftV;
			leftV += '_';
		}
		leftV = val;
		val = rightV;
		while(dagMap.find(rightV)!=dagMap.end()){
			val = rightV;
			rightV += '_';
		}
		rightV = val;
		dagnode * left;
		dagnode * right;
		if(dagMap.find(leftV)!=dagMap.end()){
			left = dagMap[leftV];
		}else{
			left = makeDagNode(leftV);
			dagMap[left->name] = left;
		}
		if(dagMap.find(rightV)!=dagMap.end()){
			right = dagMap[rightV];
		}else{
			right = makeDagNode(rightV);
			dagMap[right->name] = right;
		}
		for(int i=0;i<opResMap.size();i++){
			if(opResMap[i]->childList[0]==left && opResMap[i]->childList[1]==right && opResMap[i]->name==opr){
				return opResMap[i];
			}
		}
		result->childList.push_back(left);
		result->childList.push_back(right);
		opResMap.push_back(result);
		return result;
	}

	void dfs(dagnode * op){
		if(op->index=="#"){
			cout<<endl<<op->name<<" ";
		}else{
			cout<<endl<<op->name<<"["<<op->index<<"] ";
		}
		for(int i=0;i<op->labelList.size();i++){
			if(op->labelList[i]->index!="#"){
				cout<<op->labelList[i]->name<<"["<<op->labelList[i]->index<<"] ";
			}else{
				cout<<op->labelList[i]->name<<" ";
			}
		}cout<<endl;
		if(op->childList.size()==1){
			if(op->childList[0]->isRes){
				cout<<op->childList[0]->name;
				dfs(op->childList[0]->opr);
			}
			else{
				dfs(op->childList[0]);
			}
		}
		if(op->childList.size()==2){
			if(op->childList[0]->isRes){
				cout<<op->childList[0]->name;
				dfs(op->childList[0]->opr);
			}
			else{
				dfs(op->childList[0]);
			}
			if(op->childList[1]->isRes){
				cout<<op->childList[1]->name;
				dfs(op->childList[1]->opr);
			}
			else{
				dfs(op->childList[1]);
			}
		}
	}

	void create_dag(int blockNo){
		int val = findLineNo(blockNo);
		int nextVal = findLineNo(blockNo+1);
		if(nextVal==-1){
			nextVal = instructions.rbegin()->first+1;
		}
		vector<string> ins;
		for(int i=val;i<nextVal;i++){
			ins.push_back(instructions[i]);
		}
		for(int _=0;_<ins.size();_++){
		//	cout<<ins[_]<<endl;
			vector<string> sp = split(' ',ins[_]);
			bool flag = true;
			for(int i=0;i<sp.size();i++){
				if(sp[i].find('[')<sp[i].length()){
					flag=false;
					break;
				}
			}
			if(!flag){
				string res = sp[0];
				string leftV = sp[2];
				if(res.find('[')<res.length()){
					string res1 = "";
					string res2 = "";
					int i=0;
					while(res[i]!='['){	res1+=res[i]; 	i+=1;}
					i+=1;
					while(res[i]!=']'){	res2+=res[i];	i+=1;}
					while(dagMap.find(res1)!=dagMap.end())	res1+='_';
					string val=res2;
					while(dagMap.find(res2)!=dagMap.end()){	val=res2;	res2+='_';}
					dagnode * array;
					dagnode * index;
					dagnode * eq;
					array = makeDagNode(res1);	array->isRes = true;	dagMap[array->name] = array;
					if(dagMap.find(val)!=dagMap.end()){	index = dagMap[val];	}
					else{	index = makeDagNode(val);	dagMap[index->name] = index;	}
					val = leftV;
					while(dagMap.find(leftV)!=dagMap.end()){	val = leftV;	leftV+='_';	}
					if(dagMap.find(val)!=dagMap.end()){	eq = dagMap[val];	}
					else{	eq = makeDagNode(val);	dagMap[eq->name] = eq;	}
					array->index = index->name;
					if(eq->isRes){
						array->opr = eq->opr;
						array->opr->labelList.push_back(array);
					}
				}else{
					string res1 = "";
					string res2 = "";
					int i=0;
					while(leftV[i]!='['){	res1+=leftV[i];	i+=1;	}
					i+=1;
					while(leftV[i]!=']'){	res2+=leftV[i];	i+=1;	}
					string val = res1;
					while(dagMap.find(res1)!=dagMap.end()){	val=res1;	res1+='_';	}
					res1 = val;
					dagnode * array;
					dagnode * index;
					dagnode * left;
					
					val=res2;
					while(dagMap.find(res2)!=dagMap.end()){	val=res2;	res2+='_';}

					array = makeDagNode(res1);	dagMap[array->name]=array;	array->index=val;
					
					if(dagMap.find(val)!=dagMap.end()){	index = dagMap[val];	}
					else{	index = makeDagNode(val);	dagMap[index->name] = index;	}
					
					while(dagMap.find(res)!=dagMap.end())	res+='_';
					left = makeDagNode(res);	left->isRes=true;	dagMap[left->name] = left;
					left->opr = makeDagNode("=[]");
					left->opr->labelList.push_back(left);
					//opResMap.push_back(left->opr);
					left->opr->childList.push_back(array);
				}
				continue;
			}
			if(sp.size()==3 && flag){
				string rr = sp[2];
				string val = sp[2];
				while(dagMap.find(rr)!=dagMap.end()){
					val = rr;
					rr += '_';
				}
				rr = val;
				dagnode * res;
				if(dagMap.find(rr)!=dagMap.end()){
					res = dagMap[rr];
				}else{
					res = makeDagNode(rr);
					dagMap[res->name] = res;
				}
				rr = sp[0];
				while(dagMap.find(rr)!=dagMap.end())	rr+='_';
				dagnode * r = makeDagNode(rr);
				r->isRes = true;
				if(res->isRes){
					r->opr = res->opr;
					r->opr->labelList.push_back(r);
				}
				dagMap[r->name] = r;
				continue;
			}
			if(sp[0]!="if" && sp[0]!="goto" && flag){
				string opr = sp[3];
				string left = sp[2];
				string right = sp[4];
				dagnode * op = searchOperator(opr,left,right);
				string val = sp[0];
				while(dagMap.find(val)!=dagMap.end())	val+='_';
				dagnode * res = makeDagNode(val);
				res->isRes = true;
				res->opr = op;
				dagMap[res->name] = res;
				op->labelList.push_back(res);
			}
		}
		for(int i=0;i<opResMap.size();i++){
			dfs(opResMap[i]);
		}
		opResMap.clear();
		dagMap.clear();
	}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 504 "three.y"
{
	char * str;
	struct Node * nn;
	struct NodeDec * nd;
}
/* Line 193 of yacc.c.  */
#line 668 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 681 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    11,    13,    15,    17,    19,
      21,    25,    27,    28,    35,    46,    54,    55,    59,    64,
      71,    75,    81,    83,    85,    90,    91,    96,   101,   106,
     111,   113,   115,   119,   123,   125,   127,   131,   135,   137,
     139,   141,   143,   147,   150,   151,   152,   157,   162,   165,
     169,   173,   175,   177,   179,   181,   183,   185,   187
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    -1,    36,    20,    37,    21,
      -1,    41,    -1,    46,    -1,    38,    -1,    39,    -1,    40,
      -1,    37,    52,    35,    -1,    35,    -1,    -1,    27,    18,
      54,    19,    52,    35,    -1,    27,    18,    54,    19,    52,
      35,    28,    53,    52,    35,    -1,    29,    52,    18,    54,
      19,    52,    35,    -1,    -1,     3,    42,    43,    -1,     4,
      45,    25,    43,    -1,     4,    45,    24,    44,    25,    43,
      -1,     4,    45,    26,    -1,     4,    45,    24,    44,    26,
      -1,     4,    -1,     5,    -1,    22,     5,    23,    45,    -1,
      -1,    47,    24,    48,    26,    -1,     4,    24,    48,    26,
      -1,     4,    22,    49,    23,    -1,    47,    22,    49,    23,
      -1,    49,    -1,    47,    -1,    49,    14,    50,    -1,    49,
      15,    50,    -1,    50,    -1,    47,    -1,    50,    16,    51,
      -1,    50,    17,    51,    -1,    51,    -1,    47,    -1,     4,
      -1,     5,    -1,    18,    49,    19,    -1,    15,    51,    -1,
      -1,    -1,    54,     7,    52,    54,    -1,    54,     6,    52,
      54,    -1,     8,    54,    -1,    18,    54,    19,    -1,    49,
      55,    49,    -1,    30,    -1,    31,    -1,     9,    -1,    10,
      -1,    12,    -1,    13,    -1,    11,    -1,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   518,   518,   530,   530,   536,   537,   538,   539,   540,
     542,   547,   550,   552,   558,   566,   576,   576,   578,   586,
     594,   602,   611,   612,   614,   621,   623,   624,   630,   643,
     659,   661,   662,   663,   664,   666,   667,   668,   669,   671,
     672,   676,   679,   680,   682,   684,   686,   692,   698,   703,
     708,   715,   716,   718,   719,   720,   721,   722,   723
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ID", "VAL", "AND", "OR", "NOT",
  "LT", "GT", "EQQ", "LTE", "GTE", "PL", "MI", "MUL", "DIV", "OP", "CL",
  "OCB", "CCB", "OSB", "CSB", "EQ", "COMMA", "SEMICOLON", "IF", "ELSE",
  "WHILE", "TRUE", "FALSE", "NTE", "$accept", "start", "ST", "@1", "st",
  "I", "IE", "W", "D", "@2", "VARIABLES", "HMM", "ARR", "A", "L", "R", "E",
  "T", "F", "M", "N", "BOOLEAN", "RELOP", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    36,    35,    35,    35,    35,    35,    35,
      37,    37,    37,    38,    39,    40,    42,    41,    43,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      48,    49,    49,    49,    49,    50,    50,    50,    50,    51,
      51,    51,    51,    51,    52,    53,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     1,     1,     1,     1,     1,
       3,     1,     0,     6,    10,     7,     0,     3,     4,     6,
       3,     5,     1,     1,     4,     0,     4,     4,     4,     4,
       1,     1,     3,     3,     1,     1,     3,     3,     1,     1,
       1,     1,     3,     2,     0,     0,     4,     4,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    16,     0,     0,    44,     0,     2,     0,     7,     8,
       9,     5,     6,     0,     0,     0,     0,     0,     0,     1,
       3,     0,     0,    25,    17,    40,    41,     0,     0,    31,
       0,    34,    38,     0,    30,     0,     0,    51,    52,     0,
       0,     0,    11,    44,     0,     0,     0,     0,    39,    43,
       0,     0,     0,    28,     0,     0,    27,    48,     0,     0,
      53,    54,    57,    55,    56,    58,     0,    44,    44,    44,
       0,     4,     3,    29,    26,     0,     0,     0,    20,    42,
      35,    32,    33,    36,    37,    49,    50,     0,     0,     3,
      44,    10,    25,    22,    23,     0,    18,    47,    46,    13,
       3,    24,     0,    21,    45,    15,    19,    44,     3,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    43,     8,     9,    10,    11,    14,
      24,    95,    47,    12,    29,    33,    39,    31,    32,    18,
     107,    40,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int8 yypact[] =
{
      15,   -77,    19,   -13,   -77,     9,   -77,    -6,   -77,   -77,
     -77,   -77,   -77,    95,    17,    20,    20,    60,    29,   -77,
       7,    20,    20,    11,   -77,    28,   -77,    20,    20,    64,
      48,    85,   -77,    31,   106,    60,    60,   -77,   -77,   100,
      -4,    60,   -77,    45,    62,    43,    69,    80,    57,   -77,
      68,    20,    20,   -77,    20,    20,   -77,   116,    84,    39,
     -77,   -77,   -77,   -77,   -77,   -77,    20,   -77,   -77,   -77,
      42,   -77,    15,   -77,   -77,    65,   120,    17,   -77,   -77,
      57,    85,    85,   -77,   -77,   -77,   106,    60,    60,    15,
     -77,   -77,    11,   -77,   -77,   101,   -77,   116,   116,    79,
      15,   -77,    17,   -77,   -77,   -77,   -77,   -77,    15,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -16,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -76,   -77,    26,   -77,     0,   108,     1,    77,   -15,   -37,
     -77,   -28,   -77
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -36
static const yytype_int8 yytable[] =
{
      13,    96,    67,    68,    42,    17,    72,    57,    59,    19,
       1,     2,    49,    70,    20,    69,    30,    34,     1,     2,
      13,    23,    44,    34,    25,    26,   106,    48,   -12,    50,
      87,    88,    89,    46,     3,    27,     4,    58,    28,    83,
      84,    15,     3,    16,     4,    67,    68,    41,    67,    68,
      15,    80,    80,   100,    48,    48,    91,    56,    85,    97,
      98,    90,    51,    52,    25,    26,    71,    86,    35,    74,
     108,    53,    13,    99,    75,    27,    51,    52,    36,    21,
     -35,   -35,    51,    52,   105,    73,    21,    79,    92,    13,
      37,    38,   109,    60,    61,    62,    63,    64,    51,    52,
      13,    54,    55,    79,    76,    77,    78,   104,    13,    60,
      61,    62,    63,    64,    51,    52,    65,    21,   101,    22,
      51,    52,    67,    68,    93,    94,   102,   103,    81,    82,
      45,     0,    65
};

static const yytype_int8 yycheck[] =
{
       0,    77,     6,     7,    20,    18,    43,    35,    36,     0,
       3,     4,    27,    41,    20,    19,    15,    16,     3,     4,
      20,     4,    21,    22,     4,     5,   102,    27,    21,    28,
      67,    68,    69,    22,    27,    15,    29,    36,    18,    54,
      55,    22,    27,    24,    29,     6,     7,    18,     6,     7,
      22,    51,    52,    90,    54,    55,    72,    26,    19,    87,
      88,    19,    14,    15,     4,     5,    21,    66,     8,    26,
     107,    23,    72,    89,     5,    15,    14,    15,    18,    22,
      16,    17,    14,    15,   100,    23,    22,    19,    23,    89,
      30,    31,   108,     9,    10,    11,    12,    13,    14,    15,
     100,    16,    17,    19,    24,    25,    26,    28,   108,     9,
      10,    11,    12,    13,    14,    15,    32,    22,    92,    24,
      14,    15,     6,     7,     4,     5,    25,    26,    51,    52,
      22,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    27,    29,    34,    35,    36,    38,    39,
      40,    41,    46,    47,    42,    22,    24,    18,    52,     0,
      20,    22,    24,     4,    43,     4,     5,    15,    18,    47,
      49,    50,    51,    48,    49,     8,    18,    30,    31,    49,
      54,    18,    35,    37,    49,    48,    22,    45,    47,    51,
      49,    14,    15,    23,    16,    17,    26,    54,    49,    54,
       9,    10,    11,    12,    13,    32,    55,     6,     7,    19,
      54,    21,    52,    23,    26,     5,    24,    25,    26,    19,
      47,    50,    50,    51,    51,    19,    49,    52,    52,    52,
      19,    35,    23,     4,     5,    44,    43,    54,    54,    35,
      52,    45,    25,    26,    28,    35,    43,    53,    52,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 518 "three.y"
    {
			for(map<int, string>::iterator it=instructions.begin();it!=instructions.end();it++){
				cout<<it->first<<" "<<it->second<<endl;
			}
			generate_leaders();
			generate_basic_blocks();
			for(set<int>::iterator it=leaders.begin();it!=leaders.end();it++){
				cout<<"DAG FOR BLOCK "<<findBlockNo(*it)<<" :: "<<endl;
				create_dag(findBlockNo(*it));
			}
		}
    break;

  case 3:
#line 530 "three.y"
    {block++;}
    break;

  case 4:
#line 530 "three.y"
    {
			//showBlock();
			(yyval.nn)=new node();
			(yyval.nn)->nextList=(yyvsp[(3) - (4)].nn)->nextList;
			block--;
		}
    break;

  case 5:
#line 536 "three.y"
    {type="";(yyval.nn)=new node();(yyval.nn)->nextList=(yyvsp[(1) - (1)].nn)->nextList;}
    break;

  case 6:
#line 537 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->nextList=(yyvsp[(1) - (1)].nn)->nextList;}
    break;

  case 7:
#line 538 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->nextList=(yyvsp[(1) - (1)].nn)->nextList;}
    break;

  case 8:
#line 539 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->nextList=(yyvsp[(1) - (1)].nn)->nextList;}
    break;

  case 9:
#line 540 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->nextList=(yyvsp[(1) - (1)].nn)->nextList;}
    break;

  case 10:
#line 542 "three.y"
    {
			(yyval.nn)=new node();
			bp((yyvsp[(1) - (3)].nn)->nextList,(yyvsp[(2) - (3)].nn)->ins);
			(yyval.nn)->nextList=(yyvsp[(3) - (3)].nn)->nextList;
		}
    break;

  case 11:
#line 547 "three.y"
    {
			(yyval.nn)->nextList=(yyvsp[(1) - (1)].nn)->nextList;
		}
    break;

  case 12:
#line 550 "three.y"
    {}
    break;

  case 13:
#line 552 "three.y"
    {
		(yyval.nn)=new node();
		bp((yyvsp[(3) - (6)].nn)->trueList,(yyvsp[(5) - (6)].nn)->ins);
		(yyval.nn)->nextList=mergeVectors((yyvsp[(3) - (6)].nn)->falseList,(yyvsp[(6) - (6)].nn)->nextList);
	}
    break;

  case 14:
#line 558 "three.y"
    {
				(yyval.nn)=new node();
				bp((yyvsp[(3) - (10)].nn)->trueList,(yyvsp[(5) - (10)].nn)->ins);
				bp((yyvsp[(3) - (10)].nn)->falseList,(yyvsp[(9) - (10)].nn)->ins);
				(yyval.nn)->nextList=mergeVectors((yyvsp[(6) - (10)].nn)->nextList,(yyvsp[(8) - (10)].nn)->nextList);
				(yyval.nn)->nextList=mergeVectors((yyval.nn)->nextList,(yyvsp[(10) - (10)].nn)->nextList);
			}
    break;

  case 15:
#line 566 "three.y"
    {
				(yyval.nn)=new node();
				bp((yyvsp[(4) - (7)].nn)->trueList,(yyvsp[(6) - (7)].nn)->ins);
				bp((yyvsp[(7) - (7)].nn)->nextList,(yyvsp[(2) - (7)].nn)->ins);
				ostringstream ss;
				ss<<(yyvsp[(2) - (7)].nn)->ins;
				instructions[getIns()]="goto "+ss.str();
				(yyval.nn)->nextList=(yyvsp[(4) - (7)].nn)->falseList;
		}
    break;

  case 16:
#line 576 "three.y"
    {type=(yyvsp[(1) - (1)].str);}
    break;

  case 17:
#line 576 "three.y"
    {(yyval.nn)=makeNode();}
    break;

  case 18:
#line 578 "three.y"
    {
					checkId((yyvsp[(1) - (4)].str));
					(yyval.nd) = makeNodeDec();
					(yyval.nd)->type = type;
					(yyval.nd)->value="";
					(yyval.nd)->index = (yyvsp[(2) - (4)].nd)->index;
					symboltable[block][(yyvsp[(1) - (4)].str)]=(yyval.nd);
				}
    break;

  case 19:
#line 586 "three.y"
    {
					checkId((yyvsp[(1) - (6)].str));
					(yyval.nd) = makeNodeDec();
					(yyval.nd)->type = type;
					(yyval.nd)->value=(yyvsp[(4) - (6)].str);
					(yyval.nd)->index = (yyvsp[(2) - (6)].nd)->index;
					symboltable[block][(yyvsp[(1) - (6)].str)]=(yyval.nd);
				}
    break;

  case 20:
#line 594 "three.y"
    {
					checkId((yyvsp[(1) - (3)].str));
					(yyval.nd) = makeNodeDec();
					(yyval.nd)->type = type;
					(yyval.nd)->value="";
					(yyval.nd)->index = (yyvsp[(2) - (3)].nd)->index;
					symboltable[block][(yyvsp[(1) - (3)].str)]=(yyval.nd);
				}
    break;

  case 21:
#line 602 "three.y"
    {
					checkId((yyvsp[(1) - (5)].str));
					(yyval.nd) = makeNodeDec();
					(yyval.nd)->type = type;
					(yyval.nd)->value=(yyvsp[(4) - (5)].str);
					(yyval.nd)->index = (yyvsp[(2) - (5)].nd)->index;
					symboltable[block][(yyvsp[(1) - (5)].str)]=(yyval.nd);
				}
    break;

  case 22:
#line 611 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 23:
#line 612 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 24:
#line 614 "three.y"
    {
				(yyval.nd)=makeNodeDec();
				(yyval.nd)->index.push_back((yyvsp[(2) - (4)].str));
				for(int i=0;i<(yyvsp[(4) - (4)].nd)->index.size();i++)	{
					(yyval.nd)->index.push_back((yyvsp[(4) - (4)].nd)->index[i]);
				}
			}
    break;

  case 25:
#line 621 "three.y"
    {(yyval.nd)=makeNodeDec();}
    break;

  case 26:
#line 623 "three.y"
    {instructions[getIns()]=(yyvsp[(1) - (4)].nn)->name+"["+(yyvsp[(1) - (4)].nn)->code+"] = "+(yyvsp[(3) - (4)].nn)->code;}
    break;

  case 27:
#line 624 "three.y"
    {
			checkDeclared((yyvsp[(1) - (4)].str));
			instructions[getIns()]=(string)(yyvsp[(1) - (4)].str)+" = "+(yyvsp[(3) - (4)].nn)->code;
	  		(yyval.nn)=new Node();
		}
    break;

  case 28:
#line 630 "three.y"
    {
			(yyval.nn)=makeNode();
			(yyval.nn)->name=(yyvsp[(1) - (4)].str);
			checkDeclared((yyvsp[(1) - (4)].str));
			(yyval.nn)->type=getType((yyvsp[(1) - (4)].str));
			(yyval.nn)->index=getIndex((yyvsp[(1) - (4)].str));
			int w;
			if((yyval.nn)->type=="int" || (yyval.nn)->type=="float"){w=4;}else{w=1;}
			for(int i=1;i<(yyval.nn)->index.size();i++){	stringstream geek((yyval.nn)->index[i]); int x=0; geek>>x; w*=x;	}
			ostringstream ss;
			ss<<w;
			instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(3) - (4)].nn)->code+" * "+ss.str();
		}
    break;

  case 29:
#line 643 "three.y"
    {
			Node * myTemp=makeNode();
 			(yyval.nn)=makeNode();
 			(yyval.nn)->name=(yyvsp[(1) - (4)].nn)->name;
 			(yyval.nn)->type=(yyvsp[(1) - (4)].nn)->type;
 			(yyval.nn)->index=(yyvsp[(1) - (4)].nn)->index;
 			(yyval.nn)->index.erase((yyval.nn)->index.begin());
 			int w;
			if((yyval.nn)->type=="int" || (yyval.nn)->type=="float"){w=4;}else{w=1;}
			for(int i=1;i<(yyval.nn)->index.size();i++){	stringstream geek((yyval.nn)->index[i]); int x=0; geek>>x; w*=x;	}
			ostringstream ss;
			ss<<w;
 			instructions[getIns()]=myTemp->code + " = "+(yyvsp[(3) - (4)].nn)->code +" * "+ss.str();
 			instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (4)].nn)->code+ " + " + myTemp->code;
		}
    break;

  case 30:
#line 659 "three.y"
    {(yyval.nn)=(yyvsp[(1) - (1)].nn);}
    break;

  case 31:
#line 661 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (1)].nn)->name+"["+(yyvsp[(1) - (1)].nn)->code+"]";}
    break;

  case 32:
#line 662 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (3)].nn)->code+" + "+(yyvsp[(3) - (3)].nn)->code;}
    break;

  case 33:
#line 663 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (3)].nn)->code+" - "+(yyvsp[(3) - (3)].nn)->code;}
    break;

  case 34:
#line 664 "three.y"
    {(yyval.nn)=(yyvsp[(1) - (1)].nn);}
    break;

  case 35:
#line 666 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (1)].nn)->name+"["+(yyvsp[(1) - (1)].nn)->code+"]";}
    break;

  case 36:
#line 667 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (3)].nn)->code+" * "+(yyvsp[(3) - (3)].nn)->code;}
    break;

  case 37:
#line 668 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (3)].nn)->code+" / "+(yyvsp[(3) - (3)].nn)->code;}
    break;

  case 38:
#line 669 "three.y"
    {(yyval.nn)=(yyvsp[(1) - (1)].nn);}
    break;

  case 39:
#line 671 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = "+(yyvsp[(1) - (1)].nn)->name+"["+(yyvsp[(1) - (1)].nn)->code+"]";}
    break;

  case 40:
#line 672 "three.y"
    {
			checkDeclared((yyvsp[(1) - (1)].str));
			(yyval.nn)=makeNode2((yyvsp[(1) - (1)].str));
		}
    break;

  case 41:
#line 676 "three.y"
    {
			(yyval.nn)=makeNode2((yyvsp[(1) - (1)].str));
		}
    break;

  case 42:
#line 679 "three.y"
    {(yyval.nn)=(yyvsp[(2) - (3)].nn);}
    break;

  case 43:
#line 680 "three.y"
    {(yyval.nn)=makeNode();instructions[getIns()]=(yyval.nn)->code+" = - "+(yyvsp[(2) - (2)].nn)->code;}
    break;

  case 44:
#line 682 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->ins=ins;}
    break;

  case 45:
#line 684 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->nextList.push_back(getIns());instructions[(yyval.nn)->nextList.back()]="goto ";}
    break;

  case 46:
#line 686 "three.y"
    {
					(yyval.nn)=new node();
					bp((yyvsp[(1) - (4)].nn)->falseList,(yyvsp[(3) - (4)].nn)->ins);
					(yyval.nn)->trueList=mergeVectors((yyvsp[(1) - (4)].nn)->trueList,(yyvsp[(4) - (4)].nn)->trueList);
					(yyval.nn)->falseList=(yyvsp[(4) - (4)].nn)->falseList;
				}
    break;

  case 47:
#line 692 "three.y"
    {
					(yyval.nn)=new node();
	 				bp((yyvsp[(1) - (4)].nn)->trueList,(yyvsp[(3) - (4)].nn)->ins);
	 				(yyval.nn)->trueList=(yyvsp[(4) - (4)].nn)->trueList;
	 				(yyval.nn)->falseList=mergeVectors((yyvsp[(1) - (4)].nn)->falseList,(yyvsp[(4) - (4)].nn)->falseList);
				}
    break;

  case 48:
#line 698 "three.y"
    {
					(yyval.nn)=new node();
					(yyval.nn)->trueList=(yyvsp[(2) - (2)].nn)->falseList;
					(yyval.nn)->falseList=(yyvsp[(2) - (2)].nn)->trueList;
				}
    break;

  case 49:
#line 703 "three.y"
    {
					(yyval.nn)=new node();
					(yyval.nn)->trueList=(yyvsp[(2) - (3)].nn)->trueList;
					(yyval.nn)->falseList=(yyvsp[(2) - (3)].nn)->falseList;
				}
    break;

  case 50:
#line 708 "three.y"
    {
					(yyval.nn)=new node();
					(yyval.nn)->trueList.push_back(getIns());
					instructions[(yyval.nn)->trueList.back()]="if "+(yyvsp[(1) - (3)].nn)->code+" "+(yyvsp[(2) - (3)].str)+" "+(yyvsp[(3) - (3)].nn)->code+" goto ";
					(yyval.nn)->falseList.push_back(getIns());
					instructions[(yyval.nn)->falseList.back()]="goto ";
				}
    break;

  case 51:
#line 715 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->trueList.push_back(getIns());instructions[(yyval.nn)->trueList.back()]="goto ";}
    break;

  case 52:
#line 716 "three.y"
    {(yyval.nn)=new node();(yyval.nn)->falseList.push_back(getIns());instructions[(yyval.nn)->falseList.back()]="goto ";}
    break;

  case 53:
#line 718 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 54:
#line 719 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 55:
#line 720 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 56:
#line 721 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 57:
#line 722 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 58:
#line 723 "three.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;


/* Line 1267 of yacc.c.  */
#line 2385 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 725 "three.y"


void yyerror(char* s)
{
	cout<<s<<endl;
}
int yywrap(){	return 1;	}

int main()
{
	yyparse();
}
