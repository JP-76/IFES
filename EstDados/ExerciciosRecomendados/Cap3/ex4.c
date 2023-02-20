//$ Escreva um programa que converta coordenadas polares (raio r e ângulo a) em coordenadas cartesianas (abscissa x e ordenada y)

#include <stdio.h>
#include <math.h>

int main(void) {

    float r, a, x, y;

    printf("Insira o angulo a: ");
    scanf("%f", &a);

    printf("Insira o raio r: ");
    scanf("%f", &r);

    x = r * cos(a);
    y = r * sin(a);

    printf("Essas coordenadas polares correspondem ao ponto (%.2f, %.2f) no plano cartesiano.\n", x, y);


    return 0;
}
