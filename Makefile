CFLAGS = -std=c99 -Wall -g
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = mundo.o posicoes.o testa.o listaCarac.o
     
#mundo: mundo.o libconjunto.o  liblef.o libfila.o
#	$(CC) -o mundo mundo.o libconjunto.o  liblef.o libfila.o $(LDFLAGS)

testa: testa.o posicoes.o listaCarac.o
	$(CC) -o testa testa.o posicoes.o listaCarac.o $(LDFLAGS)

posicoes.o: posicoes.c
	$(CC) -c $(CFLAGS) posicoes.c

listaCarac.o: listaCarac.c
	$(CC) -c $(CFLAGS) listaCarac.c

#mundo.o: mundo.c
#	$(CC) -c $(CFLAGS) mundo.c

testa.o: testa.c
	$(CC) -c $(CFLAGS) testa.c

clean:
	rm -f $(objects) 
	
purge: clean
	rm -f mundo testa 

run: testa
	valgrind --leak-check=full -s ./testa