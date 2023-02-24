/*
@    Desenvolva um programa que leia dois valores a e b (a ≤ b) e mostre o seguintes
@    resultados:
@        a. Todos os números em [a, b].
@        b. Todos os números ímpares em [a, b].
@        c. Todos os números ímpares em [a, b] múltiplos de 3.
@        d. A média dos elementos em [a, b].
*/

#include <stdio.h>

int main(void)
{
    int a, b, total;
    float avrg;

    total = 0;

    printf("Entre com dois valores A e B (A menor ou igual a B): ");
    scanf("%d %d", &a, &b);

    printf("Numeros inteiros entre %d e %d: ", a, b);
    for (int i = a; i <= b; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");

    printf("Numeros impares entre %d e %d: ", a, b);
    for (int i = a; i <= b; i++)
    {
        if (i % 2 != 0)
            printf("%d  ", i);
    }
    printf("\n");

    printf("Numeros impares e multiplos de 3 entre %d e %d: ", a, b);
    for (int i = a; i <= b; i++)
    {
        if ((i % 2 != 0) && (i % 3 == 0))
            printf("%d  ", i);
    }
    printf("\n");

    printf("Media dos numeros entre %d e %d: ", a, b);
    for (int i = a; i <= b; i++)
    {
        total += i;
    }
    avrg = (float)total / (b - a + 1);
    printf("%.2f\n", avrg);

    return 0;
}
