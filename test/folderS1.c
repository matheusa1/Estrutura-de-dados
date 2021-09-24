#include <stdio.h>

float calc(float x, float y, float z);

int main() {
    float n1, n2, n3, result;

    //entrada
    FILE *arq_in = fopen("teste_in.txt","r");
    fscanf(arq_in, "%f %f %f", &n1, &n2, &n3);
    fclose(arq_in);

    //processamento
    result = calc(n1, n2, n3);

    //saida
    printf("\nResultado: %.2f\n", result);

    return 0;
}

float calc(float x, float y, float z){
    return (x + y + z) / 3;
}