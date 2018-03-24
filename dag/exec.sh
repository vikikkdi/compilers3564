lex three.l
yacc -d three.y
g++ lex.yy.c y.tab.c -lfl