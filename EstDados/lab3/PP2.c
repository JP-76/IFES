/*
@    Escreva um programa que calcula o fatorial de um número (n!).
*/

#include <stdio.h>

int main(void)
{
    int n;
    double fat;

    fat = 1;
    printf("Entre com um numero: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        fat *= i;
    }

    printf("%d! = %.0lf", n, fat);

    return 0;
}
