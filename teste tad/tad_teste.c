#include "tad_teste.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct teste {
    char* TestName;
    int total;
    int passaram;
    int falharam;
};

Teste* teste_criar(char* descricao) {
    Teste* t = (Teste*) malloc(sizeof(Teste));
    t->TestName = (char*) calloc(strlen(descricao) + 1, sizeof(char));
    strcpy(t->TestName, descricao);
    t->total = 0;
    t->passaram = 0;
    t->falharam = 0;
    return t;
}

void teste_verificar(Teste* t, int condicao, char *mensagem) {
    t->total++;
    if(condicao == 1) {
        printf("\n[OK] %s", mensagem);
        t->passaram++;
    }
    else {
        t->falharam++;
        printf("\nErro: %s", mensagem);
    }
}

void teste_relatorio(Teste* t) {
    printf("\n----------------------------------------------------");
    printf("\n%s",t->TestName);
    printf("\n----------------------------------------------------");
    printf("\nTotal    = %d", t->total);
    printf("\nPassaram = %d", t->passaram);
    printf("\nFalharam = %d", t->falharam);

}

void teste_desalocar(Teste** t) {
    free((*t)->TestName);
    free(*t);
    *t = NULL;
}