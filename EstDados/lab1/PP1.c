/*
    Escreva um programa C com variáveis inteiras x e y que tem por objetivo exibir na tela a soma entre seus valores.
*/

#include <stdio.h>

int main(void)
{
    int x, y;

    // Pedindo a entrada dos dois numeros inteiros e armazenado-os em 'x' e 'y'
    printf("Insira dois numeros inteiros: ");
    scanf("%d %d", &x, &y);

    // Imprimindo a soma entre 'x' e 'y'
    printf("%d + %d = %d", x, y, x + y);

    return 0;
}
