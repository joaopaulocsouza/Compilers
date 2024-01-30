CC = gcc
LEX = flex
LDFLAGS =

all: cstats
	./cstats arquivo.c arquivo2.c

cstats: cstats.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

cstats.c: cstats.l
	$(LEX) -o $@ $^

.PHONY: clean

clean:
	rm -f cstats cstats.c
