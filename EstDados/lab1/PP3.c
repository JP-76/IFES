/*
    Escreva um programa que receba como entrada dois valores reais e mostre o resultado da soma, subtração e divisão entre eles. Cada resultado deve ser mostrado numa linha separada.
*/

#include <stdio.h>

int main(void)
{
    float x, y;

    // Entrada dos valores de X e Y
    printf("Entre com dois valores X e Y: ");
    scanf("%f %f", &x, &y);

    // Soma entre X e Y
    printf("%f + %f = %f\n", x, y, x + y);

    // Subtracao entre X e Y | Y e X
    printf("%f - %f = %f\n", x, y, x - y);
    printf("%f - %f = %f\n", y, x, y - x);

    // Divisao entre X e Y | Y e X
    printf("%f / %f = %f\n", x, y, x / y);
    printf("%f / %f = %f\n", y, x, y / x);

    return 0;
}
