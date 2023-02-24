/*
@   Desenvolva um programa que leia o número n, o primeiro termo a1 e a razão r de
@   uma Progressão Geométrica (PG). Seu programa deve calcular e imprimir o n-ésimo termo
@   da PG
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, a1, q;
    printf("Insira a posicao do termo a ser encontrado na PG: ");
    scanf("%d", &n);

    printf("Insira o primeiro termo da PG: ");
    scanf("%d", &a1);

    printf("Insira a razao da PG: ");
    scanf("%d", &q);

    printf("O %do termo da PG e %.2lf",n , a1 * pow(q, (n - 1)));

    return 0;
}
