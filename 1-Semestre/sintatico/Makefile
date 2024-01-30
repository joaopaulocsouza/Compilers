# Makefile para compilar analisador léxico e sintático

# Nome do analisador léxico (Flex)
LEX_FILE = lexico.l

# Nome do analisador sintático (Bison)
YACC_FILE = sintatico.y

# Nome do arquivo de saída
OUTPUT_FILE = sintatico

all: $(OUTPUT_FILE)

$(OUTPUT_FILE): lex.yy.c sintatico.tab.c 
	gcc -std=c99 -o $(OUTPUT_FILE) lex.yy.c sintatico.tab.c -I. -lfl

lex.yy.c: $(LEX_FILE)
	flex $(LEX_FILE)

sintatico.tab.c: $(YACC_FILE)
	bison -d $(YACC_FILE)

clean:
	rm -f lex.yy.c sintatico.tab.c sintatico.tab.h $(OUTPUT_FILE)
