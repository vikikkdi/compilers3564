lex syntax.l
yacc -d syntax.y -o syntax.cc
gcc -c lex.yy.c -o lex.yy.o
g++ lex.yy.o syntax.cc
./a.out < inp.txt