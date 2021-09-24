#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista_alocacao_dinamica.c"

#define MAX_LIMIT 100




void teste_ex01(){
    char nome[100];
    // scanf("%[^\n]s", nome);
    fgets(nome, MAX_LIMIT, stdin);
    // O fgets inclui na string o \n
    nome[strlen(nome)-2] = '\0'; 

    inverte_string(nome);
    printf("[01] %s\n", nome); 
}
void teste_ex02(){
    char nome[100];
    fgets(nome, MAX_LIMIT, stdin);
    // O fgets inclui na string o \n
    nome[strlen(nome)-2] = '\0'; 

    int qtde1 = qtde_vogais1(nome);
    int qtde2;
    qtde_vogais2(nome, &qtde2);
    printf("[02] %d %d\n", qtde1, qtde2); 
}

void teste_ex03(){
    char str[100];
    fgets(str, MAX_LIMIT, stdin);
    // O fgets inclui na string o \n
    str[strlen(str)-2] = '\0'; 

    char* copia = copia_string(str);
    // verifica se a copia e o original são iguais
    int iguais = strcmp(copia, str)==0;
    // altera o primeiro caracter da cópia e verifica se alterou o original
    copia[0] = '#';
    int diff = str[0] != copia[0];    
    printf("[03] %d %d\n", iguais, diff); 
    free(copia);
}

void teste_ex04(){
    int tam, valor;
    scanf("%d %d", &tam, &valor);
    int* v1 = cria_vetor1(tam, valor);
    int* v2;
    cria_vetor2(tam*2, valor+10, &v2);
    char str1[100], str2[100];
    
    bool deuCerto1 = true;
    bool deuCerto2 = true;
    for (int i=0; i < tam; i++){
        if(v1[i] != valor) deuCerto1 = false;
    }
    for (int i=0; i < tam*2; i++){
        if(v2[i] != valor+10) deuCerto2 = false;
    }
    printf("[04] %d %d\n", deuCerto1, deuCerto2);
    free(v1);
    free(v2);
}

void teste_ex05(){
    int tam;
    scanf("%d", &tam);

    int* v = cria_vetor1(tam, tam);
    int* copia1 = clone1(v, tam);
    int* copia2;
    bool resultado = clone2(v, tam, &copia2);
    
    bool deuCerto1 = true;
    bool deuCerto2 = true;
    for (int i=0; i < tam; i++){
        if(v[i] != copia1[i]) deuCerto1 = false;
        if(v[i] != copia2[i]) deuCerto2 = false;
    }

    printf("[05] %d %d\n", deuCerto1, deuCerto2 && resultado); 
    free(v);
    free(copia1);
    free(copia2);
}
void teste_ex08(){
    int linhas, colunas, valor;
    scanf("%d %d %d", &linhas, &colunas, &valor);

    int** m = cria_matriz(linhas, colunas, valor);

    bool deuCerto = true;
    for (int i=0; i < linhas; i++){
        for (int j=0; j < colunas; j++){
            if(m[i][j] != valor) deuCerto = false;
        }
    }
    

    printf("[08] %d\n", deuCerto);     
}



int main(){
    
    teste_ex01();
    teste_ex02();
    teste_ex03();
    teste_ex04();
    teste_ex05();
    teste_ex08();

    
    return 0;
}