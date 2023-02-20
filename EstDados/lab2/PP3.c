/*
    @Faça um programa que leia as notas, a opção escolhida pelo usuário e calcule a média.
*/

#include <stdio.h>

int main(void)
{
    float grade1, grade2, grade3, avrg;
    char option;

    printf("Entre com sua primeira nota: ");
    scanf("%f", &grade1);

    printf("Entre com sua segunda nota: ");
    scanf("%f", &grade2);

    printf("Entre com sua terceira nota: ");
    scanf("%f", &grade3);

    printf("Escolha o tipo de media desejada ('a' - aritmetica /'p' - ponderada): ");
    scanf(" %c", &option);

    avrg = 0.0;

    if (option == 'a')
    {
        avrg = (grade1 + grade2 + grade3) / 3;
    }
    else if (option == 'p')
    {
        avrg = (grade1 * 0.3 + grade2 * 0.3 + grade3 * 0.4);
    }
    else
    {
        printf("Opcao invalida\n");
    }

if (option == 'a' || option == 'p')
{
    printf("Sua media e %.2f\n", avrg);
}

    return 0;
}
