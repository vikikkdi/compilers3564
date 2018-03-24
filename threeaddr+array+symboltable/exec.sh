lex three.l
bison -d three.y
g++ lex.yy.c three.tab.c -ll
./a.out < inp.txt
