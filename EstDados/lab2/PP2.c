/*
    @Faça um programa que receba três números e informe qual é o maior
*/

#include <stdio.h>

int main(void)
{
    float x, y, z;

    printf("Insira tres numeros: ");
    scanf("%f %f %f", &x, &y, &z);

    if (x > y)
    {
        if (x > z)
        {
            printf("%.2f e maior que os outros numeros.\n", x);
        }
        else
        {
            printf("%.2f e maior que os outros numeros.\n", z);
        }
    }
    else if (y > z)
    {
        printf("%.2f e maior que os outros numeros.\n", y);
    }
    else
    {
        printf("%.2f e maior que os outros numeros.\n", z);
    }

    return 0;
}