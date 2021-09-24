#include <stdio.h>

float calc(float x, float y, float z);

int main() {
    float n1, n2, n3, result;

    //Entrada
    printf("\nEntre com 3 notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    //Processamento
    result = calc(n1, n2, n3);

    //Saida
    printf("\nResultado: %.2f\n", result);
    
    return 0;
}

float calc(float x, float y, float z){
    return (x + y + z) / 3;
}