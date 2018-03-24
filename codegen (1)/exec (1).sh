lex syntax.l
yacc -d syntax.y
g++ lex.yy.c y.tab.c -lfl
./a.out < inp.txt