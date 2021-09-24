#include <stdio.h>

float calc(float x, float y, float z);

int main() {
    float n1, n2, n3, result;

    //entrada
    n1 = 6;
    n2 = 6;
    n3 = 6;

    //processamento
    result = calc(n1, n2, n3);

    //saida
    printf("\nResultado: %.2f\n", result);

    return 0;
}

float calc(float x, float y, float z){
    return (x + y + z) / 3;
}