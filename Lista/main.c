#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "lista.h"

int main(){
    Lista* l = lista_criar();

    lista_anexar(l, 10);
    lista_anexar(l, 20);
    lista_anexar(l, 30);   
    char str[200];
    lista_toString(l, str);
    printf("%s, esperado: [10,20,30]\n", str);

    lista_inserir(l, 5, 0);  
    lista_toString(l, str);
    printf("%s, esperado: [5,10,20,30]\n", str);

    printf("Pos elem 20: %d, esperado: 2\n", lista_posicao(l, 20));

    printf("Tam: %d, esperado: 4\n", lista_tamanho(l));

    printf("Pos removido: %d, esperado: 3\n", lista_removerElemento(l, 30));
    lista_toString(l, str);
    printf("%s, esperado: [5,10,20]\n", str);

    lista_substituir(l, -2, 1);
    lista_toString(l, str);
    printf("%s, esperado: [5,1,20]\n", str);

    TipoElemento a;  
    lista_removerPosicao(l, 2, &a);   
    printf("Elem removido: %d, esperado: 20\n", a);
    lista_toString(l, str);
    printf("%s, esperado: [5,1]\n", str);

    TipoElemento b;
    lista_buscar(l, 0, &b); 
    printf("Elem na posicao 0: %d, esperado: 5\n", b);  


    lista_inserir(l, 15, 2);  
    lista_toString(l, str);  
    printf("%s, esperado: [5,1,15]\n", str);

    lista_destruir(&l);

    return 0;
}