//$ Escreva um programa C completo que capture os valores de s0, v0, a e t, fornecidos pelo usuário via teclado,
//$ e calcule e exiba os valores de s e v. Todos os valores tratados no programa devem ser números reais ( float ou double )

#include <stdio.h>

float pos(float s0, float v0, float t, float a) {
    return s0 + v0 * t + (a * t * t) / 2;
}

float vel(float v0, float a, float t) {
    return v0 + a * t;
}

int main(void)
{
    float s0, s, v0, v, a, t;

    printf("Entre com a velocidade inicial (em m/s): ");
    scanf("%f", &v0);

    printf("Entre com a posicao inicial (em m): ");
    scanf("%f", &s0);

    printf("Entre com a aceleracao (em m/s^2): ");
    scanf("%f", &a);

    printf("Entre com o tempo (em s): ");
    scanf("%f", &t);

    s = pos(s0, v0, t, a);

    v = vel(v0, a, t);

    printf("A posicao do objeto no tempo %.1fs e: %.2f\n", t, s);
    printf("A velocidade do objeto com aceleracao %.1fm/s^2 no tempo %.1fs e: %.2fm/s\n", a, t, v);

    return 0;
}
