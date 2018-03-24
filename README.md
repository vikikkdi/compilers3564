# compilers3564
* folder 22.12.17 -> if a given "if" statement doesnt have a corresponding "else", add an empty "else{}" statement.
* folder 29.12.17 -> convert the given "for" and "dowhile" loop to "while" loop such that its semantic meaning is maintained.
* folder boolean backpatching -> for a given boolean expression, create the true list, false list etc.
* folder codegen(1) and codegen -> given an arithmetic expression ,generate its corresponding assembly code for any value for required register and available number of registers.
* folder dag -> generates dag from given set of c statements for a basic block. it generates leaders and blocks and dag for each blocks.
* folder dag_opt -> it is an updated version of dag folder.
* folder dag_opt_all and dag_opt_all(1) -> it generates dag for a given block of statements and removes copy propagation, constant folding and common sub expression and generates optimized three address statements for that block.
* folder symbol table -> given a set of declaration statements, it generates its symbol table.
* folder syntax tree -> creates a syntax tree for an arithmetic expression.
* folder threeaddr+array+symboltree and threeaddr_all -> creates three address statements for any kind of c statements(inclusing array reference of any dimension).


How to execute :
  * Open a terminal
  * move into the corresponding folder
  * chmod 777 exec.sh #give all permissions for exec.sh file
  * ./exec.sh #for providing other inputs, change the last line of exec.sh as ./a.out < ($your filename.txt)
