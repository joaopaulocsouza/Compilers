# Makefile para compilar analisador léxico e sintático

# Nome do analisador léxico (Flex)
LEX_FILE = dcmat.l

# Nome do analisador sintático (Bison)
YACC_FILE = dcmat.y

# Nome do arquivo de saída
OUTPUT_FILE = dcmat

# Nome do arquivo fonte C++
CPP_FILE = dcmat.cpp

# Nome do arquivo de header C++
HEADER_FILE = dcmat.hpp

AST_HEADER_FILE = ast.hpp

all: $(OUTPUT_FILE)

$(OUTPUT_FILE): lex.yy.c dcmat.tab.c $(CPP_FILE) $(AST_HEADER_FILE)
	g++ -o $(OUTPUT_FILE) lex.yy.c dcmat.tab.c $(CPP_FILE) -I. -lstdc++

lex.yy.c: $(LEX_FILE)
	flex $(LEX_FILE)

dcmat.tab.c: $(YACC_FILE)
	bison -d $(YACC_FILE)

clean:
	rm -f *.yy.c *.tab.c *.tab.h $(OUTPUT_FILE)
