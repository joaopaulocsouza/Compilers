all:
	flex lexico.l
	bison -d sintatico.y
	gcc lex.yy.c sintatico.tab.c -o l14e1 -lm
