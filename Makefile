CFLAGS = -std=c99 -Wall -g
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = mundo.o posicoes.o beale.o listaCarac.o cript.o

beale: beale.o posicoes.o listaCarac.o cript.o
	$(CC) -o beale beale.o posicoes.o listaCarac.o cript.o $(LDFLAGS)

posicoes.o: posicoes.c
	$(CC) -c $(CFLAGS) posicoes.c

listaCarac.o: listaCarac.c
	$(CC) -c $(CFLAGS) listaCarac.c

cript.o: cript.c
	$(CC) -c $(CFLAGS) cript.c

beale.o: beale.c
	$(CC) -c $(CFLAGS) beale.c

clean:
	rm -f $(objects) 
	
purge: clean
	rm -f mundo beale 

run: beale
	valgrind --leak-check=full -s ./beale