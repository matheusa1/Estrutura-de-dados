all:
	gcc -c pilha_contigua.c
	gcc main.c pilha_contigua.o -o main

run:
	./main < 01.in