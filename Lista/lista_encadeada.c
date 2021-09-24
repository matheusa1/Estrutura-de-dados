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
	No *inicio;
	No *fim;
	int qtde;
};


/*------------------------------------------------
Funções Auxiliares
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
	No* new = (No*) malloc (sizeof(No));
	new->ant = NULL;
	new->dado = dado;
	new->prox = NULL;

	return new;
}

bool destroi_no(No** endereco) {
	if(*endereco == NULL) return false;

	free(*endereco);
	*endereco = NULL;

	return true;
}

No* set_aux(Lista* l, int posicao) {
	No* aux;
	if(posicao <= (l->qtde / 2)) {
		aux = l->inicio;
		for(int i = 0; i < posicao; i++) aux = aux->prox;
	} else {
		aux = l->fim;
		for(int i = l->qtde - 1; i > posicao; i--) aux = aux->ant;
	}
	return aux;
}

/*------------------------------------------------
Implementação das funções
-------------------------------------------------*/
Lista* lista_criar() {
	Lista* l = (Lista*) malloc (sizeof(Lista));
	l->fim = NULL;
	l->inicio = NULL;
	l->qtde = 0;

	return l;
}

void lista_destruir(Lista** endereco) {
	if(!lista_ehValida(*endereco)) return;
	
	Lista* l = *endereco;
	if(!lista_vazia(l)) {
		for(int i = 0; i < l->qtde; i++) {
			TipoElemento aux;
			lista_removerPosicao(l, 0, &aux);
		}
	}
	free(l);
	*endereco = NULL;
}

bool lista_anexar(Lista* l, TipoElemento elemento) {
	if(!lista_ehValida(l)) return false;

	No* new = cria_no(elemento);
	
	if(lista_vazia(l)) {
		l->fim = new;
		l->inicio = new;
		
		l->qtde++;
		return true;
	}

	new->ant = l->fim;
	l->fim->prox = new;
	l->fim = new;

	l->qtde++;
	
	return true;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao) {
	if(!lista_ehValida(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;

	No* new = cria_no(elemento);

	if(lista_vazia(l)) { // Lista Vazia
		l->fim = new;
		l->inicio = new;
	} else if(posicao == 0) {  // Na primeira posição
		new->prox = l->inicio;
		l->inicio->ant = new;
		l->inicio = new;
	} else if(posicao == l->qtde) { // Ultima posição
		l->fim->prox = new;
		new->ant = l->fim;
		l->fim = new;
	} else{
		No* aux = set_aux(l, posicao);

		new->ant = aux->ant;
		new->prox = aux;

		aux->ant->prox = new;
		aux->ant = new;
	}

	l->qtde++;

	return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco) {
	if(!lista_ehValida(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;
	if(lista_vazia(l)) return false;

	No* aux;
	if(l->qtde == 1) { //Lista com um elemento
		aux = l->inicio;

		l->fim = NULL;
		l->inicio = NULL;
		*endereco = aux->dado;
		destroi_no(&aux);
	} else if(posicao == 0) { //Remocão na posição inicial
		aux = l->inicio;

		aux->prox->ant = NULL;
		l->inicio = aux->prox;
		*endereco = aux->dado;		
		destroi_no(&aux);
	} else if(posicao == l->qtde - 1) { //Remoção na posição final
		aux = l->fim;

		aux->ant->prox = NULL;
		l->fim = aux->ant;
		*endereco = aux->dado;
		destroi_no(&aux);
	} else { //Remoção no meio;
		aux = set_aux(l, posicao);

		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		*endereco = aux->dado;
		destroi_no(&aux);
	}
	l->qtde--;

	return true;
}

int lista_removerElemento(Lista* l, TipoElemento elemento) {
	if(!lista_ehValida(l)) return -1;

	No* aux = l->inicio;
	for(int i = 0; i < l->qtde; i++) {
		if(aux->dado == elemento) {
			if(i == 0) {
				l->inicio = aux->prox;
				aux->prox->ant = aux->ant;
			} else if(i == l->qtde - 1) {
				l->fim = aux->ant;
				aux->ant->prox = aux->prox;
			} else {
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
			}
			destroi_no(&aux);
			l->qtde--;
			return i;
		} else aux = aux->prox;
	}
	
	return -1;
}

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento) {
	if(!lista_ehValida(l)) return false;
	if(lista_vazia(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;
	
	No* aux = set_aux(l, posicao);
	aux->dado = novoElemento;

	return true;
}

int lista_posicao(Lista* l, TipoElemento elemento) {
	if(!lista_ehValida(l)) return -1;
	if(lista_vazia(l)) return -1;

	No* aux = l->inicio;
	for(int i = 0; i < l->qtde; i++) {
		if(aux->dado == elemento) return i;
		else aux = aux->prox;
	}

	return -1;
}

bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco) {
	if(!lista_ehValida(l)) return false;
	if(!posicao_ehValida(l, &posicao)) return false;
	if(lista_vazia(l)) return false;

	No* aux = set_aux(l, posicao);

	*endereco = aux->dado;

	return true;
}

int lista_tamanho(Lista* l) {
	if(!lista_ehValida(l)) return -1;
	return l->qtde;
}

bool lista_vazia(Lista* l) {
	if(!lista_ehValida(l)) return false;
	if(l->qtde == 0) return true;
	else return false;
}

bool lista_toString(Lista* l, char* str) {
	if(!lista_ehValida(l)) return false;
	
	No* aux = l->inicio;
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