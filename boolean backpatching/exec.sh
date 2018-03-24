lex bool.l
bison -d bool.y
g++ lex.yy.c bool.tab.c -lfl
./a.out < inp.txt
