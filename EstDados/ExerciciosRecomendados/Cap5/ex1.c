//$ Implemente uma função iterativa para calcular o máximo divisor comum de dois números inteiros positivos, MDC(x,y), usando o algoritmo de Euclides.

#include <stdio.h>

int calcMdc(int x, int y)
{
    int r;

    r = x % y;

    if (r == 0)
    {
        return y;
    }

    return calcMdc(y, r);
}

int main(void)
{
    int x, y;

    printf("Insira X: ");
    scanf("%d", &x);

    printf("Insira Y: ");
    scanf("%d", &y);

    printf("O MDC entre %d e %d eh %d", x, y, calcMdc(x, y));

    return 0;
}
