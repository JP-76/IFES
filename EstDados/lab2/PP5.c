/*
    @Faça um programa que receba três números e os imprima em ordem crescente.
*/

#include <stdio.h>

int main(void)
{

    float x, y, z, temp;

    printf("Insira tres numeros: ");
    scanf("%f %f %f", &x, &y, &z);

    if (x > y)
    {
        if (x > z)
        {
            printf("");
        }
        else
        {
            temp = x;
            x = z;
            z = temp;
        }
    }
    else if (y > z)
    {
        temp = x;
        x = y;
        y = temp;
    }
    else
    {
        temp = x;
        x = z;
        z = temp;
    }

    if (z > y)
    {
        temp = y;
        y = z;
        z = temp;
    }

    printf("%.2f < %.2f < %.2f", z, y, x);

    return 0;
}
