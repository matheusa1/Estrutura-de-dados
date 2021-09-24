#include "fila.h"
#include <string.h>
/**************************************
* DADOS
**************************************/
typedef struct no{
    int dado;
    struct no* prox;
}No;

struct fila {
    No* inicio;
    No* fim;
    int qtde;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Fila* fila_criar() {
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;

    return f;
}

void fila_destruir(Fila** enderecoFila) {
    Fila* x = *enderecoFila;
    int a;
    No* aux = x->fim;
    for(int i = 0; i < x->qtde; i++) {
        free(aux);
        fila_remover(x, &a);
        aux = x->fim;
    }   
    free(x);
    x = NULL;
}  

bool fila_inserir(Fila* f, TipoElemento elemento) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;

    if(f->qtde == 0) {
        f->fim = novo;
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->qtde++;

    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida) {
    if(f->qtde == 0) return false;
    
    No* aux = f->inicio;
    f->inicio = f->inicio->prox;

    *saida = aux->dado;

    free(aux);
    aux = NULL;

    f->qtde--;

    return true;
}

bool fila_primeiro(Fila* f, TipoElemento* saida) {
    *saida = f->inicio->dado;
    
    return true;
}

bool fila_vazia(Fila* f) {
    if(f->qtde == 0) return true;
    return false;
}

void fila_toString(Fila* f, char* saida) {
    
    No* aux = f->inicio;
    saida[0] = '\0';
    strcat(saida, "[");
    
    for (int i = 0; i < f->qtde; i++){
        char elemento[200];
        sprintf(elemento, "%d", aux->dado);
        strcat(saida, elemento);
        if(i < f->qtde - 1) strcat(saida, ",");
        aux = aux->prox;
    }

    strcat(saida, "]");
}

