/*
    @Faça um programa para calcular as raízes de uma equação de 2º grau.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{

    float a, b, c, delta, x1, x2;

    printf("Entre com o valor de A: ");
    scanf("%f", &a);

    printf("Entre com o valor de B: ");
    scanf("%f", &b);

    printf("Entre com o valor de C: ");
    scanf("%f", &c);

    if (a != 0)
    {
        delta = pow(b, 2) - 4 * a * c;
        if (delta >= 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);

            printf("As raizes sao:\nX1 = %.2f\nX2 = %.2f", x1, x2);
        }
        else
        {
            printf("Nao existe solucao no conjunto dos numeros reais!");
        }
    }
    else
    {
        printf("Nao e equacao do 2o grau");
    }

    return 0;
}
