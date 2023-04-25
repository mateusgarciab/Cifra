CFLAGS = -std=c99 -Wall 
LDFLAGS = -lm

CC = gcc

# arquivos-objeto
	objects = mundo.o posicoes.o 
     
#mundo: mundo.o libconjunto.o  liblef.o libfila.o
#	$(CC) -o mundo mundo.o libconjunto.o  liblef.o libfila.o $(LDFLAGS)

testa: testa.o posicoes.o
	$(CC) -o testa testa.o posicoes.o $(LDFLAGS)

posicoes.o: posicoes.c
	$(CC) -c $(CFLAGS) posicoes.c


#mundo.o: mundo.c
#	$(CC) -c $(CFLAGS) mundo.c

testa.o: testa.c
	$(CC) -c $(CFLAGS) testa.c

clean:
	rm -f $(objects) mundo testa testa.o