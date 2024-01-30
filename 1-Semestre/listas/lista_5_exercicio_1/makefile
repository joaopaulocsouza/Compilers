# Nome do executável a ser gerado
TARGET = l5e1

# Compilador a ser usado
CC = gcc

# Opções do compilador
CFLAGS = -Wall -I.

# Arquivos-fonte
SRCS = main.c

# Objetos gerados a partir dos arquivos-fonte
OBJS = $(SRCS:.c=.o)

# Regra para a construção do executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regras para a construção dos objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos temporários
clean:
	rm -f $(OBJS) $(TARGET)
