LEX_FILE = lista_7_exercicio_2

OUTPUT = l7e2

CC = gcc


all: $(OUTPUT)
	./$(OUTPUT) < entrada.txt

$(OUTPUT): lex.yy.c
	$(CC) $(CFLAGS) -o $(OUTPUT) lex.yy.c

lex.yy.c: $(LEX_FILE).l
	flex $(LEX_FILE).l

clean:
	rm -f $(OUTPUT) lex.yy.c

