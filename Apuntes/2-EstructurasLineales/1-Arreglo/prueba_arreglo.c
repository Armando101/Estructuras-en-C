#include "arreglo.h"

#include <stdio.h>

int main(void)
{
    // Se reserva memoria para el arreglo
    struct arreglo * a = crearArreglo(20);

    for (int i = 0; i < tamArr(a); ++i) {
        putArreglo(a, i + 1, i);
    }

    printf("Los elementos en el arreglo son: \n");
    for (int i = 0; i < tamArr(a); ++i) {
        printf("Posición %d es: %d\n", i, checarPosArreglo(a, i));
    }

    // Cambiando el tamaño del arreglo a 10
    redimensionarArr(a, 10);

    printf("Se le quitan 10 elementos al arreglo, ahora contiene: \n");
    for (int i = 0; i < tamArr(a); ++i) {
        printf("Posición %d es: %d\n", i, checarPosArreglo(a, i));
    }

    // Como el arreglo fue reservado dinámicamente, su memoria se tiene
    // que liberar
    liberarArreglo(a);
}
