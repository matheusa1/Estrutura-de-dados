#include "fila.h"
#include "pilha.h"
#include "string.h"

/**************************************
* DADOS
**************************************/
struct fila {
    Pilha* p1;
    Pilha* p2;    
    int qtde;
};
/**************************************
* Funções Auxiliares
**************************************/
bool fila_ehValida(Fila* f) { 
    return (f != NULL? true : false);
}
/**************************************
* Exercício
**************************************/
Fila* fila_criar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->p1 = pilha_criar();
    f->p2 = pilha_criar();
    f->qtde = 0;

    return f;
}

bool fila_inserir(Fila* f, TipoElemento elemento) {
    if(!fila_ehValida(f)) return false;

    pilha_empilhar(f->p1, elemento);
    f->qtde++;
    return true;
}

void fila_destruir(Fila** enderecoFila) {
    if(!fila_ehValida(*enderecoFila)) return;
    
    Fila* f = *enderecoFila;
    pilha_destruir(&f->p1);
    pilha_destruir(&f->p2);
    free(f);
    *enderecoFila = NULL;
}

bool fila_remover(Fila* f, TipoElemento* saida) { // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    
    TipoElemento aux;
    for(int i = 0; i < f->qtde; i++) {
        pilha_desempilhar(f->p1, &aux);
        pilha_empilhar(f->p2, aux);
    }

    pilha_desempilhar(f->p2, &*saida);
    f->qtde--;

    for(int i = 0; i < f->qtde; i++) {
        pilha_desempilhar(f->p2, &aux);
        pilha_empilhar(f->p1, aux);
    }

    return true;
} 
bool fila_primeiro(Fila* f, TipoElemento* saida) { // estratégia do scanf
    if(!fila_ehValida(f)) return false;

    TipoElemento aux;
    for(int i = 0; i < f->qtde; i++) {
        pilha_desempilhar(f->p1, &aux);
        pilha_empilhar(f->p2, aux);
    }

    pilha_topo(f->p2, &*saida);

    for(int i = 0; i < f->qtde; i++) {
        pilha_desempilhar(f->p2, &aux);
        pilha_empilhar(f->p1, aux);
    }

    return true;
} 
bool fila_vazia(Fila* f) {
    return (f->qtde == 0? true: false);
}

bool fila_toString(Fila* f, char* saida) {
    if(!fila_ehValida(f)) return false;

    TipoElemento aux;
    for(int i = 0; i < f->qtde; i++) {
        pilha_desempilhar(f->p1, &aux);
        pilha_empilhar(f->p2, aux);
    }

    pilha_toString(f->p2, &*saida);

    for(int i = 0; i < f->qtde; i++) {
        pilha_desempilhar(f->p2, &aux);
        pilha_empilhar(f->p1, aux);
    }

    return true;
}