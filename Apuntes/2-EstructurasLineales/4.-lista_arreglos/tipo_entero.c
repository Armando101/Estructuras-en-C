#include <stdio.h>
#include <math.h>

void imprimirDato(int * dt)
{
    printf("%d_", *dt);
}

int compararDato(const int * a, const int * b) {
    return (*a > *b) ? 1 : (*b > *a) ? -1 : 0;
}

void multiplicar5(int * dt)
{
    *dt *= 5;
}

void dividir5(int * dt)
{
    *dt /= 5;
}
