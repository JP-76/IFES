/*
    Elabore um programa C que converta o certo número de dias para anos.
*/

#include <stdio.h>

int main(void)
{
    int days;
    float years;

    // Pedindo o numero de dias a serem convertidos ao usuario
    printf("Insira o numero de dias: ");
    scanf("%d", &days);

    // Convertendo o numero de dias para anos
    years = days / 365;

    // IMprimindo a equivalencia entre dias e anos
    printf("%d dias sao equivalentes a %.2f anos", days, years);

    return 0;
}
