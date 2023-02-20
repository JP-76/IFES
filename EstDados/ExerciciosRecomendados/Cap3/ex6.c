//$ Modifique o programa do jogo “par ou ímpar” apresentado para que, em vez de o usuário, o computador escolha, de forma aleatória, se quer par ou ímpar. O usuário apenas fornece seu número.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {

    int escolha; /* escolha do usuário : 0=par , 1=ímpar */
    int usuario; /* número fornecido pelo usuário */
    int computador; /* número gerado pelo computador */

    srand(time(NULL)); /* inicializa gerador */

    escolha = rand() % 2;

    printf("%d \n", escolha);


    if (escolha == 1)
        printf("Seu objetivo e ter um resultado impar.\n");
    else
        printf("Seu objetivo e ter um resultado par.\n");

    printf("Entre com seu numero: ");
    scanf("%d", &usuario);

    /* gera número do computador e exibe */ 

    computador = rand() % 10;

    printf(" Computador: %d\n", computador);

    /* testa se soma é par ou ímpar , com escolha do usuário */

    if ((( usuario + computador) % 2) == escolha)
        printf("Voce ganhou!\n");

    else
        printf("Eu ganhei!\n");

    return 0;
}