# Makefile para compilar analisador léxico e sintático

# Nome do analisador léxico (Flex)
LEX_FILE = linearscan.l

# Nome do analisador sintático (Bison)
YACC_FILE = linearscan.y

# Nome do arquivo de saída
OUTPUT_FILE = linearscan

# # Nome do arquivo fonte C++
# CPP_FILE = ast.cpp

# # Nome do arquivo de header C++
HEADER_FILE = linearscan.hpp

# AST-CPP_FILE = ast.cpp

# AST_HEADER_FILE = ast.hpp

all: $(OUTPUT_FILE)

$(OUTPUT_FILE): lex.yy.c linearscan.tab.c $(HEADER_FILE)
	g++ -o $(OUTPUT_FILE) lex.yy.c linearscan.tab.c -I.

lex.yy.c: $(LEX_FILE)
	flex $(LEX_FILE)

linearscan.tab.c: $(YACC_FILE)
	bison -d $(YACC_FILE)

clean:
	rm -f *.yy.c *.tab.c *.tab.h $(OUTPUT_FILE)
