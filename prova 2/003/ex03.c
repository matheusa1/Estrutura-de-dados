#include "lista_incidencia.h"

No* cria_no(int dado) {
    No* new = (No*) malloc (sizeof(No));
    new->dado = dado;
    new->prox = NULL;
    
    return new;
}

void destroi_no(No** endereco) {
    free(*endereco);
    *endereco = NULL;
}

bool lista_ehValida(Lista* l) { 
    return (l != NULL? true: false);
}

Lista* lista_criar(int nos) {
    Lista* l = (Lista*) malloc (sizeof(Lista));
    l->nos = nos;
    l->vetor = (No**) calloc (nos, sizeof(No*));
    for(int i = 0; i < nos; i++) l->vetor[i] = NULL;

    return l;
}

void lista_destruir(Lista** enderecoLista) {
    Lista* l = *enderecoLista;
    for(int i = 0; i < l->nos; i++) {
        for(int j = 0; j < l->nos; j++) {
            lista_removerCaminho(l, i, j);
        }
    }
    free(l->vetor);
    free(*enderecoLista);
    *enderecoLista = NULL;
}

bool lista_temCaminho(Lista* l, int a, int b) {
    if(!lista_ehValida(l)) return false;
    if(a < 0 || a >= l->nos) return false;
    if(b < 0 || b >= l->nos) return false;
    if(a == b) return false;

    No* aux = l->vetor[a];

    while(aux != NULL) {
        if(aux->dado == b) return true;
        else aux = aux->prox;
    }

    return false;
}

bool lista_inserirCaminho(Lista* l, int a, int b) {
    if(!lista_ehValida(l)) return false;
    if(a < 0 || a >= l->nos) return false;
    if(b < 0 || b >= l->nos) return false;
    if(a == b) return false;

    No* newA = cria_no(b);
    No* newB = cria_no(a);

    No* aux = l->vetor[a];
    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = newA;

    aux = l->vetor[b];
    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = newB;

    return true;
}

bool lista_removerCaminho(Lista* l, int a, int b) {
    if(!lista_ehValida(l)) return false;
    if(a < 0 || a >= l->nos) return false;
    if(b < 0 || b >= l->nos) return false;
    if(a == b) return false;
    if(!lista_temCaminho(l, a, b)) return false;

    No* aux = l->vetor[a];
    if(l->vetor[a]->dado == b) {
        l->vetor[a] = l->vetor[a]->prox;
        destroi_no(&aux);
    } else {
        while(aux != NULL) {
            if(aux->prox->dado == b) {
                No* removido = aux->prox;
                if(removido->prox == NULL) aux->prox = NULL;
                else aux->prox = removido->prox;
                destroi_no(&removido);
                break;
            } else aux = aux->prox;
        }
    }
    
    aux = l->vetor[b];
    if(l->vetor[b]->dado == a) {
        l->vetor[b] = l->vetor[b]->prox;
        destroi_no(&aux);
    } else {
        while(aux != NULL) {
            if(aux->prox->dado == a) {
                No* removido = aux->prox;
                if(removido->prox == NULL) aux->prox = NULL;
                else aux->prox = removido->prox;
                destroi_no(&removido);
                break;
            } else aux = aux->prox;
        }
    }

    return true;
}

void lista_toString(Lista* l, char* saida){
    saida[0] = '\0';
    char string[100];

    for(int i=0; i < l->nos; i++){
        sprintf(string, "[%d] ", i);
        strcat(saida, string);

        for(int j=0; j < l->nos; j++){
            if (lista_temCaminho(l, i, j)){
                sprintf(string, "%d ", j);
                strcat(saida, string);
            }
        }
        strcat(saida, "\n");        
    }
}