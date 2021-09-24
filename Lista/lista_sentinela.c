#include "lista.h"
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------
Especificação dos dados
-------------------------------------------------*/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *sentinela;
	int qtde;
};

/*------------------------------------------------
Implementação das funções
-------------------------------------------------*/
bool lista_ehValida(Lista* l) {
	return (l != NULL? true: false);
}

bool posicao_ehValida(Lista* l, int* pos) {
	if(*pos > l->qtde) return false;
	if(*pos < 0) *pos = l->qtde + *pos;
	if(*pos < 0) return false;
	return true;
}

No* cria_no(TipoElemento dado) {
	No* n = (No*) malloc (sizeof(No));

	n->ant = NULL;
	n->dado = dado;
	n->prox = NULL;

	return n;
}

void destroi_no(No** endereco) {
	No* n = *endereco;
	free(n);
	*endereco = NULL;
}

No* set_aux(Lista* l, int posicao) {
	No* aux;
	if(posicao < (l->qtde - 1) / 2) {
		aux = l->sentinela->prox;
		for(int i = 0; i < posicao; i++) aux = aux->prox;
	} else {
		aux = l->sentinela->ant;
		for(int i = l->qtde - 1; i > posicao; i--) aux = aux->ant;
	}
	return aux;
}

void insere_direita(No* referencia, No* no) {
	no->ant = referencia;
	no->prox = referencia->prox;

	no->ant->prox = no;
	no->prox->ant = no;
}

void insere_esquerda(No* referencia, No* no) {
	no->ant = referencia->ant;
	no->prox = referencia;

	no->ant->prox = no;
	no->prox->ant = no;
}

/*------------------------------------------------
Implementação das funções
-------------------------------------------------*/

Lista* lista_criar() {
	Lista* l = (Lista*) malloc (sizeof(Lista));

	l->sentinela = (No*) malloc (sizeof(No));
	l->sentinela->ant = l->sentinela;
	l->sentinela->prox = l->sentinela;
	l->qtde = 0;

	return l;
}

void lista_destruir(Lista** endereco) {
	if(!lista_ehValida(*endereco)) return;

	Lista* l = *endereco;
	if(l->qtde > 0) {
		TipoElemento a;
		for(int i = 0; i < l->qtde; i++) lista_removerPosicao(l, 0, &a);
	}
	free(l->sentinela);
	free(l);
	*endereco = NULL;
}

bool lista_anexar(Lista* l, TipoElemento elemento) {
	if(!lista_ehValida(l)) return false;
	
	No* new = cria_no(elemento);
	
	No* ultimo = l->sentinela->ant;
	insere_direita(ultimo, new);

	l->qtde++;
	return true;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao) {
	if(!lista_ehValida(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;

	No* new = cria_no(elemento);
	No* aux = set_aux(l, posicao);
	
	if(posicao == l->qtde) insere_direita(aux, new);
	else insere_esquerda(aux, new);

	l->qtde++;
	return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco) {
	if(!lista_ehValida(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;
	if(lista_vazia(l)) return false;
	if(posicao == l->qtde) return false;

	No* aux = set_aux(l, posicao);

	aux->ant->prox = aux->prox;
	aux->prox->ant = aux->ant;

	*endereco = aux->dado;
	destroi_no(&aux);

	l->qtde--;
	return true;
	
}

int lista_removerElemento(Lista* l, TipoElemento elemento) {
	if(!lista_ehValida(l)) return -1;
	if(lista_vazia(l)) return -1;

	No* aux = l->sentinela->prox;
	for(int i = 0; i < l->qtde; i++) {
		if(aux->dado == elemento) {
			TipoElemento a;
			lista_removerPosicao(l, i, &a);
			return i;
		}
		else aux = aux->prox;
	}

	return -1;
}

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento) {
	if(!lista_ehValida(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;
	if(lista_vazia(l)) return false;

	No* aux = set_aux(l, posicao);
	aux->dado = novoElemento;

	return true;
}

int lista_posicao(Lista* l, TipoElemento elemento) {
	if(!lista_ehValida(l)) return false;
	if(lista_vazia(l)) return false;

	No* aux = l->sentinela->prox;
	for(int i = 0; i < l->qtde - 1; i++) {
		if(aux->dado == elemento) return i;
		else aux = aux->prox;
	}

	return -1;
}

bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco) {
	if(!lista_ehValida(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;

	No* aux = set_aux(l, posicao);

	*endereco = aux->dado;

	return true; 
}	

int lista_tamanho(Lista* l) {
	return l->qtde;
}

bool lista_vazia(Lista* l) {
	if(!lista_ehValida(l)) return false;
	// return (l->qtde == 0? true: false);
	if(l->qtde == 0) return true;
	else return false;
}

bool lista_toString(Lista* l, char* str) {
	if(!lista_ehValida(l)) return false;
	
	No* aux = l->sentinela->prox;
    str[0] = '\0';
    strcat(str, "[");
    
    for (int i = 0; i < l->qtde; i++){
        char elemento[200];
        sprintf(elemento, "%d", aux->dado);
        strcat(str, elemento);
        if(i < l->qtde - 1) strcat(str, ",");
        aux = aux->prox;
    }

    strcat(str, "]");

	return true;
}