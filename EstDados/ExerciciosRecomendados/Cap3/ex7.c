//$ Escreva um programa que implemente o jogo conhecido como pedra, papel, tesoura.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    int user, comp;

    printf("Escolha pedra(0), papel(1) ou tesoura(2): ");
    scanf("%d", &user);

    srand(time(NULL));

    comp = rand() % 3;

    printf("Sua escolha: %d\nMinha escolha: %d\n", user, comp);

    if ((comp == 0 && user == 2) || (comp == 1 && user == 0) || (comp == 2 && user == 1))
    {
        printf("Eu venci!\n");
    }
    else if ((user == 0 && comp == 2) || (user == 1 && comp == 0) || (user == 2 && comp == 1))
    {
        printf("Voce venceu!\n");
    }
    else
    {
        printf("Empate!\n");
    }

    return 0;
}
