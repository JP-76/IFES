/*
    Escreva um programa que leia duas variáveis reais x e y, efetue a troca dos seus valores entre si e mostre na tela o novo valor de ambas as variáveis.
*/

#include <stdio.h>

int main(void)
{
    float x, y, temp;

    // Entrada dos valores de X e Y
    printf("Entre com dois valores X e Y: ");
    scanf("%f %f", &x, &y);

    // Exibindo os valores de X e Y
    printf("X = %.2f\tY = %.2f\n", x, y);

    // Trocando os valores de X e Y
    temp = x;
    x = y;
    y = temp;

    // Exibindo os valores atualizados de X e Y
    printf("X = %.2f\tY = %.2f\n", x, y);

    return 0;
}
