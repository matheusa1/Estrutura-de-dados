#include <stdio.h>
#include <stdlib.h>

float calc(float x, float y, float z);

int main(int argc, char const *argv[]){
    float n1, n2, n3, result;

    //entrada
    n1 = atof(argv[1]);
    n2 = atof(argv[2]);
    n3 = atof(argv[3]);

    //processamento
    result = calc(n1, n2, n3);

    //saida
    printf("\nResultado: %.2f\n", result);

    return 0;
}

float calc(float x, float y, float z){
    return (x + y + z) / 3;
}