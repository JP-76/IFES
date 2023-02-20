/*
    @Faça um programa que receba dois números e informe qual é o maior.
*/

#include <stdio.h>

int main(void)
{
    float x, y;

    printf("Insira dois numeros: ");
    scanf("%f %f", &x, &y);

    if (x > y)
    {
        printf("%.2f e maior que %.2f", x, y);
    }
    else
    {
        printf("%.2f e maior que %.2f", y, x);
    }

    return 0;
}
