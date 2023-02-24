//$ Implemente um jogo de adivinhação com dois modos.
//$ No primeiro modo, o usuário pensa em um número entre 1 e 1024, e o computador tenta adivinhar o número pensado.
//$ No segundo modo, o computador “escolhe” (gera aleatoriamente) um número entre 1 e 1024, e o usuário tenta adivinhar o número escolhido.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int answer, num, tries, mode, max, min;

    min = 1;
    max = 1024;
    num = 0;
    tries = 0;
    srand(time(NULL));

    printf("Escolha o modo de jogo:\n");
    printf("0 - voce escolhe o numero e a maquina adivinha\n");
    printf("1 - a maquina escolhe o numero e voce adivinha\n");
    scanf("%d", &mode);

    //@ Modo 0 - Voce escolhe o numero e a maquina adivinha
    if (mode == 0)
    {
        printf("Pense em um numero entre 1 e 1024.\n");

        do
        {

            //@ Limita o numero minimo e maximo para 1 e 1024
            if (max > 1024)
                max = 1024;
            if (min < 1)
                min = 1;

            //@ Se o minimo for maior que o maximo, limita o minimo a tentativa anterior
            if (min > max)
                min = num;
            //@ Se o maximo for menor que o minimo, limita o maximo a tentativa anterior
            if (max < min)
                max = num;


            //@ Calcula o numero medio entre o minimo e o maximo (como se fosse busca binaria)
            num = (max + min) / 2;
            tries++;

            printf("O numero e %d?\n", num);
            printf("1 se o seu numero e maior, -1 se o seu numero e menor, 0 se o numero e igual\n");
            scanf("%d", &answer);

            if (num == min + 1 && answer == -1)
            {
                printf("O numero e %d!\n", min);
                answer = 0;
            }

            else if (answer == -1)
                max = num - 1;

            else if (num == max - 1 && answer == 1)
            {
                printf("O numero e %d!\n", max);
                answer = 0;
            }

            else if (answer == 1)
                min = num + 1;

            else
                printf("Resposta invalida!\n");

        } while (answer != 0);

        printf("A maquina acertou em %d tentativas!\n", tries);

        return 0;
    }

    //@ Modo 1 - A maquina escolhe o numero e voce adivinha
    else if (mode == 1)
    {
        num = (rand() % 1024) + 1;
        do
        {
            printf("Tente adivinhar o numero: ");
            scanf("%d", &answer);
            tries++;

            if (answer > num)
            {
                printf("-1\n");
            }
            else if (answer < num)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }

        } while (answer != num);

        printf("Voce acertou em %d tentativas!\n", tries);
        return 0;
    }

    //@ Modo invalido
    else
    {
        printf("Modo invalido!\n");
        return 1;
    }
}
