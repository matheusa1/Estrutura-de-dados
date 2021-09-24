#include "tad_vetor.h"

Vetor* lerVetor(){
    int tam;
    scanf("[%d] ", &tam);
    Vetor* v = vet_criar(tam);
    for (int i=0; i < tam; i++){
        int n;
        scanf("%d ", &n);
        vet_anexar(v, n);
    }
    return v;
}

void teste01(){

    // Leitura do primeiro vetor
    Vetor* v1 = lerVetor();
    // Leitura do segundo vetor
    Vetor* v2 = lerVetor();
    Vetor* v3 = vet_concatena(v1, v2);
    vet_imprimir(v3);
    
    vet_desalocar(&v1);
    vet_desalocar(&v2);
    vet_desalocar(&v3);
    scanf("\n");
    printf("\n");
}

void teste02(){
    Vetor* v1 = lerVetor();
    Vetor* v2 = lerVetor();
    Vetor* v3 = vet_intercala(v1, v2);
    vet_imprimir(v3);

    vet_desalocar(&v1);
    vet_desalocar(&v2);
    vet_desalocar(&v3);
    scanf("\n");
    printf("\n");
}


int main(){
    
    // teste01();
    // teste02();

    Vetor* v1 = vet_criar(4);
    vet_anexar(v1, 1);
    vet_anexar(v1, 2);
    vet_anexar(v1, 3);
    vet_anexar(v1, 4);

    Vetor* v2 = vet_criar(6);

    vet_anexar(v2, 5);
    vet_anexar(v2, 6);
    vet_anexar(v2, 7);
    vet_anexar(v2, 8);
    vet_anexar(v2, 9);
    vet_anexar(v2, 10);

    Vetor* alt1 = vet_criar(5);

    vet_anexar(alt1, 20);
    vet_anexar(alt1, 40);
    vet_anexar(alt1, 60);
    vet_anexar(alt1, 80);
    vet_anexar(alt1, 100);

    Vetor* alt2 = vet_criar(5);

    vet_anexar(alt2, 10);
    vet_anexar(alt2, 30);
    vet_anexar(alt2, 50);
    vet_anexar(alt2, 70);
    vet_anexar(alt2, 90);

    Vetor* v3 = vet_concatena(v1, v2);
    Vetor* v4 = vet_intercala(alt1, alt2);

    printf("Concatena: ");
    vet_imprimir(v3);
    printf("\nIntercala ");
    vet_imprimir(v4);

    vet_desalocar(&v1);
    vet_desalocar(&v2);
    vet_desalocar(&alt2);
    vet_desalocar(&alt1);
    vet_desalocar(&v3);
    vet_desalocar(&v4);

}