#include <stdio.h>
#include <math.h>

void imprimirDato(int * dt) {
    printf("\t\t\t | %2d |\n", *dt);
}

void multiplicar5(int * dt) {
    *dt *= 5;
}

void dividir5(int * dt) {
    *dt /= 5;
}
