all: investimentos

investimentos: main.c dados.o data.o atualizacao.o ordenacao.o
	gcc -o investimentos main.c dados.o data.o atualizacao.o ordenacao.o -lm

dados.o: dados.c estrutura.h dados.h
	gcc -o dados.o -c dados.c

data.o: data.c estrutura.h data.h
	gcc -o data.o -c data.c

atualizacao.o: atualizacao.c estrutura.h data.h atualizacao.h
	gcc -o atualizacao.o -c atualizacao.c

ordenacao.o: ordenacao.c estrutura.h ordenacao.h dados.h
	gcc -o ordenacao.o -c ordenacao.c

clean:
	rm -f *.o investimentos
