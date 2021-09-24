#include "fila.h"

No* cria_no(TipoElemento dado) {
    No* aux = (No*) malloc(sizeof(No));
    aux->dado = dado;
    aux->prox = NULL;

    return aux;
}

Fila* fila_criar(int ordem) {
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->fim = NULL;
    f->inicio = NULL;
    f->qtde = 0;
    f->ordem = ordem;

    return f;
}
bool fila_inserir(Fila* f, TipoElemento elemento) {
    // if(!fila_ehValida(f)) return false;

    No* new = cria_no(elemento);

    if(f->qtde == 0) {
        f->inicio = new;
        f->fim = new;
    } else {
        No* aux = f->inicio;
        if(f->ordem == 1) {
            if(new->dado <= aux->dado) {
                new->prox = f->inicio;
                f->inicio = new;
            } else if(new->dado >= f->fim->dado){
                f->fim->prox = new;
                f->fim = new;
            } else {
                while(new->dado >= aux->prox->dado) aux = aux->prox;
                new->prox = aux->prox;
                aux->prox = new;
            }
        } else {
            if(new->dado >= aux->dado) {
                new->prox = f->inicio;
                f->inicio = new;
            } else if(new->dado <= f->fim->dado){
                f->fim->prox = new;
                f->fim = new;
            } else {
                while(new->dado <= aux->prox->dado) aux = aux->prox;
                new->prox = aux->prox;
                aux->prox = new;
            }
        }
    }

    f->qtde++;
    return true;
}