/*
@   Escreva um algoritmo que lê um valor n inteiro e positivo, e calcula e escreve o valor
@   de S para a equação abaixo:
@       S = 1 + 1/1! + 1/2! + 1/3! + ⋯ + 1/n!
*/

#include <stdio.h>

int main(void)
{
    int n;
    double fat, sum;

    sum = 1.0;
    fat = 1.0;

    printf("Entre com um numero: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        fat *= i;
        sum += 1 / fat;
    }

    printf("O somatorio e: %.4f", sum);

    return 0;
}
