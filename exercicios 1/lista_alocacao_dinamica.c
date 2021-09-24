#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Exercicio 01
void inverte_string(char* str);
//Exercicio 02
int qtde_vogais1(char* str);
void qtde_vogais2(char* str, int* saida);
//Exercicio 03
char* copia_string(char* str);
//Exercicio 04
int* cria_vetor1(int tam, int valor);
bool cria_vetor2(int tam, int valor, int** saida);
//Exercicio 05
int* clone1(int* v, int tam);
bool clone2(int* v, int tam, int** saida);
//Exercicio 06
int* aleatorio1(int tam);
bool aleatorio2(int tam, int** saida);
//Exercicio 07
int dobra_tamanho(int** v, int tam);
//Exercicio 08
int** cria_matriz(int linhas, int colunas, int valor);

/***********************************************
* FUNCOES AUXILIARES
************************************************/
void imprimir_vetor(int* v, int tam){
    printf("[");
    for (int i=0; i < tam; i++){
        printf("%d", v[i]);
        if(i<tam-1) printf(",");
    }
    printf("]");
}

void toString_vetor(int* v, int tam, char* saida){
    saida[0] = '\0';
    strcat(saida, "[");
    
    char elemento[20];
    for (int i=0; i < tam; i++){
        sprintf(elemento, "%d", v[i]);
        strcat(saida, elemento);
        if(i<tam-1) strcat(saida, ",");
    }
    strcat(saida, "]");
}

/***********************************************
* IMPLEMENTACAO
************************************************/

void inverte_string(char* str){
    int strlen = 1;
    for (int i = 0; str[i] != '\0'; i++) strlen++;

    char save[strlen];
    int cont = strlen - 2;
    for(int i = 0; str[i] != '\0'; i++) {
        save[cont] = str[i];
        cont--;
    }
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = save[i];
    }
}

int qtde_vogais1(char* str){
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U') cont++;
    }
    return cont;
}

void qtde_vogais2(char* str, int* saida) {
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U') cont++;
    }
    *saida = cont;
}

char* copia_string(char* str) {
    int strlen = 1;
    for (int i = 0; str[i] != '\0'; i++) strlen++;

    char* temp = (char*)calloc(strlen, sizeof(char));
    for(int i = 0; str[i] != '\0'; i++) {
        temp[i] = str[i];
    }

    return temp;
}

int* cria_vetor1(int tam, int valor) {
    int* v1 = (int*)calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++) {
        v1[i] = valor;
    }
    return v1;
}

bool cria_vetor2(int tam, int valor, int** saida){
    int* v1 = (int*)calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++) {
        v1[i] = valor;
    }
    *saida = v1;
    return true;
}

int* clone1(int* v, int tam) {
    int* v1 = (int*)calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++) {
        v1[i] = v[i];
    }

    return v1;
}

bool clone2(int* v, int tam, int** saida) {
    int* v1 = (int*)calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++) {
        v1[i] = v[i];
    }
    *saida = v1;
    return true;
}

int* aleatorio1(int tam){
    int* v1 = (int*)calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++) {
        v1[i] = rand();
    }
    return v1;
}

bool aleatorio2(int tam, int** saida){
    int* v1 = (int*)calloc(tam, sizeof(int));
    for(int i = 0; i < tam; i++) {
        v1[i] = rand();
    }
    *saida = v1;
    return true;
}

int dobra_tamanho(int** v, int tam) {
    int novoTamanho = 2 * tam;
    int* v2 = (int*)calloc(novoTamanho, sizeof(int));
    for(int i = 0; i < tam; i++) {
        v2[i] = v[0][i];
    }
    for(int i = tam; i < novoTamanho; i++) {
        v2[i] = 0;
    }
    free(*v);
    *v = v2;
    return novoTamanho; 
}

int** cria_matriz(int linhas, int colunas, int valor) {
    int** matrix;
    matrix = (int**)calloc(linhas, sizeof(int));
    for(int i = 0; i < linhas; i++) {
        matrix[i] = (int*)calloc(colunas, sizeof(int));
    }
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            matrix[i][j] = valor;
        }
    }
    return matrix;
}