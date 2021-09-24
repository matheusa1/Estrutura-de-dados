#include "pilha.h"

typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

struct pilha{
	int qtde;
    No *topo;
};



/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar() {
    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->qtde = 0;
    p->topo = NULL;
    return p;
}

void pilha_destruir(Pilha** endereco) {
    Pilha* x = *endereco;
    No* aux = x->topo;
    TipoElemento a;
    while(aux->prox != NULL) {
        pilha_desempilhar(x, &a);
    }
    free(x->topo);
    free(x);
    x = NULL;
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento) {
    No* aux = (No*) malloc(sizeof(No));
    aux->dado = elemento;
    aux->prox = p->topo;
    p->topo = aux;

    p->qtde++;

    return true;    
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida) {
    No* aux = p->topo;

    p->topo = p->topo->prox;
    *saida = aux->dado;
    free(aux);
    aux = NULL;
    
    p->qtde--;

    return true;
}

bool pilha_topo(Pilha* p, TipoElemento* saida) {
    No* aux = p->topo;
    *saida = aux->dado;

    return true;
}

bool pilha_vazia(Pilha* p) {
    if(p->qtde == 0) return true;
    else return false;
}

void pilha_toString(Pilha* p, char* saida) {
    No* aux = p->topo;
    saida[0] = '\0';
    strcat(saida, "[");
    
    for (int i = 0; i < p->qtde; i++){
        char elemento[200];
        sprintf(elemento, "%d", aux->dado);
        strcat(saida, elemento);
        if(i < p->qtde - 1) strcat(saida, ",");
        aux = aux->prox;
    }

    strcat(saida, "]");
}