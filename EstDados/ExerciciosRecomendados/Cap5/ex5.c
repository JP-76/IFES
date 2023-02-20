//$ Implemente um jogo de adivinhação. O computador “escolhe” (gera aleatoriamente) um número entre 1 e 1024, e o usuário tenta adivinhar o número escolhido.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int answer, num, tries;

    tries = 0;

    srand(time(NULL));
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
