#include "tad_vetor.h"

/***********************************************
* PROVA
************************************************/

Vetor* vet_concatena(Vetor* v1, Vetor* v2){
    Vetor* new = (Vetor*) malloc (sizeof(Vetor));
    new->vet = (int*) calloc (v1->tam + v2->tam, sizeof(int));
    new->tam = v1->tam + v2->tam;
    new->qtd = v1->qtd + v2->qtd;

    if(v1->vet[0] == 0) {
        for(int i = 0; i < new->qtd; i++) new->vet[i] = v2->vet[i];
        return new;
    }
    if(v2->vet[0] == 0) {
        for(int i = 0; i < new->qtd; i++) new->vet[i] = v1->vet[i];
        return new;
    }

    int count = 0;
    for(int i = 0; i < new->qtd; i++) {
        if(i < v1->qtd) new->vet[i] = v1->vet[i];
        else {
            new->vet[i] = v2->vet[count];
            count++;
        }
    }

    return new;
}

Vetor* vet_intercala(Vetor* v1, Vetor* v2){
    Vetor* new = (Vetor*) malloc (sizeof(Vetor));
    new->vet = (int*) calloc (v1->tam + v2->tam, sizeof(int));
    new->tam = v1->tam + v2->tam;
    new->qtd = v1->qtd + v2->qtd;
    
    int posVet1 = 0;
    int posVet2 = 0;
    for(int i = 0; i < new->qtd; i++) {
        if(posVet1 >= v1->qtd){
            new->vet[i] = v2->vet[posVet2];
            posVet2++;
        }
        else {
            if(posVet2 >= v2->qtd){
                new->vet[i] = v1->vet[posVet1];
                posVet1++;
            }
            else {
                if(v1->vet[posVet1] < v2->vet[posVet2]) {
                    new->vet[i] = v1->vet[posVet1];
                    posVet1++;
                }
                else {
                    new->vet[i] = v2->vet[posVet2];
                    posVet2++;
                }
            }
        }
    }
    
    return new;
}