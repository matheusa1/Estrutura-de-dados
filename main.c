#include<stdio.h>
#include<stdbool.h>
#include "pilha.h"


#define MAX_LIMIT 301

int avalia_expressao(char* str);

int main(){

    int tam;
    char expressao[MAX_LIMIT];
    scanf("%d\n", &tam);

    int x;

    for (int i=0; i < tam; i++){
        fgets(expressao, MAX_LIMIT, stdin);
        expressao[strlen(expressao)-1] = '\0';
        
        x = avalia_expressao(expressao);
        printf("%d\n", x);
    }

    return 0;
}

int avalia_expressao(char* str) {
    int op = 0;
    int close = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(') op++;
        if(str[i] == '}' || str[i] == ']' || str[i] == ')') close++;
    }
    if(close > op) return -3;
    // if(op > close) return -2;

    char op1;
    char op2;

    Pilha* p = pilha_criar();

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(') pilha_empilhar(p, str[i]);
        if(str[i] == '}' || str[i] == ']' || str[i] == ')') {
            op1 = str[i];
            pilha_desempilhar(p, &op2);

            if(op1 == '}') if(op2 != '{') return -1;
            if(op1 == ']') if(op2 != '[') return -1;
            if(op1 == ')') if(op2 != '(') return -1;
        }
    }

    if(pilha_vazia(p)) return 1;
    else return -2;    
}
