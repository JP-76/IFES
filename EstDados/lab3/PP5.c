/*
@   O comprimento de um polígono regular inscrito numa circunferência de raio 𝑅 e
@    comprimento 𝐿𝑐 = 2π𝑅 pode ser calculado por:
@    
@    𝐿𝑝 = 2𝑅𝑛∙𝑠𝑒𝑛(𝜋/𝑛)
@
@    À medida que se aumenta o número de lados do polígono, seu comprimento se aproxima do
@    comprimento da circunferência circunscrita. Faça um programa que leia 𝑅, e mostre uma
@    tabela relacionando 𝑛 com o resíduo 𝐿c - 𝐿p para 𝑛 = 1, 2, 3, …, 𝑁𝑚𝑎𝑥, sendo 𝑁𝑚𝑎𝑥 valor
@    lido. Seu programa também deve informar para qual valor de 𝑛 o resíduo se torna inferior a
@    2%.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int nMax, r, doisprcnt;
    float ladoC, ladoP, residuo;

    printf("Insira o numero de lados do poligono inscrito: ");
    scanf("%d", &nMax);

    printf("Insira o raio da circunferencia: ");
    scanf("%d", &r);

    ladoC = 2 * 3.14 * r;
    doisprcnt = 0;

    printf("---------------------------------\n");

    for (int n = 1; n <= nMax; n++)
    {
        ladoP = 2 * r * n * sin(3.14 / n);
        residuo = ladoC - ladoP;
        if (residuo < 2 && doisprcnt == 0)
            doisprcnt = n;
        printf("| Para n = %d - residuo = %.2f\t|\n", n, residuo);

        printf("---------------------------------\n");
    }

    if (doisprcnt != 0)
        printf("=> A partir de %d lados, o residuo e menor que 2%%\n", doisprcnt);
    else
        printf("=> O residuo nao e menor que 2%%");

    return 0;
}
